`timescale 1ns/1ps

module id_ex_reg (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        flush,
    input logic         stall,
    input  logic [31:0] pcD,
    input  logic [31:0] pcplus4D,
    input  logic [31:0] rd1D,
    input  logic [31:0] rd2D,
    input  logic [31:0] immedD,
    input  logic [4:0]  rs1D,
    input  logic [4:0]  rs2D,
    input  logic [4:0]  rdD,
    input  logic [3:0]  alu_controlD,
    input  logic        alu_srcD,
    input  logic        reg_writeD,
    input  logic        mem_writeD,
    input  logic [1:0]  result_srcD,
    input  logic        branchD,
    input  logic        jumpD,
    input  logic [2:0]  branch_typeD,
    output logic [31:0] pcE,
    output logic [31:0] pcplus4E,
    output logic [31:0] rd1E,
    output logic [31:0] rd2E,
    output logic [4:0]  rs1E,
    output logic [4:0]  rs2E,
    output logic [4:0]  rdE,
    output logic [31:0] immedE,
    output logic [3:0]  alu_controlE,
    output logic        alu_srcE,
    output logic        reg_writeE,
    output logic        mem_writeE,
    output logic [1:0]  result_srcE,
    output logic        branchE,
    output logic        jumpE,
    output logic [2:0]  branch_typeE
);

    always_ff @(posedge clk) begin
        if (!rst_n || flush) begin
            pcE          <= 32'd0;
            pcplus4E     <= 32'd4;
            rd1E         <= 32'd0;
            rd2E         <= 32'd0;
            rs1E         <= 5'd0;
            rs2E         <= 5'd0;
            rdE          <= 5'd0;
            immedE       <= 32'd0;
            alu_controlE <= 4'd0;
            alu_srcE     <= 1'b0;
            reg_writeE   <= 1'b0;
            mem_writeE   <= 1'b0;
            result_srcE  <= 2'b00;
            branchE      <= 1'b0;
            jumpE        <= 1'b0;
            branch_typeE <= 3'b000;
        end else if(!stall) begin
            pcE          <= pcD;
            pcplus4E     <= pcplus4D;
            rd1E         <= rd1D;
            rd2E         <= rd2D;
            rs1E         <= rs1D;
            rs2E         <= rs2D;
            rdE          <= rdD;
            immedE       <= immedD;
            alu_controlE <= alu_controlD;
            alu_srcE     <= alu_srcD;
            reg_writeE   <= reg_writeD;
            mem_writeE   <= mem_writeD;
            result_srcE  <= result_srcD;
            branchE      <= branchD;
            jumpE        <= jumpD;
            branch_typeE <= branch_typeD;
        end
    end

endmodule