`timescale 1ns/1ps

module sram_bus #(
    parameter WORDS = 4096,
    parameter string MEM_INIT = ""
)(
    input  logic        clk,
    input  logic        rst_n,
    input  logic        req_valid,
    input  logic        req_write,
    input  logic [31:0] req_addr,
    input  logic [31:0] req_wdata,
    input  logic [3:0]  req_wstrb,
    output logic        rsp_valid,
    output logic [31:0] rsp_rdata
);
    logic [31:0] mem [0:WORDS-1];
    logic [31:0] rdata_r;
    logic        valid_r;

    initial if (MEM_INIT != "") $readmemh(MEM_INIT, mem);

    always_ff @(posedge clk) begin
        if (req_valid && req_write) begin
            for (int b = 0; b < 4; b++)
                if (req_wstrb[b]) mem[req_addr[31:2]][8*b +: 8] <= req_wdata[8*b +: 8];
        end
        rdata_r <= mem[req_addr[31:2]];   // synchronous read: data next cycle
        valid_r <= req_valid & ~req_write;
    end

    assign rsp_rdata = rdata_r;
    assign rsp_valid = valid_r;
endmodule