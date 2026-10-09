`timescale 1ns/1ps
module if_stage (
    input  logic        clk, rst_n,
    input  logic        stall,      // holds PC when anything downstream/icache stalls
    input  logic        flush,      // branch/jump redirect
    input  logic [31:0] pc_targetE,
    output logic [31:0] pcF,
    output logic [31:0] pcplus4F
);
    logic [31:0] pc;
    assign pcF      = pc;
    assign pcplus4F = pc + 32'd4;

    always_ff @(posedge clk) begin
        if (!rst_n)        pc <= 32'd0;
        else if (flush)    pc <= pc_targetE;   // redirect wins over stall
        else if (!stall)   pc <= pc + 32'd4;
    end
endmodule