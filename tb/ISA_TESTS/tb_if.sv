`timescale 1ns/1ps

module tb_if;

    // ---------- 1. Clock & reset ----------
    logic clk = 0;
    always #5 clk = ~clk;

    logic rst_n = 0;

    // ---------- 2. Wires (now with F/D suffixes) ----------
    logic [31:0] pcF, pcplus4F, instrF;
    logic [31:0] pcD, pcplus4D, instrD;

    // ---------- 3. DUT: IF stage ----------
    if_stage u_if (
        .clk(clk), .rst_n(rst_n), .stall(1'b0),
        .pcF(pcF), .pcplus4F(pcplus4F)
    );

    // Instruction memory
    memory #(.WORDS(256), .mem_init("test_add_clean.hex")) u_imem (
        .clk(clk), .rst_n(rst_n),
        .address(pcF),
        .write_data(32'd0),
        .write_enable(1'b0),
        .byte_enable(4'b0),
        .read_data(instrF)
    );

    // Pipeline register: IF → ID
    if_id_reg u_bridge (
        .clk(clk), .rst_n(rst_n),
        .pcF(pcF), .pcplus4F(pcplus4F), .instrF(instrF),
        .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD)
    );

    // ---------- 4. Stimulus ----------
    initial begin
        rst_n = 0;
        repeat (2) @(posedge clk);
        rst_n = 1;
        repeat (10) @(posedge clk);
        $finish;
    end

    // ---------- 5. Observation ----------
    always @(posedge clk)
        $display("t=%0t | pcF=%h imem=%h || IF/ID: pcD=%h instrD=%h",
                 $time, pcF, instrF, pcD, instrD);

endmodule