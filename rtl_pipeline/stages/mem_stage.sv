`timescale 1ns/1ps
import cpu_package::*;
module mem_stage (
    input  logic [31:0] alu_resultM, writeDataM, pcplus4M, immM,
    input  logic [4:0]  rdM,
    input  logic        mem_writeM, reg_writeM,
    input  logic [1:0]  result_srcM,
    output logic [31:0] dmem_address, dmem_write_data,
    output logic        dmem_write_enable,
    output logic [3:0]  dmem_byte_enable,
    output logic [31:0] alu_resultM_out, pcplus4M_out, immM_out, wdM,
    output logic [4:0]  rdM_out,
    output logic        reg_writeM_out,
    output logic [1:0]  result_srcM_out
);
    assign dmem_address      = alu_resultM;
    assign dmem_write_data   = writeDataM;
    assign dmem_write_enable = mem_writeM;
    assign dmem_byte_enable  = mem_writeM ? 4'b1111 : 4'b0000;
    always_comb begin
        case (result_srcM)
            WRITEBACK_ALU:    wdM = alu_resultM;
            WRITEBACK_MEMORY: wdM = alu_resultM;
            WRITEBACK_PC4:    wdM = pcplus4M;
            WRITEBACK_IMM:    wdM = immM;
            default:          wdM = alu_resultM;
        endcase
    end
    assign alu_resultM_out = alu_resultM;
    assign rdM_out         = rdM;
    assign pcplus4M_out    = pcplus4M;
    assign reg_writeM_out  = reg_writeM;
    assign result_srcM_out = result_srcM;
    assign immM_out        = immM;
endmodule