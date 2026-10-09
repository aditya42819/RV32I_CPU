`timescale 1ns/1ps

import cpu_package::*;

module cpu (
    input  logic        rst_n,
    input  logic        clk,

    output logic [31:0] instr_address,
    input  logic [31:0] instr_rdata,

    input  logic [31:0] data_rdata,
    output logic [31:0] data_address,
    output logic [31:0] data_writedata,
    output logic        data_writeenable,
    output logic [3:0]  data_byteenable
);

    logic [31:0] pc;
    logic [31:0] pc_next;
    logic [31:0] pc_plus4;
    logic [31:0] pc_target;

    logic [6:0] opcode;
    logic [6:0] funct7;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rd;
    logic [2:0] funct3;

    logic [31:0] read_reg1;
    logic [31:0] read_reg2;
    logic [31:0] writeback_data;
    logic [31:0] immediate;

    logic [31:0] alu_src1;
    logic [31:0] alu_src2;
    logic [31:0] alu_result;

    logic [31:0] store_data;
    logic [31:0] load_data;

    logic [3:0] alu_control;
    logic [2:0] imm_source;
    logic [2:0] branch_type;
    logic [1:0] result_src;

    logic alu_src;
    logic reg_write;
    logic mem_write;
    logic branch;
    logic jump;

    logic alu_zero;
    logic alu_last_bit;
    logic branch_taken;

    assign opcode = instr_rdata[6:0];
    assign rd     = instr_rdata[11:7];
    assign funct3 = instr_rdata[14:12];
    assign rs1    = instr_rdata[19:15];
    assign rs2    = instr_rdata[24:20];
    assign funct7 = instr_rdata[31:25];

    assign instr_address = pc;
    assign pc_plus4 = pc + 32'd4;

    always_comb begin
        case (branch_type)
            BR_BEQ:  branch_taken = (read_reg1 == read_reg2);
            BR_BNE:  branch_taken = (read_reg1 != read_reg2);
            BR_BLT:  branch_taken = ($signed(read_reg1) <  $signed(read_reg2));
            BR_BGE:  branch_taken = ($signed(read_reg1) >= $signed(read_reg2));
            BR_BLTU: branch_taken = (read_reg1 <  read_reg2);
            BR_BGEU: branch_taken = (read_reg1 >= read_reg2);
            default: branch_taken = 1'b0;
        endcase
    end

    always_comb begin
        if (jump && opcode == OPCODE_JALR)
            pc_target = (read_reg1 + immediate) & 32'hffff_fffe;
        else
            pc_target = pc + immediate;

        if (jump || (branch && branch_taken))
            pc_next = pc_target;
        else
            pc_next = pc_plus4;
    end

    program_counter u_pc (
        .clk     (clk),
        .reset   (~rst_n),
        .next_pc (pc_next),
        .pc      (pc)
    );

    control u_control (
        .opcode      (opcode),
        .funct3      (funct3),
        .funct7      (funct7),
        .alu_control (alu_control),
        .imm_source  (imm_source),
        .alu_src     (alu_src),
        .reg_write   (reg_write),
        .mem_write   (mem_write),
        .result_src  (result_src),
        .branch      (branch),
        .jump        (jump),
        .branch_type (branch_type)
    );

    signext u_signext (
        .raw_src    (instr_rdata[31:7]),
        .imm_source (imm_source),
        .immediate  (immediate)
    );

    assign alu_src1 = (opcode == OPCODE_AUIPC) ? pc : read_reg1;
    assign alu_src2 = alu_src ? immediate : read_reg2;

    alu u_alu (
        .alu_control (alu_control),
        .src1        (alu_src1),
        .src2        (alu_src2),
        .alu_result  (alu_result),
        .zero        (alu_zero),
        .last_bit    (alu_last_bit)
    );

    load_store_decoder u_store_decoder (
        .alu_result  (alu_result),
        .funct3      (funct3),
        .reg_read    (read_reg2),
        .data        (store_data),
        .byte_enable (data_byteenable)
    );

    assign data_address     = {alu_result[31:2], 2'b00};
    assign data_writedata   = store_data;
    assign data_writeenable = mem_write;

    reader u_reader (
        .mem_data   (data_rdata),
        .alu_result (alu_result),
        .funct3     (funct3),
        .read_data  (load_data)
    );

    always_comb begin
        case (result_src)
            WRITEBACK_ALU:    writeback_data = alu_result;
            WRITEBACK_MEMORY: writeback_data = load_data;
            WRITEBACK_PC4:    writeback_data = pc_plus4;
            WRITEBACK_IMM:    writeback_data = immediate;
            default:          writeback_data = 32'd0;
        endcase
    end

    regfile u_regfile (
        .clk          (clk),
        .rst          (~rst_n),
        .rs1          (rs1),
        .rs2          (rs2),
        .rd           (rd),
        .write_data   (writeback_data),
        .write_enable (reg_write),
        .data1        (read_reg1),
        .data2        (read_reg2)
    );

endmodule