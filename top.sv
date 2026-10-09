`timescale 1ns/1ps
module top (
    input  wire        clk_100mhz,   // Board clock
    input  wire        btn_rst_n,    // Reset button (active low)
    output wire [3:0]  led_status    // 4 LEDs to show CPU activity
);
    // Slow down the clock if needed, or use it directly. 
    // For a 5-stage pipeline, 100MHz might be tight depending on the board.
    // You might need a clock divider or PLL later, but start simple.
    
    logic clk;
    logic rst_n;
    
    // Simple clock divider (optional, removes timing pressure for first test)
    // logic [25:0] clk_div;
    // always_ff @(posedge clk_100mhz) clk_div <= clk_div + 1;
    // assign clk = clk_div[25]; // ~1.5 MHz
    
    assign clk = clk_100mhz;       // Or use the divided clock above
    assign rst_n = btn_rst_n;

    // CPU Instantiation
    logic [31:0] pcF;
    logic [31:0] dbg_wd;
    logic [4:0]  dbg_rd;
    logic        dbg_rw, dbg_fl;
    
    // AXI ports (tie off or connect to on-chip BRAM later)
    // For a first test, you can leave the AXI ports unconnected if your 
    // synthesis tool allows it, or instantiate a simple BRAM wrapper.
    
    cpu u_cpu (
        .clk(clk), .rst_n(rst_n),
        .pcF(pcF),
        // Tie off AXI for now, or connect to a BRAM IP in Vivado/Quartus
        .imem_araddr(), .imem_arvalid(), .imem_arready(1'b1),
        .imem_arlen(), .imem_arsize(), .imem_arburst(),
        .imem_rdata(32'h00000013), .imem_rvalid(1'b1), .imem_rlast(1'b1), .imem_rresp(2'b00), // NOP fallback
        .imem_rready(),
        .m_awaddr(), .m_awvalid(), .m_awready(1'b1), .m_awlen(), .m_awsize(),
        .m_wdata(), .m_wstrb(), .m_wlast(), .m_wvalid(), .m_wready(1'b1),
        .m_bvalid(1'b1), .m_bresp(2'b00), .m_bready(),
        .m_araddr(), .m_arvalid(), .m_arready(1'b1), .m_arlen(), .m_arsize(), .m_arburst(),
        .m_rdata(32'h00000000), .m_rvalid(1'b1), .m_rlast(1'b1), .m_rresp(2'b00), .m_rready(),
        .dbg_wd(dbg_wd), .dbg_rd(dbg_rd), .dbg_rw(dbg_rw), .dbg_fl(dbg_fl)
    );

    // Tie LEDs to interesting signals to prove it's running:
    // led[0] = Clock activity (if divided) or just 1'b1
    // led[1] = Register Write activity (dbg_rw)
    // led[2] = Branch/Jump flush activity (dbg_fl)
    // led[3] = Inverted reset (shows button is working)
    assign led_status = { ~rst_n, dbg_fl, dbg_rw, 1'b1 };

endmodule
