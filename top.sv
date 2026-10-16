`timescale 1ns/1ps
module top (
    input  wire        clk_100mhz,
    input  wire        btn_rst_n,
    output wire [3:0]  led_status
);

    logic clk, rst_n;
    assign clk = clk_100mhz;
    assign rst_n = btn_rst_n;

    // --- Internal Wires for AXI GPIO ---
    logic [31:0] m_awaddr, m_wdata;
    logic [3:0]  m_wstrb;
    logic        m_awvalid, m_wvalid, m_bready;
    logic        m_awready, m_wready, m_bvalid;
    logic [1:0]  m_bresp;
    logic [3:0]  gpio_leds;

    // --- Internal Wires for Stubbed I-Cache & D-Cache Reads ---
    // We stub these so the CPU just fetches NOPs and reads 0, 
    // allowing us to focus purely on the D-Cache STORE to GPIO.
    logic [31:0] imem_rdata_stub, m_rdata_stub;
    logic        imem_arvalid_stub, imem_rvalid_stub, imem_rready_stub;
    logic        m_arvalid_stub, m_rvalid_stub, m_rready_stub;
    logic [7:0]  imem_arlen_stub, m_arlen_stub;
    logic [2:0]  imem_arsize_stub, m_arsize_stub;
    logic [1:0]  imem_arburst_stub, m_arburst_stub;
    logic [1:0]  imem_rresp_stub, m_rresp_stub;
    logic        imem_rlast_stub, m_rlast_stub;

    assign imem_rdata_stub = 32'h00000013; // NOP instruction
    assign m_rdata_stub    = 32'h00000000; // Read data = 0
    assign imem_rvalid_stub = 1'b1;
    assign m_rvalid_stub    = 1'b1;
    assign imem_rlast_stub  = 1'b1;
    assign m_rlast_stub     = 1'b1;
    assign imem_rresp_stub  = 2'b00;
    assign m_rresp_stub     = 2'b00;

    // --- CPU Instantiation ---
    cpu u_cpu (
        .clk(clk), .rst_n(rst_n),
        .pcF(), // Tie off PC for now
        
        // I-Cache Ports (Stubbed)
        .imem_araddr(), .imem_arvalid(imem_arvalid_stub), .imem_arready(1'b1),
        .imem_arlen(imem_arlen_stub), .imem_arsize(imem_arsize_stub), .imem_arburst(imem_arburst_stub),
        .imem_rdata(imem_rdata_stub), .imem_rvalid(imem_rvalid_stub), .imem_rlast(imem_rlast_stub), 
        .imem_rresp(imem_rresp_stub), .imem_rready(imem_rready_stub),
        
        // D-Cache Read Ports (Stubbed)
        .m_araddr(), .m_arvalid(m_arvalid_stub), .m_arready(1'b1),
        .m_arlen(m_arlen_stub), .m_arsize(m_arsize_stub), .m_arburst(m_arburst_stub),
        .m_rdata(m_rdata_stub), .m_rvalid(m_rvalid_stub), .m_rlast(m_rlast_stub), 
        .m_rresp(m_rresp_stub), .m_rready(m_rready_stub),

        // D-Cache WRITE Ports -> Connected to AXI GPIO
        .m_awaddr(m_awaddr), .m_awvalid(m_awvalid), .m_awready(m_awready),
        .m_wdata(m_wdata), .m_wstrb(m_wstrb), .m_wvalid(m_wvalid), .m_wready(m_wready),
        .m_bvalid(m_bvalid), .m_bresp(m_bresp), .m_bready(m_bready),
        
        // Debug ports (Tie off)
        .dbg_wd(), .dbg_rd(), .dbg_rw(), .dbg_fl()
    );

    // --- AXI GPIO Instantiation ---
    axi_gpio u_gpio (
        .clk(clk), .rst_n(rst_n),
        .awaddr(m_awaddr), .awvalid(m_awvalid), .awready(m_awready),
        .wdata(m_wdata), .wstrb(m_wstrb), .wvalid(m_wvalid), .wready(m_wready),
        .bready(1'b1), .bvalid(m_bvalid), .bresp(m_bresp),
        .led_out(gpio_leds)
    );

    // Drive physical LEDs: [3] = Inverted Reset, [2:0] = GPIO Data
    assign led_status = { ~rst_n, gpio_leds[2:0] };

endmodule
