`timescale 1ns/1ps
import cpu_package::*;

module wb_stage (
    input  logic [31:0] alu_resultW,
    input  logic [31:0] read_dataW,
    input  logic [31:0] pcplus4W,
    input  logic [31:0] immW,
    input  logic [1:0]  result_srcW,
    input  logic [4:0]  rdW,
    input  logic        reg_writeW,
    output logic [31:0] wdW,
    output logic [4:0]  rdW_out,
    output logic        reg_writeW_out
);
    always_comb begin
        case (result_srcW)
            WRITEBACK_ALU:    wdW = alu_resultW;
            WRITEBACK_MEMORY: wdW = read_dataW;
            WRITEBACK_PC4:    wdW = pcplus4W;
            WRITEBACK_IMM:    wdW = immW;
            default:          wdW = alu_resultW;
        endcase
    end
    assign rdW_out        = rdW;
    assign reg_writeW_out = reg_writeW;
endmodule