`timescale 1ns/1ps

module tb_isa;
    logic clk = 0;  always #5 clk = ~clk;
    logic rst_n = 0;

    logic [31:0] pcF;
    // I-MEM AXI
    logic [31:0] imem_araddr, imem_rdata; logic imem_arvalid, imem_arready, imem_rvalid, imem_rlast, imem_rready;
    logic [7:0] imem_arlen; logic [2:0] imem_arsize; logic [1:0] imem_arburst, imem_rresp;
    // D-MEM AXI
    logic [31:0] m_awaddr, m_wdata, m_araddr, m_rdata;
    logic m_awvalid, m_awready, m_wvalid, m_wready, m_wlast, m_bvalid, m_bready;
    logic m_arvalid, m_arready, m_rvalid, m_rlast, m_rready;
    logic [3:0] m_wstrb; logic [1:0] m_bresp, m_rresp;
    logic [7:0] m_awlen, m_arlen; logic [2:0] m_awsize, m_arsize; logic [1:0] m_arburst;

    logic [31:0] wd;
    logic [4:0]  rd;
    logic        rw;

    reg [8*64:1] hex_file, exp_file;
    logic [31:0] exp_regs [0:31];
    logic [31:0] shadow   [0:31];
    integer i, fails;

    cpu u_cpu (.clk(clk), .rst_n(rst_n),
               .pcF(pcF),
               // I-MEM AXI Ports
               .imem_araddr(imem_araddr), .imem_arvalid(imem_arvalid), .imem_arready(imem_arready),
               .imem_arlen(imem_arlen), .imem_arsize(imem_arsize), .imem_arburst(imem_arburst),
               .imem_rdata(imem_rdata), .imem_rvalid(imem_rvalid), .imem_rlast(imem_rlast), .imem_rresp(imem_rresp),
               .imem_rready(imem_rready),
               // D-MEM AXI Ports
               .m_awaddr(m_awaddr), .m_awvalid(m_awvalid), .m_awready(m_awready),
               .m_awlen(m_awlen), .m_awsize(m_awsize),
               .m_wdata(m_wdata), .m_wstrb(m_wstrb), .m_wlast(m_wlast), .m_wvalid(m_wvalid), .m_wready(m_wready),
               .m_bvalid(m_bvalid), .m_bresp(m_bresp), .m_bready(m_bready),
               .m_araddr(m_araddr), .m_arvalid(m_arvalid), .m_arready(m_arready),
               .m_arlen(m_arlen), .m_arsize(m_arsize), .m_arburst(m_arburst),
               .m_rdata(m_rdata), .m_rvalid(m_rvalid), .m_rlast(m_rlast), .m_rresp(m_rresp), .m_rready(m_rready),
               // Debug
               .dbg_wd(wd), .dbg_rd(rd), .dbg_rw(rw), .dbg_fl());

    // I-MEM Slave (Directly connected to CPU)
    axi4_bram_slave_burst #(.WORDS(256), .MEM_INIT("")) u_islave (.clk(clk), .rst_n(rst_n),
        .awaddr(32'd0), .awvalid(1'b0), .awready(), .awlen(8'd0), .awsize(3'd0),
        .wdata(32'd0), .wstrb(4'd0), .wlast(1'b0), .wvalid(1'b0), .wready(),
        .bresp(), .bvalid(), .bready(1'b1),
        .araddr(imem_araddr), .arvalid(imem_arvalid), .arready(imem_arready),
        .arlen(imem_arlen), .arsize(imem_arsize), .arburst(imem_arburst),
        .rdata(imem_rdata), .rresp(imem_rresp), .rlast(imem_rlast), .rvalid(imem_rvalid), .rready(imem_rready));

    // D-MEM Slave (Directly connected to CPU's D-Cache)
    axi4_bram_slave_burst #(.WORDS(4096), .MEM_INIT("test_dmemory.hex")) u_dslave (.clk(clk), .rst_n(rst_n),
        .awaddr(m_awaddr), .awvalid(m_awvalid), .awready(m_awready), .awlen(m_awlen), .awsize(m_awsize),
        .wdata(m_wdata), .wstrb(m_wstrb), .wlast(m_wlast), .wvalid(m_wvalid), .wready(m_wready),
        .bresp(m_bresp), .bvalid(m_bvalid), .bready(m_bready),
        .araddr(m_araddr), .arvalid(m_arvalid), .arready(m_arready), .arlen(m_arlen), .arsize(m_arsize), .arburst(m_arburst),
        .rdata(m_rdata), .rresp(m_rresp), .rlast(m_rlast), .rvalid(m_rvalid), .rready(m_rready));

    always @(negedge clk) begin
        if (rst_n && rw && rd != 5'd0) shadow[rd] = wd;
    end

    initial begin
        for (i = 0; i < 32; i = i + 1) shadow[i] = 32'd0;
        if (!$value$plusargs("HEX=%s", hex_file)) hex_file = "test_add_clean.hex";
        if (!$value$plusargs("EXP=%s", exp_file)) exp_file = "exp_zero.hex";
        $readmemh(hex_file, u_islave.mem);
        $readmemh(exp_file, exp_regs);
        rst_n = 0;  repeat (2) @(posedge clk);  rst_n = 1;
        repeat (60) @(posedge clk);
        fails = 0;
        for (i = 1; i < 32; i = i + 1) begin
            if (shadow[i] !== exp_regs[i]) begin
                $display("  FAIL x%0d: got %h, want %h", i, shadow[i], exp_regs[i]);
                fails = fails + 1;
            end
        end
        if (fails == 0) $display("PASS %s", hex_file);
        else            $display("FAIL %s (%0d mismatches)", hex_file, fails);
        $finish;
    end
endmodule