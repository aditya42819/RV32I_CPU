`timescale 1ns/1ps
module mem_wb_reg (
    input  logic        clk, rst_n,stall,
    input  logic [31:0] alu_resultM, pcplus4M, immM,
    input  logic [4:0]  rdM,
    input  logic        reg_writeM,
    input  logic [1:0]  result_srcM,
    output logic [31:0] alu_resultW, pcplus4W, immW,
    output logic [4:0]  rdW,
    output logic        reg_writeW,
    output logic [1:0]  result_srcW
);
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            alu_resultW <= 32'd0; 
            pcplus4W <= 32'd4; 
            immW <= 32'd0;
            rdW <= 5'd0; 
            reg_writeW <= 1'b0; 
            result_srcW <= 2'b00;
        end else if(!stall) begin
            alu_resultW <= alu_resultM; 
            pcplus4W <= pcplus4M; 
            immW <= immM;
            rdW <= rdM; 
            reg_writeW <= reg_writeM; 
            result_srcW <= result_srcM;
        end
    end
endmodule