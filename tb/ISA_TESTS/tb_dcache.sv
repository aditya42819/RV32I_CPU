`timescale 1ns/1ps
module tb_dcache;
    logic clk=0; always #5 clk=~clk;  logic rst_n=0;
    logic core_req, core_write, core_stall, core_rvalid;
    logic [31:0] core_addr, core_wdata, core_rdata;  logic [3:0] core_wstrb;
    logic [31:0] m_araddr, m_rdata; logic [7:0] m_arlen; logic [2:0] m_arsize; logic [1:0] m_arburst, m_rresp;
    logic m_arvalid, m_arready, m_rvalid, m_rlast, m_rready;
    logic [31:0] m_awaddr, m_wdata; logic [7:0] m_awlen; logic [2:0] m_awsize; logic [3:0] m_wstrb; logic [1:0] m_bresp;
    logic m_awvalid, m_awready, m_wvalid, m_wready, m_wlast, m_bvalid, m_bready;

    dcache u_dc (
        .clk(clk), .rst_n(rst_n),
        .core_req(core_req), .core_write(core_write), .core_addr(core_addr),
        .core_wdata(core_wdata), .core_wstrb(core_wstrb),
        .core_stall(core_stall), .core_rdata(core_rdata), .core_rvalid(core_rvalid),
        .m_araddr(m_araddr), .m_arvalid(m_arvalid), .m_arready(m_arready),
        .m_arlen(m_arlen), .m_arsize(m_arsize), .m_arburst(m_arburst),
        .m_rdata(m_rdata), .m_rvalid(m_rvalid), .m_rlast(m_rlast), .m_rresp(m_rresp), .m_rready(m_rready),
        .m_awaddr(m_awaddr), .m_awvalid(m_awvalid), .m_awready(m_awready),
        .m_awlen(m_awlen), .m_awsize(m_awsize),
        .m_wdata(m_wdata), .m_wstrb(m_wstrb), .m_wlast(m_wlast), .m_wvalid(m_wvalid), .m_wready(m_wready),
        .m_bvalid(m_bvalid), .m_bresp(m_bresp), .m_bready(m_bready));

    axi4_bram_slave_burst #(.WORDS(512), .MEM_INIT("test_dcache.hex")) u_mem (
        .clk(clk), .rst_n(rst_n),
        .awaddr(m_awaddr), .awvalid(m_awvalid), .awready(m_awready), .awlen(m_awlen), .awsize(m_awsize),
        .wdata(m_wdata), .wstrb(m_wstrb), .wlast(m_wlast), .wvalid(m_wvalid), .wready(m_wready),
        .bresp(m_bresp), .bvalid(m_bvalid), .bready(m_bready),
        .araddr(m_araddr), .arvalid(m_arvalid), .arready(m_arready),
        .arlen(m_arlen), .arsize(m_arsize), .arburst(m_arburst),
        .rdata(m_rdata), .rresp(m_rresp), .rlast(m_rlast), .rvalid(m_rvalid), .rready(m_rready));

    integer fails=0;
    task automatic do_store(input logic [31:0] a, input logic [31:0] d);
        while (core_rvalid) @(posedge clk);
        @(negedge clk); core_req=1; core_write=1; core_addr=a; core_wdata=d; core_wstrb=4'hf;
        @(negedge clk); core_req=0; core_write=0; core_wstrb=4'h0;
        @(posedge clk);
    endtask
    task automatic do_load(input logic [31:0] a, output logic [31:0] d);
        integer t;
        while (core_rvalid) @(posedge clk);
        @(negedge clk); core_req=1; core_write=0; core_addr=a;
        do @(negedge clk); while (core_stall);
        core_req=0;
        t=0; while (!core_rvalid && t<500) begin @(posedge clk); t=t+1; end
        d=core_rdata;
        if (t>=500) begin $display("  TIMEOUT load %h",a); fails=fails+1; end
    endtask
    task automatic check(input logic [31:0] got, input logic [31:0] exp, input string name);
        if (got===exp) $display("  OK   %s = %h", name, got);
        else begin $display("  FAIL %s = %h (want %h)", name, got, exp); fails=fails+1; end
    endtask

    logic [31:0] d;
    initial begin
        core_req=0; core_write=0; core_addr=0; core_wdata=0; core_wstrb=0;
        rst_n=0; repeat(3) @(posedge clk); rst_n=1; repeat(2) @(posedge clk);
        $display("== dcache write-back test ==");
        do_load(32'h000, d);  check(d, 32'h1000, "T1 read-miss fill");
        do_load(32'h004, d);  check(d, 32'h1001, "T1 read hit same line");
        do_store(32'h008, 32'hBEEF);
        do_load(32'h008, d);  check(d, 32'hBEEF, "T2 store-hit readback (dirty)");
        do_store(32'h010, 32'hCAFE);
        do_load(32'h010, d);  check(d, 32'hCAFE, "T3 store-miss then fill");
        do_load(32'h100, d);   // these four fill set0's ways...
        do_load(32'h200, d);
        do_load(32'h300, d);
        do_load(32'h400, d);   // ...and this one evicts the DIRTY line0 -> writeback
        do_load(32'h008, d);  check(d, 32'hBEEF, "T4 writeback preserved dirty line");
        repeat(3) @(posedge clk);
        if (fails==0) $display("PASS dcache"); else $display("FAIL dcache (%0d)", fails);
        $finish;
    end
endmodule