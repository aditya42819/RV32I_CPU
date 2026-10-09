`timescale 1ns/1ps

module regfile (
    input  logic        clk,
    input  logic        rst,
    input  logic [4:0]  rs1,
    input  logic [4:0]  rs2,
    input  logic [4:0]  rd,
    input  logic [31:0] write_data,
    input  logic        write_enable,
    output logic [31:0] data1,
    output logic [31:0] data2
);

    logic [31:0] registers [0:31];

    // Reads: combinational, x0 hardwired to zero
    always_comb begin
        data1 = (rs1 == 5'd0) ? 32'd0 : registers[rs1];
        data2 = (rs2 == 5'd0) ? 32'd0 : registers[rs2];
    end

    // Writes: NEGEDGE = the half-cycle write trick.
    // A write lands mid-cycle; an ID read in the second half sees fresh data.
    always_ff @(negedge clk) begin
        if (rst) begin
            for (int i = 0; i < 32; i++) registers[i] <= 32'd0;
        end else if (write_enable && rd != 5'd0) begin
            registers[rd] <= write_data;
        end
    end

endmodule