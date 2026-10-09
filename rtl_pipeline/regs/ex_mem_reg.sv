`timescale 1ns/1ps

module ex_mem_reg (
    input  logic        clk,
    input  logic        rst_n,
    input logic         stall,

    // Passengers boarding from the EX stage (suffix E)
    input  logic [31:0] alu_resultE,   
    input  logic [31:0] writeDataE,    
    input  logic [4:0]  rdE,           
    input  logic [31:0] pcplus4E,      
    input  logic        mem_writeE,   
    input  logic        reg_writeE,    
    input  logic [1:0]  result_srcE,  
        input  logic [31:0] immE,

    // Passengers exiting toward the MEM stage (suffix M)
    output logic [31:0] alu_resultM,
    output logic [31:0] writeDataM,
    output logic [4:0]  rdM,
    output logic [31:0] pcplus4M,
    output logic        mem_writeM,
    output logic        reg_writeM,
        output logic [31:0] immM,
    output logic [1:0]  result_srcM
);

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            alu_resultM  <= 32'd0;
            writeDataM   <= 32'd0;
            rdM          <= 5'd0;
            pcplus4M     <= 32'd4;     // Keeping it consistent with IF reset
            mem_writeM   <= 1'b0;
            reg_writeM   <= 1'b0;
            result_srcM  <= 2'b00;
            immM <= 32'd0;
        end else if(!stall) begin
            alu_resultM  <= alu_resultE;
            writeDataM   <= writeDataE;
            rdM          <= rdE;
            pcplus4M     <= pcplus4E;
            mem_writeM   <= mem_writeE;
            reg_writeM   <= reg_writeE;
            result_srcM  <= result_srcE;
            immM         <= immE;
        end
    end

endmodule