`timescale 1ns/1ps
module axi4_bram_slave #(
    parameter WORDS = 4096,
    parameter string MEM_INIT = ""
)(
    input  logic        clk, rst_n,
    input  logic [31:0] awaddr,  input  logic awvalid, output logic awready,
    input  logic [31:0] wdata,   input  logic [3:0] wstrb,
    input  logic        wlast,   input  logic wvalid,  output logic wready,
    output logic [1:0]  bresp,   output logic bvalid,  input  logic bready,
    input  logic [31:0] araddr,  input  logic arvalid, output logic arready,
    output logic [31:0] rdata,   output logic [1:0] rresp,
    output logic        rlast,   output logic rvalid,  input  logic rready
);
    logic [31:0] mem [0:WORDS-1];
    initial if (MEM_INIT != "") $readmemh(MEM_INIT, mem);

    assign arready = 1'b1;
    assign awready = 1'b1;
    assign wready  = 1'b1;

    logic [31:0] rdata_r;
    logic        rvalid_r, bvalid_r;

    always_ff @(posedge clk) begin
        if (awvalid && awready && wvalid && wready) begin
            for (int b = 0; b < 4; b++)
                if (wstrb[b]) mem[awaddr[31:2]][8*b +: 8] <= wdata[8*b +: 8];
        end
        if (arvalid && arready) rdata_r <= mem[araddr[31:2]];
        rvalid_r  <= arvalid && arready;
        bvalid_r  <= awvalid && awready && wvalid && wready;
    end

    assign rdata  = rdata_r;
    assign rvalid = rvalid_r;
    assign rlast  = 1'b1;
    assign rresp  = 2'b00;
    assign bvalid = bvalid_r;
    assign bresp  = 2'b00;
endmodule