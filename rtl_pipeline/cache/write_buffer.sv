`timescale 1ns/1ps
module write_buffer #(
    parameter DEPTH = 4
)(
    input  logic        clk, rst_n,
    input  logic        push,
    input  logic [31:0] push_addr,
    input  logic [31:0] push_data,
    input  logic [3:0]  push_strb,
    output logic        full,
    output logic        empty,
    output logic [31:0] m_awaddr,
    output logic        m_awvalid,
    input  logic        m_awready,
    output logic [31:0] m_wdata,
    output logic [3:0]  m_wstrb,
    output logic        m_wlast,
    output logic        m_wvalid,
    input  logic        m_wready,
    input  logic        m_bvalid,
    input  logic [1:0]  m_bresp,
    output logic        m_bready
);
    localparam PTR_W = 2;   // log2(4)
    localparam CNT_W = 3;   // log2(4)+1

    logic [31:0] addr_q [0:DEPTH-1];
    logic [31:0] data_q [0:DEPTH-1];
    logic [3:0]  strb_q [0:DEPTH-1];
    logic [PTR_W-1:0] wr_ptr, rd_ptr;
    logic [CNT_W-1:0] count;

    assign full  = (count == DEPTH);
    assign empty = (count == 0);

    assign m_awaddr  = addr_q[rd_ptr];
    assign m_awvalid = !empty;
    assign m_wdata   = data_q[rd_ptr];
    assign m_wstrb   = strb_q[rd_ptr];
    assign m_wlast   = 1'b1;
    assign m_wvalid  = !empty;
    assign m_bready  = 1'b1;

    wire do_push = push && !full;
    wire do_pop  = m_awready && m_wready && !empty;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            wr_ptr <= 0;
            rd_ptr <= 0;
            count  <= 0;
        end else begin
            if (do_push) begin
                addr_q[wr_ptr] <= push_addr;
                data_q[wr_ptr] <= push_data;
                strb_q[wr_ptr] <= push_strb;
                wr_ptr <= wr_ptr + 1'b1;
            end
            if (do_pop) rd_ptr <= rd_ptr + 1'b1;
            case ({do_push, do_pop})
                2'b10:   count <= count + 1'b1;
                2'b01:   count <= count - 1'b1;
                default: ;
            endcase
        end
    end
endmodule
