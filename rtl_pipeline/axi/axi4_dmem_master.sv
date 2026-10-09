`timescale 1ns/1ps
module axi4_dmem_master (
    input  logic        clk, rst_n,
    input  logic [31:0] dmem_addr,  input  logic        dmem_we,
    input  logic [31:0] dmem_wdata, input  logic [3:0]  dmem_be,
    output logic [31:0] dmem_rdata,
    output logic [31:0] awaddr, output logic awvalid, input logic awready,
    output logic [31:0] wdata,  output logic [3:0] wstrb,
    output logic        wlast,  output logic wvalid,  input logic wready,
    input  logic        bvalid, input  logic [1:0] bresp, output logic bready,
    output logic [31:0] araddr, output logic arvalid, input logic arready,
    input  logic [31:0] rdata,  input  logic rvalid,
    input  logic        rlast,  input  logic [1:0] rresp, output logic rready
);
    assign araddr  = dmem_addr;
    assign arvalid = 1'b1;
    assign rready  = 1'b1;
    assign dmem_rdata = rdata;

    assign awaddr  = dmem_addr;
    assign awvalid = dmem_we;
    assign wdata   = dmem_wdata;
    assign wstrb   = dmem_be;
    assign wlast   = 1'b1;
    assign wvalid  = dmem_we;
    assign bready  = 1'b1;
endmodule