`timescale 1ns/1ps
module axi4_imem_master (
    input  logic        clk, rst_n,
    input  logic [31:0] pcF,
    output logic [31:0] instrF,
    output logic [31:0] araddr, output logic arvalid, input logic arready,
    input  logic [31:0] rdata,  input  logic rvalid,
    input  logic        rlast,  input  logic [1:0] rresp,
    output logic        rready
);
    assign araddr  = pcF;
    assign arvalid = 1'b1;
    assign rready  = 1'b1;
    assign instrF  = rdata;
endmodule