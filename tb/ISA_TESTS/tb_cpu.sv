`timescale 1ns/1ps

module tb_cpu;
    logic clk = 0;  always #5 clk = ~clk;
    logic rst_n = 0;

    logic [31:0] pcF, instrF;
    logic [31:0] dmem_addr, dmem_wdata, dmem_rdata;
    logic        dmem_we;
    logic [3:0]  dmem_be;
    logic [31:0] wd;  logic [4:0] rd;  logic rw, fl;

    cpu u_cpu (.clk(clk), .rst_n(rst_n),
               .pcF(pcF), .instrF(instrF),
               .dmem_addr(dmem_addr), .dmem_wdata(dmem_wdata),
               .dmem_we(dmem_we), .dmem_be(dmem_be), .dmem_rdata(dmem_rdata),
               .dbg_wd(wd), .dbg_rd(rd), .dbg_rw(rw), .dbg_fl(fl));

    memory #(.WORDS(256), .mem_init("test_jump.hex")) u_imem (
        .clk(clk), .rst_n(rst_n), .address(pcF),
        .write_data(32'd0), .write_enable(1'b0), .byte_enable(4'b0),
        .read_data(instrF));

    memory #(.WORDS(4096), .mem_init("test_dmemory.hex")) u_dmem (
        .clk(clk), .rst_n(rst_n), .address(dmem_addr),
        .write_data(dmem_wdata), .write_enable(dmem_we),
        .byte_enable(dmem_be), .read_data(dmem_rdata));

    initial begin
        rst_n = 0;  repeat (2) @(posedge clk);  rst_n = 1;
        repeat (30) @(posedge clk);  $finish;
    end

    always @(posedge clk) if (rst_n)
        $display("t=%0t | W: rd=%2d wd=%h rw=%b fl=%b", $time, rd, wd, rw, fl);
endmodule