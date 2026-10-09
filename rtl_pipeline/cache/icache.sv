`timescale 1ns/1ps
module icache #(
    parameter NUM_SETS=8, parameter NUM_WAYS=2, parameter LINE_WORDS=4
)(
    input  logic clk, rst_n,
    input  logic core_req,
    input  logic [31:0] core_addr,
    output logic core_stall,
    output logic [31:0] core_rdata,
    output logic core_rvalid,
    output logic [31:0] m_araddr, output logic m_arvalid, input logic m_arready,
    output logic [7:0]  m_arlen, output logic [2:0] m_arsize, output logic [1:0] m_arburst,
    input  logic [31:0] m_rdata, input logic m_rvalid, input logic m_rlast, input logic [1:0] m_rresp,
    output logic m_rready
);
    wire [23:0] req_tag   = core_addr[31:8];
    wire [3:0]  req_index = core_addr[7:4];
    wire [1:0]  req_word  = core_addr[3:2];
    wire [31:0] req_line  = {core_addr[31:4], 4'b0000};

    logic        valid_mem [NUM_SETS][NUM_WAYS];
    logic [23:0] tag_mem   [NUM_SETS][NUM_WAYS];
    logic [31:0] data_mem  [NUM_SETS][NUM_WAYS][LINE_WORDS];
    logic [2:0]  plru_mem  [NUM_SETS];

    integer s_init, w_init, i_init;
    initial begin
        for (s_init = 0; s_init < NUM_SETS; s_init = s_init + 1) begin
            plru_mem[s_init] = 3'd0;
            for (w_init = 0; w_init < NUM_WAYS; w_init = w_init + 1) begin
                valid_mem[s_init][w_init] = 1'b0;
                tag_mem[s_init][w_init]   = 24'd0;
                for (i_init = 0; i_init < LINE_WORDS; i_init = i_init + 1)
                    data_mem[s_init][w_init][i_init] = 32'd0;
            end
        end
    end

    logic [NUM_WAYS-1:0] hit_oh;
    for (genvar w=0; w<NUM_WAYS; w++)
        assign hit_oh[w] = valid_mem[req_index][w] && (tag_mem[req_index][w] == req_tag);
    wire hit = |hit_oh;
    logic [1:0] hit_way;
    always_comb begin hit_way=2'd0; for (int w=0;w<NUM_WAYS;w++) if (hit_oh[w]) hit_way=w[1:0]; end
    wire [31:0] hit_data = data_mem[req_index][hit_way][req_word];

    logic [1:0] victim_way;
    wire  [2:0] p_victim = plru_mem[req_index];
    assign victim_way = p_victim[2] ? (p_victim[0] ? 2'd3 : 2'd2)
                                    : (p_victim[1] ? 2'd1 : 2'd0);
    function automatic logic [2:0] plru_update(input logic [2:0] p, input logic [1:0] way);
        logic [2:0] n = p;
        case (way)
            2'd0: begin n[2]=1; n[1]=1; end
            2'd1: begin n[2]=1; n[1]=0; end
            2'd2: begin n[2]=0; n[0]=1; end
            2'd3: begin n[2]=0; n[0]=0; end
        endcase
        return n;
    endfunction

    typedef enum logic [1:0] {S_IDLE, S_FILL_AR, S_FILL_R, S_FILL_DONE} state_t;
    state_t state;
    logic [23:0] miss_tag_r;  logic [3:0] miss_index_r;  logic [1:0] miss_word_r;
    logic [31:0] miss_line_r;
    logic [1:0]  victim_r, fill_cnt;
    logic [31:0] fill_buf [LINE_WORDS];
    logic [31:0] core_rdata_r;  logic core_rvalid_r;

    wire read_miss = (state==S_IDLE) && core_req && !hit;
    assign core_stall = read_miss || (state != S_IDLE);
    assign core_rdata = core_rdata_r;  assign core_rvalid = core_rvalid_r;

    always_ff @(posedge clk) begin
        if (!rst_n) begin state <= S_IDLE; core_rvalid_r <= 0; fill_cnt <= 0; end
        else begin
            core_rvalid_r <= 1'b0;
            case (state)
                S_IDLE: begin
                    if (core_req && hit) begin
                        core_rdata_r <= hit_data;  core_rvalid_r <= 1'b1;
                        plru_mem[req_index] <= plru_update(plru_mem[req_index], hit_way);
                    end
                    else if (read_miss) begin
                        miss_tag_r <= req_tag;  miss_index_r <= req_index;
                        miss_word_r <= req_word; miss_line_r <= req_line;
                        victim_r <= victim_way;  fill_cnt <= 2'd0;
                        state <= S_FILL_AR;
                    end
                end
                S_FILL_AR: if (m_arready) state <= S_FILL_R;
                S_FILL_R: if (m_rvalid && m_rready) begin
                    fill_buf[fill_cnt] <= m_rdata;
                    if (m_rlast) state <= S_FILL_DONE; else fill_cnt <= fill_cnt + 2'd1;
                end
                S_FILL_DONE: begin
                    for (int i=0;i<LINE_WORDS;i++) data_mem[miss_index_r][victim_r][i] <= fill_buf[i];
                    tag_mem[miss_index_r][victim_r]   <= miss_tag_r;
                    valid_mem[miss_index_r][victim_r] <= 1'b1;
                    plru_mem[miss_index_r] <= plru_update(plru_mem[miss_index_r], victim_r);
                    core_rdata_r <= fill_buf[miss_word_r];  core_rvalid_r <= 1'b1;
                    state <= S_IDLE;
                end
            endcase
        end
    end

    assign m_araddr = miss_line_r;  assign m_arvalid = (state==S_FILL_AR);
    assign m_arlen = 8'd3;  assign m_arsize = 3'd2;  assign m_arburst = 2'b01;
    assign m_rready = (state==S_FILL_R);
endmodule
