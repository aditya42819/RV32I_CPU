`timescale 1ns/1ps
module axi4_bram_slave_burst #(
    parameter WORDS = 4096,
    parameter string MEM_INIT = ""
)(
    input  logic        clk, rst_n,
    input  logic [31:0] awaddr, input logic awvalid, output logic awready,
    input  logic [7:0]  awlen,  input logic [2:0] awsize,
    input  logic [31:0] wdata,  input logic [3:0] wstrb,
    input  logic        wlast,  input logic wvalid, output logic wready,
    output logic [1:0]  bresp,  output logic bvalid, input logic bready,
    input  logic [31:0] araddr, input logic arvalid, output logic arready,
    input  logic [7:0]  arlen,  input logic [2:0] arsize, input logic [1:0] arburst,
    output logic [31:0] rdata,  output logic [1:0] rresp,
    output logic        rlast,  output logic rvalid, input logic rready
);
    logic [31:0] mem [0:WORDS-1];
    initial if (MEM_INIT != "") $readmemh(MEM_INIT, mem);

    // ---- WRITE: burst-capable ----
    typedef enum logic [1:0] { WIDLE, WBUSY } wstate_t;
    wstate_t wstate;
    logic [31:0] waddr_r;  logic [2:0] wsize_r;  logic bvalid_r;
    assign awready = (wstate == WIDLE);
    assign wready  = (wstate == WIDLE) ? awvalid : 1'b1;
    always_ff @(posedge clk) begin
        if (!rst_n) begin wstate <= WIDLE; bvalid_r <= 0; end
        else begin
            bvalid_r <= 1'b0;
            case (wstate)
                WIDLE: begin
                    if (awvalid && wvalid) begin
                        for (int b=0;b<4;b++) if (wstrb[b]) mem[awaddr[31:2]][8*b +: 8] <= wdata[8*b +: 8];
                        if (wlast) bvalid_r <= 1'b1;
                        else begin waddr_r <= awaddr + (32'd1 << awsize); wsize_r <= awsize; wstate <= WBUSY; end
                    end else if (awvalid) begin
                        waddr_r <= awaddr; wsize_r <= awsize; wstate <= WBUSY;
                    end
                end
                WBUSY: if (wvalid) begin
                    for (int b=0;b<4;b++) if (wstrb[b]) mem[waddr_r[31:2]][8*b +: 8] <= wdata[8*b +: 8];
                    if (wlast) begin bvalid_r <= 1'b1; wstate <= WIDLE; end
                    else       waddr_r <= waddr_r + (32'd1 << wsize_r);
                end
            endcase
        end
    end
    assign bvalid = bvalid_r;  assign bresp = 2'b00;

    // ---- READ: burst-capable, with BACK-TO-BACK AR acceptance ----
    typedef enum logic [1:0] { RIDLE, RBUSY } rstate_t;
    rstate_t rstate;
    logic [31:0] raddr_r, rdata_r;
    logic [7:0]  rcnt_r, rlen_r;
    logic [2:0]  rsize_r;
    logic        rvalid_r, rlast_r;

    // KEY FIX: accept a new AR when idle, OR when finishing the current burst
    wire burst_finishing = (rstate == RBUSY) && rvalid_r && rready && rlast_r;
    assign arready = (rstate == RIDLE) || burst_finishing;

    always_ff @(posedge clk) begin
        if (!rst_n) begin rstate <= RIDLE; rvalid_r <= 0; rlast_r <= 0; rcnt_r <= 0; end
        else case (rstate)
            RIDLE: begin
                rvalid_r <= 1'b0;
                if (arvalid && arready) begin
                    raddr_r <= araddr; rlen_r <= arlen; rsize_r <= arsize; rcnt_r <= 0;
                    rdata_r <= mem[araddr[31:2]];
                    rvalid_r <= 1'b1; rlast_r <= (arlen == 8'd0);
                    rstate <= RBUSY;
                end
            end
            RBUSY: begin
                // NEW AR arriving exactly as the current burst completes -> reload immediately
                if (burst_finishing && arvalid) begin
                    raddr_r <= araddr; rlen_r <= arlen; rsize_r <= arsize; rcnt_r <= 0;
                    rdata_r <= mem[araddr[31:2]];
                    rvalid_r <= 1'b1; rlast_r <= (arlen == 8'd0);
                end
                else if (rvalid_r && rready) begin
                    if (rcnt_r == rlen_r) begin rvalid_r <= 0; rlast_r <= 0; rstate <= RIDLE; end
                    else begin
                        logic [31:0] nxt;  nxt = raddr_r + (32'd1 << rsize_r);
                        raddr_r <= nxt;  rcnt_r <= rcnt_r + 8'd1;
                        rdata_r <= mem[nxt[31:2]];
                        rvalid_r <= 1'b1; rlast_r <= (rcnt_r + 8'd1 == rlen_r);
                    end
                end
            end
        endcase
    end
    assign rdata = rdata_r;  assign rvalid = rvalid_r;  assign rlast = rlast_r;  assign rresp = 2'b00;
endmodule