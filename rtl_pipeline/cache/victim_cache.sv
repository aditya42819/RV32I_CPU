`timescale 1ns/1ps
module victim_cache #(
    parameter DEPTH = 2,
    parameter TAG_W = 24
)(
    input  logic                 clk, rst_n,
    input  logic [TAG_W-1:0]     lookup_tag,
    output logic                 hit,
    output logic [1:0]           hit_idx,
    output logic [127:0]         hit_line,
    input  logic                 push,
    input  logic [TAG_W-1:0]     push_tag,
    input  logic [127:0]         push_line
);
    localparam PTR_W = $clog2(DEPTH);

    logic             valid [0:DEPTH-1];
    logic [TAG_W-1:0] tag   [0:DEPTH-1];
    logic [127:0]     line  [0:DEPTH-1];
    logic [PTR_W-1:0] fifo_ptr;

    always_comb begin
        hit     = 1'b0;
        hit_idx = 2'd0;
        for (int i = 0; i < DEPTH; i++)
            if (valid[i] && tag[i] == lookup_tag) begin
                hit     = 1'b1;
                hit_idx = i[1:0];
            end
    end
    assign hit_line = line[hit_idx];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int i = 0; i < DEPTH; i++) begin
                valid[i] <= 1'b0;
                tag[i]   <= 24'd0;
                line[i]  <= 128'd0;
            end
            fifo_ptr <= 0;
        end else if (push) begin
            valid[fifo_ptr] <= 1'b1;
            tag[fifo_ptr]   <= push_tag;
            line[fifo_ptr]  <= push_line;
            fifo_ptr        <= fifo_ptr + 1'b1;
        end
    end
endmodule
