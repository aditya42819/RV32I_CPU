`timescale 1ns/1ps
module dcache #(
    parameter NUM_SETS   = 16,
    parameter NUM_WAYS   = 4,
    parameter LINE_WORDS = 4
)(
    input  logic        clk, rst_n,
    input  logic        core_req,
    input  logic        core_write,
    input  logic [31:0] core_addr,
    input  logic [31:0] core_wdata,
    input  logic [3:0]  core_wstrb,
    output logic        core_stall,
    output logic [31:0] core_rdata,
    output logic        core_rvalid,
    // AXI read (fills)
    output logic [31:0] m_araddr, output logic m_arvalid, input logic m_arready,
    output logic [7:0]  m_arlen, output logic [2:0] m_arsize, output logic [1:0] m_arburst,
    input  logic [31:0] m_rdata, input logic m_rvalid, input logic m_rlast, input logic [1:0] m_rresp,
    output logic        m_rready,
    // AXI write (write-buffer drain)
    output logic [31:0] m_awaddr, output logic m_awvalid, input logic m_awready,
    output logic [31:0] m_wdata, output logic [3:0] m_wstrb, output logic m_wlast,
    output logic m_wvalid, input logic m_wready,
    input  logic m_bvalid, input logic [1:0] m_bresp, output logic m_bready
);

    // ---- address decode ----
    wire [23:0] req_tag   = core_addr[31:8];
    wire [3:0]  req_index = core_addr[7:4];
    wire [1:0]  req_word  = core_addr[3:2];
    wire [31:0] req_line  = {core_addr[31:4], 4'b0000};

    // ---- main cache storage ----
    logic        valid_mem [NUM_SETS][NUM_WAYS];
    logic        dirty_mem [NUM_SETS][NUM_WAYS];
    logic [23:0] tag_mem   [NUM_SETS][NUM_WAYS];
    logic [31:0] data_mem  [NUM_SETS][NUM_WAYS][LINE_WORDS];
    logic [2:0]  plru_mem  [NUM_SETS];

    integer s_i, w_i, d_i;
    initial begin
        for (s_i = 0; s_i < NUM_SETS; s_i = s_i + 1) begin
            plru_mem[s_i] = 3'd0;
            for (w_i = 0; w_i < NUM_WAYS; w_i = w_i + 1) begin
                valid_mem[s_i][w_i] = 1'b0;
                dirty_mem[s_i][w_i] = 1'b0;
                tag_mem[s_i][w_i]   = 24'd0;
                for (d_i = 0; d_i < LINE_WORDS; d_i = d_i + 1)
                    data_mem[s_i][w_i][d_i] = 32'd0;
            end
        end
    end

    // ---- hit detection ----
    logic [NUM_WAYS-1:0] hit_oh;
    for (genvar g = 0; g < NUM_WAYS; g++)
        assign hit_oh[g] = valid_mem[req_index][g] && (tag_mem[req_index][g] == req_tag);
    wire hit = |hit_oh;
    logic [1:0] hit_way;
    always_comb begin hit_way = 2'd0; for (int w = 0; w < NUM_WAYS; w++) if (hit_oh[w]) hit_way = w[1:0]; end
    wire [31:0] hit_data = data_mem[req_index][hit_way][req_word];

    // ---- PLRU ----
    logic [1:0] victim_way;
    wire  [2:0] p_vic = plru_mem[req_index];
    assign victim_way = p_vic[2] ? (p_vic[0] ? 2'd3 : 2'd2)
                                 : (p_vic[1] ? 2'd1 : 2'd0);
    function automatic logic [2:0] plru_upd(input logic [2:0] p, input logic [1:0] way);
        logic [2:0] n = p;
        case (way)
            2'd0: begin n[2]=1; n[1]=1; end
            2'd1: begin n[2]=1; n[1]=0; end
            2'd2: begin n[2]=0; n[0]=1; end
            2'd3: begin n[2]=0; n[0]=0; end
        endcase
        return n;
    endfunction

    // ---- write buffer ----
    logic        wb_push, wb_full, wb_empty;
    logic [31:0] wb_push_addr, wb_push_data;
    logic [3:0]  wb_push_strb;

    write_buffer #(.DEPTH(16)) u_wbuf (
        .clk(clk), .rst_n(rst_n),
        .push(wb_push), .push_addr(wb_push_addr), .push_data(wb_push_data), .push_strb(wb_push_strb),
        .full(wb_full), .empty(wb_empty),
        .m_awaddr(m_awaddr), .m_awvalid(m_awvalid), .m_awready(m_awready),
        .m_wdata(m_wdata), .m_wstrb(m_wstrb), .m_wlast(m_wlast),
        .m_wvalid(m_wvalid), .m_wready(m_wready),
        .m_bvalid(m_bvalid), .m_bresp(m_bresp), .m_bready(m_bready)
    );

    // ---- victim cache ----
    logic         vc_push, vc_hit;
    logic [1:0]   vc_hit_idx;
    logic [127:0] vc_hit_line;
    logic [23:0]  vc_push_tag;
    logic [127:0] vc_push_line;

    victim_cache #(.DEPTH(4), .TAG_W(24)) u_vc (
        .clk(clk), .rst_n(rst_n),
        .lookup_tag(req_tag), .hit(vc_hit), .hit_idx(vc_hit_idx), .hit_line(vc_hit_line),
        .push(vc_push), .push_tag(vc_push_tag), .push_line(vc_push_line)
    );

    // ---- FSM ----
    typedef enum logic [2:0] {S_IDLE, S_WB_PUSH, S_VC_PUSH, S_FILL_AR, S_FILL_R, S_FILL_DONE} st_t;
    st_t state;

    logic [23:0] miss_tag_r, evict_tag_r;
    logic [3:0]  miss_index_r, evict_index_r;
    logic [1:0]  miss_word_r, evict_way_r, victim_r;
    logic [31:0] miss_line_r;
    logic [1:0]  wb_cnt, fill_cnt;
    logic [31:0] fill_buf [0:3];
    logic [31:0] evict_data_r [0:3];
    logic [31:0] core_rdata_r;
    logic        core_rvalid_r, miss_from_vc;

    // ---- request classification ----
    wire load_req  = core_req && !core_write;
    wire store_req = core_req &&  core_write;
    wire load_miss = (state == S_IDLE) && load_req && !hit;
    wire store_miss = (state == S_IDLE) && store_req && !hit;
    wire store_hit = (state == S_IDLE) && store_req && hit;

    // ---- stall logic ----
    assign core_stall = load_miss || (state != S_IDLE) || (store_miss && wb_full);
    assign core_rdata  = core_rdata_r;
    assign core_rvalid = core_rvalid_r;

    // ---- write-buffer push mux ----
    wire wb_push_evict = (state == S_WB_PUSH) && !wb_full;
    wire wb_push_store = (state == S_IDLE) && store_miss && !wb_full;
    assign wb_push      = wb_push_evict || wb_push_store;
    assign wb_push_addr = wb_push_evict ? {evict_tag_r, evict_index_r, wb_cnt, 2'b00} : core_addr;
    assign wb_push_data = wb_push_evict ? evict_data_r[wb_cnt] : core_wdata;
    assign wb_push_strb = wb_push_evict ? 4'hF : core_wstrb;

    // ---- victim-cache push ----
    assign vc_push      = (state == S_VC_PUSH);
    assign vc_push_tag  = evict_tag_r;
    assign vc_push_line = {evict_data_r[3], evict_data_r[2], evict_data_r[1], evict_data_r[0]};

    // ---- main FSM ----
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state <= S_IDLE; core_rvalid_r <= 1'b0; fill_cnt <= 0; wb_cnt <= 0;
        end else begin
            core_rvalid_r <= 1'b0;

            case (state)
                // ============================================================
                S_IDLE: begin
                    // -- load hit --
                    if (core_req && !core_write && hit) begin
                        core_rdata_r  <= hit_data;
                        core_rvalid_r <= 1'b1;
                        plru_mem[req_index] <= plru_upd(plru_mem[req_index], hit_way);
                    end
                    // -- store hit --
                    else if (store_hit) begin
                        for (int b = 0; b < 4; b++)
                            if (core_wstrb[b])
                                data_mem[req_index][hit_way][req_word][8*b +: 8] <= core_wdata[8*b +: 8];
                        dirty_mem[req_index][hit_way] <= 1'b1;
                        plru_mem[req_index] <= plru_upd(plru_mem[req_index], hit_way);
                    end
                    // -- miss (load or store-miss with allocate not needed) --
                    else if (load_miss) begin
                        // latch miss info
                        miss_tag_r   <= req_tag;
                        miss_index_r <= req_index;
                        miss_word_r  <= req_word;
                        miss_line_r  <= req_line;
                        victim_r     <= victim_way;
                        fill_cnt     <= 2'd0;
                        miss_from_vc <= vc_hit;
                        // latch eviction info
                        evict_tag_r   <= tag_mem[req_index][victim_way];
                        evict_index_r <= req_index;
                        evict_way_r   <= victim_way;
                        evict_data_r[0] <= data_mem[req_index][victim_way][0];
                        evict_data_r[1] <= data_mem[req_index][victim_way][1];
                        evict_data_r[2] <= data_mem[req_index][victim_way][2];
                        evict_data_r[3] <= data_mem[req_index][victim_way][3];
                        // decide first state
                        if (!valid_mem[req_index][victim_way])
                            state <= S_FILL_AR;                        // empty way: just fill
                        else if (dirty_mem[req_index][victim_way]) begin
                            state <= S_WB_PUSH; wb_cnt <= 2'd0;       // dirty: writeback first
                        end else
                            state <= S_VC_PUSH;                        // clean: move to VC
                    end
                    // store_miss (no-write-allocate): handled by wb_push_store combinationally
                end

                // ============================================================
                S_WB_PUSH: begin
                    if (!wb_full) begin
                        if (wb_cnt == 2'd3) state <= S_VC_PUSH;
                        wb_cnt <= wb_cnt + 2'd1;
                    end
                end

                // ============================================================
                S_VC_PUSH: begin
                    // evicted line goes to victim cache (always clean here)
                    if (miss_from_vc) begin
                        // VC hit: install VC line into main cache, return data
                        data_mem[miss_index_r][victim_r][0] <= vc_hit_line[31:0];
                        data_mem[miss_index_r][victim_r][1] <= vc_hit_line[63:32];
                        data_mem[miss_index_r][victim_r][2] <= vc_hit_line[95:64];
                        data_mem[miss_index_r][victim_r][3] <= vc_hit_line[127:96];
                        tag_mem[miss_index_r][victim_r]   <= miss_tag_r;
                        valid_mem[miss_index_r][victim_r] <= 1'b1;
                        dirty_mem[miss_index_r][victim_r] <= 1'b0;
                        plru_mem[miss_index_r] <= plru_upd(plru_mem[miss_index_r], victim_r);
                        // return the requested word
                        case (miss_word_r)
                            2'd0: core_rdata_r <= vc_hit_line[31:0];
                            2'd1: core_rdata_r <= vc_hit_line[63:32];
                            2'd2: core_rdata_r <= vc_hit_line[95:64];
                            2'd3: core_rdata_r <= vc_hit_line[127:96];
                        endcase
                        core_rvalid_r <= 1'b1;
                        state <= S_IDLE;
                    end else begin
                        // VC miss: go fill from memory
                        state <= S_FILL_AR;
                    end
                end

                // ============================================================
                S_FILL_AR: if (m_arready) state <= S_FILL_R;

                // ============================================================
                S_FILL_R: if (m_rvalid && m_rready) begin
                    fill_buf[fill_cnt] <= m_rdata;
                    if (m_rlast) state <= S_FILL_DONE;
                    else         fill_cnt <= fill_cnt + 2'd1;
                end

                // ============================================================
                S_FILL_DONE: begin
                    data_mem[miss_index_r][victim_r][0] <= fill_buf[0];
                    data_mem[miss_index_r][victim_r][1] <= fill_buf[1];
                    data_mem[miss_index_r][victim_r][2] <= fill_buf[2];
                    data_mem[miss_index_r][victim_r][3] <= fill_buf[3];
                    tag_mem[miss_index_r][victim_r]   <= miss_tag_r;
                    valid_mem[miss_index_r][victim_r] <= 1'b1;
                    dirty_mem[miss_index_r][victim_r] <= 1'b0;
                    plru_mem[miss_index_r] <= plru_upd(plru_mem[miss_index_r], victim_r);
                    core_rdata_r  <= fill_buf[miss_word_r];
                    core_rvalid_r <= 1'b1;
                    state <= S_IDLE;
                end
            endcase
        end
    end

    // ---- AXI read channel ----
    assign m_araddr  = miss_line_r;
    assign m_arvalid = (state == S_FILL_AR);
    assign m_arlen   = 8'd3;
    assign m_arsize  = 3'd2;
    assign m_arburst = 2'b01;
    assign m_rready  = (state == S_FILL_R);
endmodule