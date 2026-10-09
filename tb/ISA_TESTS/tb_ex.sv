`timescale 1ns/1ps

module tb_ex;

    logic clk = 0;
    always #5 clk = ~clk;
    logic rst_n = 0;

    // IF wires
    logic [31:0] pcF, pcplus4F, instrF;
    // IF/ID wires
    logic [31:0] pcD, pcplus4D, instrD;
    // ID stage outputs
    logic [31:0] pcD_out, pcplus4D_out, rd1D, rd2D, immedD;
    logic [4:0]  rs1D, rs2D, rdD;
    logic [3:0]  alu_controlD;
    logic        alu_srcD, reg_writeD, mem_writeD, branchD, jumpD;
    logic [1:0]  result_srcD;
    logic [2:0]  branch_typeD;
    // ID/EX outputs (E-age)
    logic [31:0] pcE, pcplus4E, rd1E, rd2E, immedE;
    logic [4:0]  rs1E, rs2E, rdE;
    logic [3:0]  alu_controlE;
    logic        alu_srcE, reg_writeE, mem_writeE, branchE, jumpE;
    logic [1:0]  result_srcE;
    logic [2:0]  branch_typeE;
    // EX stage outputs
    logic [31:0] alu_resultE, pc_targetE, writeDataE, immE_out;
    logic        pc_srcE;
    logic [4:0]  rdE_out;
    logic [31:0] pcplus4E_out;
    logic        mem_writeE_out, reg_writeE_out;
    logic [1:0]  result_srcE_out;
    // EX/MEM outputs (M-age)
    logic [31:0] alu_resultM, writeDataM, pcplus4M, immM;
    logic [4:0]  rdM;
    logic        mem_writeM, reg_writeM;
    logic [1:0]  result_srcM;

    if_stage u_if (
        .clk(clk), .rst_n(rst_n), .stall(1'b0),
        .pcF(pcF), .pcplus4F(pcplus4F)
    );

    memory #(.WORDS(256), .mem_init("test_add_clean.hex")) u_imem (
        .clk(clk), .rst_n(rst_n),
        .address(pcF),
        .write_data(32'd0), .write_enable(1'b0), .byte_enable(4'b0),
        .read_data(instrF)
    );

    if_id_reg u_if_id (
        .clk(clk), .rst_n(rst_n),
        .pcF(pcF), .pcplus4F(pcplus4F), .instrF(instrF),
        .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD)
    );

    id_stage u_id (
        .clk(clk), .rst_n(rst_n),
        .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD),
        .reg_writeW(1'b0), .rdW(5'b0), .wdW(32'b0),
        .pcD_out(pcD_out), .pcplus4D_out(pcplus4D_out),
        .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD),
        .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD),
        .alu_controlD(alu_controlD), .alu_srcD(alu_srcD),
        .reg_writeD(reg_writeD), .mem_writeD(mem_writeD),
        .result_srcD(result_srcD), .branchD(branchD),
        .jumpD(jumpD), .branch_typeD(branch_typeD)
    );

    id_ex_reg u_id_ex (
        .clk(clk), .rst_n(rst_n),
        .pcD(pcD_out), .pcplus4D(pcplus4D_out),
        .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD),
        .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD),
        .alu_controlD(alu_controlD), .alu_srcD(alu_srcD),
        .reg_writeD(reg_writeD), .mem_writeD(mem_writeD),
        .result_srcD(result_srcD), .branchD(branchD),
        .jumpD(jumpD), .branch_typeD(branch_typeD),
        .pcE(pcE), .pcplus4E(pcplus4E), .rd1E(rd1E), .rd2E(rd2E),
        .rs1E(rs1E), .rs2E(rs2E), .rdE(rdE), .immedE(immedE),
        .alu_controlE(alu_controlE), .alu_srcE(alu_srcE),
        .reg_writeE(reg_writeE), .mem_writeE(mem_writeE),
        .result_srcE(result_srcE), .branchE(branchE),
        .jumpE(jumpE), .branch_typeE(branch_typeE)
    );

    ex_stage u_ex (
        .pcE(pcE), .rd1E(rd1E), .rd2E(rd2E), .immedE(immedE),
        .alu_controlE(alu_controlE), .alu_srcE(alu_srcE),
        .branchE(branchE), .jumpE(jumpE), .branch_typeE(branch_typeE),
        .rdE(rdE), .pcplus4E(pcplus4E), .mem_writeE(mem_writeE),
        .reg_writeE(reg_writeE), .result_srcE(result_srcE),
        .alu_resultE(alu_resultE), .pc_targetE(pc_targetE), .pc_srcE(pc_srcE),
        .writeDataE(writeDataE), .rdE_out(rdE_out),
        .pcplus4E_out(pcplus4E_out), .mem_writeE_out(mem_writeE_out),
        .reg_writeE_out(reg_writeE_out), .result_srcE_out(result_srcE_out),
        .immE_out(immE_out)
    );

    ex_mem_reg u_ex_mem (
        .clk(clk), .rst_n(rst_n),
        .alu_resultE(alu_resultE), .writeDataE(writeDataE),
        .rdE(rdE_out), .pcplus4E(pcplus4E_out),
        .mem_writeE(mem_writeE_out), .reg_writeE(reg_writeE_out),
        .result_srcE(result_srcE_out), .immE(immE_out),
        .alu_resultM(alu_resultM), .writeDataM(writeDataM), .rdM(rdM),
        .pcplus4M(pcplus4M), .mem_writeM(mem_writeM),
        .reg_writeM(reg_writeM), .result_srcM(result_srcM), .immM(immM)
    );

    initial begin
        rst_n = 0;
        repeat (2) @(posedge clk);
        rst_n = 1;
        repeat (15) @(posedge clk);
        $finish;
    end

    always @(posedge clk) begin
        if (rst_n) begin
            $display("t=%0t | pcE=%h | E: alu=%h | M: alu=%h rd=%d rw=%b",
                     $time, pcE, alu_resultE, alu_resultM, rdM, reg_writeM);
        end
    end

endmodule