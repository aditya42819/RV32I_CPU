`timescale 1ns/1ps
module axi_gpio (
    input  logic        clk, rst_n,
    input  logic [31:0] awaddr, input  logic awvalid, output logic awready,
    input  logic [31:0] wdata,  input  logic [3:0] wstrb, input  logic wvalid, output logic wready,
    input  logic        bready, output logic bvalid, output logic [1:0] bresp,
    output logic [3:0]  led_out
);
    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign bresp   = 2'b00;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin led_out <= 4'b0000; bvalid <= 1'b0; end
        else begin
            bvalid <= (awvalid && wvalid);
            if (awvalid && wvalid && awaddr[31:28] == 4'h4) begin // Address 0x40000000
                led_out <= wdata[3:0]; 
            end
        end
    end
endmodule