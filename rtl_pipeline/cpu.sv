`timescale 1ns/1ps
import cpu_package::*;
module cpu (
    input  logic        clk, rst_n,
    output logic [31:0] pcF,
    // I-MEM AXI4
    output logic [31:0] imem_araddr, output logic imem_arvalid, input logic imem_arready,
    output logic [7:0]  imem_arlen,  output logic [2:0] imem_arsize, output logic [1:0] imem_arburst,
    input  logic [31:0] imem_rdata,  input logic imem_rvalid, input logic imem_rlast, input logic [1:0] imem_rresp,
    output logic        imem_rready,
    // D-MEM AXI4
    output logic [31:0] m_awaddr, output logic m_awvalid, input logic m_awready,
    output logic [7:0]  m_awlen, output logic [2:0] m_awsize,
    output logic [31:0] m_wdata, output logic [3:0] m_wstrb, output logic m_wlast, output logic m_wvalid, input logic m_wready,
    input  logic m_bvalid, input logic [1:0] m_bresp, output logic m_bready,
    output logic [31:0] m_araddr, output logic m_arvalid, input logic m_arready,
    output logic [7:0]  m_arlen, output logic [2:0] m_arsize, output logic [1:0] m_arburst,
    input  logic [31:0] m_rdata, input logic m_rvalid, input logic m_rlast, input logic [1:0] m_rresp,
    output logic m_rready,
    // Debug
    output logic [31:0] dbg_wd,
    output logic [4:0]  dbg_rd,
    output logic        dbg_rw, dbg_fl
);
    logic [31:0] pcplus4F, pcD, pcplus4D, instrD;
    logic [31:0] pcD_out, pcplus4D_out, rd1D, rd2D, immedD;
    logic [4:0]  rs1D, rs2D, rdD;
    logic [3:0]  alu_controlD;
    logic        alu_srcD, reg_writeD, mem_writeD, branchD, jumpD;
    logic [1:0]  result_srcD;
    logic [2:0]  branch_typeD;
    logic [31:0] pcE, pcplus4E, rd1E, rd2E, immedE;
    logic [4:0]  rs1E, rs2E, rdE;
    logic [3:0]  alu_controlE;
    logic        alu_srcE, reg_writeE, mem_writeE, branchE, jumpE;
    logic [1:0]  result_srcE;
    logic [2:0]  branch_typeE;
    logic [31:0] alu_resultE, pc_targetE, writeDataE, immE_out;
    logic        pc_srcE;
    logic [4:0]  rdE_out;
    logic [31:0] pcplus4E_out;
    logic        mem_writeE_out, reg_writeE_out;
    logic [1:0]  result_srcE_out;
    logic [31:0] alu_resultM, writeDataM, pcplus4M, immM;
    logic [4:0]  rdM;
    logic        mem_writeM, reg_writeM;
    logic [1:0]  result_srcM;
    logic [31:0] alu_resultM_out, pcplus4M_out, immM_out, wdM;
    logic [4:0]  rdM_out;
    logic        reg_writeM_out;
    logic [1:0]  result_srcM_out;
    logic [31:0] alu_resultW, pcplus4W, immW;
    logic [4:0]  rdW;
    logic        reg_writeW;
    logic [1:0]  result_srcW;
    logic [31:0] wdW;
    logic [4:0]  rdW_out;
    logic        reg_writeW_out;
    logic [1:0]  forwardAE, forwardBE;
    logic [31:0] dmem_address, dmem_write_data;
    logic        dmem_write_enable;
    logic [3:0]  dmem_byte_enable;
    logic [31:0] cache_rdata;

    logic hazard_stallF, hazard_flushE, is_loadE, is_loadM;
    logic mem_stall, stallF, stallD, stallE, is_mem_access, imem_stall;
    logic back_stall;   // unified stall for the back end

    // Instruction word driven by the I-cache
    wire [31:0] instrF;

    assign is_loadE = (result_srcE == WRITEBACK_MEMORY);
    assign is_loadM = reg_writeM && (result_srcM == WRITEBACK_MEMORY);
    assign is_mem_access = (result_srcM == WRITEBACK_MEMORY) | mem_writeM;

    // Front-end stalls on hazards, D-cache, or I-cache
    assign stallF = hazard_stallF | mem_stall | imem_stall;
    assign stallD = hazard_stallF | mem_stall | imem_stall;
    assign stallE = hazard_stallF | mem_stall | imem_stall;
    // Back end stalls on D-cache OR I-cache (keeps EX/MEM/WB aligned during I-miss)
    assign back_stall = mem_stall | imem_stall;

    hazard_detect u_hz (.rs1D(rs1D), .rs2D(rs2D), .rdE(rdE), .reg_writeE(reg_writeE),
                        .is_loadE(is_loadE), .stallF(hazard_stallF), .flushE(hazard_flushE));

    // I-CACHE
    icache u_icache (
        .clk(clk), .rst_n(rst_n),
        .core_req(1'b1), .core_addr(pcF),
        .core_stall(imem_stall), .core_rdata(instrF), .core_rvalid(),
        .m_araddr(imem_araddr), .m_arvalid(imem_arvalid), .m_arready(imem_arready),
        .m_arlen(imem_arlen), .m_arsize(imem_arsize), .m_arburst(imem_arburst),
        .m_rdata(imem_rdata), .m_rvalid(imem_rvalid), .m_rlast(imem_rlast), .m_rresp(imem_rresp), .m_rready(imem_rready)
    );

    if_stage u_if (.clk(clk), .rst_n(rst_n), .stall(stallF), .flush(pc_srcE), .pc_targetE(pc_targetE),
                   .pcF(pcF), .pcplus4F(pcplus4F));
    if_id_reg u_if_id (.clk(clk), .rst_n(rst_n), .flush(pc_srcE), .stall(stallD),
                       .pcF(pcF), .pcplus4F(pcplus4F), .instrF(instrF),
                       .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD));
    id_stage u_id (.clk(clk), .rst_n(rst_n), .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD),
                   .reg_writeW(reg_writeW_out), .rdW(rdW_out), .wdW(wdW), .pcD_out(pcD_out), .pcplus4D_out(pcplus4D_out),
                   .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD), .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD),
                   .alu_controlD(alu_controlD), .alu_srcD(alu_srcD), .reg_writeD(reg_writeD), .mem_writeD(mem_writeD),
                   .result_srcD(result_srcD), .branchD(branchD), .jumpD(jumpD), .branch_typeD(branch_typeD));
    id_ex_reg u_id_ex (.clk(clk), .rst_n(rst_n), .flush(pc_srcE | hazard_flushE), .stall(stallE),
                       .pcD(pcD_out), .pcplus4D(pcplus4D_out), .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD),
                       .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD), .alu_controlD(alu_controlD), .alu_srcD(alu_srcD),
                       .reg_writeD(reg_writeD), .mem_writeD(mem_writeD), .result_srcD(result_srcD),
                       .branchD(branchD), .jumpD(jumpD), .branch_typeD(branch_typeD),
                       .pcE(pcE), .pcplus4E(pcplus4E), .rd1E(rd1E), .rd2E(rd2E), .rs1E(rs1E), .rs2E(rs2E),
                       .rdE(rdE), .immedE(immedE), .alu_controlE(alu_controlE), .alu_srcE(alu_srcE),
                       .reg_writeE(reg_writeE), .mem_writeE(mem_writeE), .result_srcE(result_srcE),
                       .branchE(branchE), .jumpE(jumpE), .branch_typeE(branch_typeE));
    ex_stage u_ex (.pcE(pcE), .rd1E(rd1E), .rd2E(rd2E), .immedE(immedE), .alu_controlE(alu_controlE),
                   .alu_srcE(alu_srcE), .branchE(branchE), .jumpE(jumpE), .branch_typeE(branch_typeE),
                   .wdM(wdM), .wdW(wdW), .forwardAE(forwardAE), .forwardBE(forwardBE), .rdE(rdE),
                   .pcplus4E(pcplus4E), .mem_writeE(mem_writeE), .reg_writeE(reg_writeE), .result_srcE(result_srcE),
                   .alu_resultE(alu_resultE), .pc_targetE(pc_targetE), .pc_srcE(pc_srcE), .writeDataE(writeDataE),
                   .rdE_out(rdE_out), .pcplus4E_out(pcplus4E_out), .mem_writeE_out(mem_writeE_out),
                   .reg_writeE_out(reg_writeE_out), .result_srcE_out(result_srcE_out), .immE_out(immE_out));
    ex_mem_reg u_ex_mem (.clk(clk), .rst_n(rst_n), .stall(back_stall),
                         .alu_resultE(alu_resultE), .writeDataE(writeDataE), .rdE(rdE_out), .pcplus4E(pcplus4E_out),
                         .mem_writeE(mem_writeE_out), .reg_writeE(reg_writeE_out), .result_srcE(result_srcE_out), .immE(immE_out),
                         .alu_resultM(alu_resultM), .writeDataM(writeDataM), .rdM(rdM), .pcplus4M(pcplus4M),
                         .mem_writeM(mem_writeM), .reg_writeM(reg_writeM), .result_srcM(result_srcM), .immM(immM));
    mem_stage u_mem (.alu_resultM(alu_resultM), .writeDataM(writeDataM), .mem_writeM(mem_writeM), .rdM(rdM),
                     .pcplus4M(pcplus4M), .reg_writeM(reg_writeM), .result_srcM(result_srcM), .immM(immM),
                     .dmem_address(dmem_address), .dmem_write_data(dmem_write_data),
                     .dmem_write_enable(dmem_write_enable), .dmem_byte_enable(dmem_byte_enable),
                     .alu_resultM_out(alu_resultM_out), .rdM_out(rdM_out), .pcplus4M_out(pcplus4M_out),
                     .reg_writeM_out(reg_writeM_out), .result_srcM_out(result_srcM_out), .immM_out(immM_out), .wdM(wdM));
    mem_wb_reg u_mem_wb (.clk(clk), .rst_n(rst_n), .stall(back_stall),
                         .alu_resultM(alu_resultM_out), .pcplus4M(pcplus4M_out), .immM(immM_out),
                         .rdM(rdM_out), .reg_writeM(reg_writeM_out), .result_srcM(result_srcM_out),
                         .alu_resultW(alu_resultW), .pcplus4W(pcplus4W), .immW(immW),
                         .rdW(rdW), .reg_writeW(reg_writeW), .result_srcW(result_srcW));

       dcache u_dcache (
        .clk(clk), .rst_n(rst_n),
        .core_req(is_mem_access), .core_write(mem_writeM),
        .core_addr(dmem_address), .core_wdata(dmem_write_data), .core_wstrb(dmem_byte_enable),
        .core_stall(mem_stall), .core_rdata(cache_rdata), .core_rvalid(),
        .m_araddr(m_araddr), .m_arvalid(m_arvalid), .m_arready(m_arready),
        .m_arlen(m_arlen), .m_arsize(m_arsize), .m_arburst(m_arburst),
        .m_rdata(m_rdata), .m_rvalid(m_rvalid), .m_rlast(m_rlast), .m_rresp(m_rresp), .m_rready(m_rready),
        .m_awaddr(m_awaddr), .m_awvalid(m_awvalid), .m_awready(m_awready),
        .m_wdata(m_wdata), .m_wstrb(m_wstrb), .m_wlast(m_wlast), .m_wvalid(m_wvalid), .m_wready(m_wready),
        .m_bvalid(m_bvalid), .m_bresp(m_bresp), .m_bready(m_bready)
    );

    wb_stage u_wb (.alu_resultW(alu_resultW), .read_dataW(cache_rdata),
                   .pcplus4W(pcplus4W), .immW(immW), .result_srcW(result_srcW), .rdW(rdW),
                   .reg_writeW(reg_writeW), .wdW(wdW), .rdW_out(rdW_out), .reg_writeW_out(reg_writeW_out));

    forward_unit u_fwd (.rs1E(rs1E), .rs2E(rs2E), .rdM(rdM), .rdW(rdW),
                        .reg_writeM(reg_writeM), .reg_writeW(reg_writeW), .is_loadM(is_loadM),
                        .forwardAE(forwardAE), .forwardBE(forwardBE));

    assign dbg_wd = wdW; assign dbg_rd = rdW_out; assign dbg_rw = reg_writeW_out; assign dbg_fl = pc_srcE;
endmodule