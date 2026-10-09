`timescale 1ns/1ps
module tb_burst;
    logic clk = 0;  always #5 clk = ~clk;
    logic rst_n = 0;

    logic [31:0] araddr, rdata; logic [7:0] arlen; logic [2:0] arsize; logic [1:0] arburst, rresp;
    logic arvalid, arready, rvalid, rlast, rready;
    logic [31:0] awaddr, wdata; logic [3:0] wstrb; logic awvalid, wvalid, wlast, wready, bvalid, bready;
    logic [1:0] bresp;

    axi4_bram_slave_burst #(.WORDS(256), .MEM_INIT("test_burst.hex")) u_sl (
        .clk(clk), .rst_n(rst_n),
        .awaddr(awaddr), .awvalid(awvalid), .awready(awready),
        .wdata(wdata), .wstrb(wstrb), .wlast(wlast), .wvalid(wvalid), .wready(wready),
        .bresp(bresp), .bvalid(bvalid), .bready(bready),
        .araddr(araddr), .arvalid(arvalid), .arready(arready),
        .arlen(arlen), .arsize(arsize), .arburst(arburst),
        .rdata(rdata), .rresp(rresp), .rlast(rlast), .rvalid(rvalid), .rready(rready));

    int cy = 0, cnt = 0, fails = 0;  
    logic done = 0;
    
    always @(posedge clk) cy <= cy + 1;
    assign rready = !(cy == 9 || cy == 10);          // two wait-states mid-burst

    // Declare empty arrays
    logic [31:0] exp_data [0:3];
    logic [31:0] exp_addr [0:3];

    initial begin
        // Icarus Verilog doesn't like the '{...} array literal at declaration time.
        // Initialize them element-by-element here instead.
        exp_data[0] = 32'he;  exp_data[1] = 32'hf;  exp_data[2] = 32'h10; exp_data[3] = 32'h11;
        exp_addr[0] = 32'h10; exp_addr[1] = 32'h14; exp_addr[2] = 32'h18; exp_addr[3] = 32'h1c;

        arvalid = 0; araddr = 0; arlen = 0; arsize = 3'd2; arburst = 2'b01;
        awvalid = 0; wvalid = 0; wlast = 0; wdata = 0; wstrb = 0; awaddr = 0; bready = 1;
        
        rst_n = 0;  repeat (2) @(posedge clk);  rst_n = 1;
        
        // Fire the burst
        @(negedge clk);  arvalid = 1; araddr = 32'h0000_0010; arlen = 8'd3;
        @(negedge clk);  arvalid = 0;
    end

    always @(posedge clk) begin
        if (rst_n && rvalid && rready) begin
            $display("beat%0d  addr=%h  data=%h  rlast=%b", cnt, exp_addr[cnt], rdata, rlast);
            if (rdata !== exp_data[cnt]) begin $display("  DATA MISMATCH"); fails = fails + 1; end
            if ((cnt == 3) !== rlast)      begin $display("  RLAST MISMATCH"); fails = fails + 1; end
            cnt = cnt + 1;
            if (cnt == 4) done = 1;
        end
    end

    initial begin
        wait (done);  repeat (2) @(posedge clk);
        if (fails == 0) $display("PASS burst"); else $display("FAIL burst (%0d)", fails);
        $finish;
    end
endmodule