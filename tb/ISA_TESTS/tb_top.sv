`timescale 1ns/1ps

module tb_top (
    input logic clk,
    input logic rst_n
);

    // Internal wires connecting CPU to Memories
    logic [31:0] instr_address;
    logic [31:0] instr_rdata;
    logic [31:0] data_address;
    logic [31:0] data_writedata;
    logic [31:0] data_rdata;
    logic        data_writeenable;
    logic [3:0]  data_byteenable;

    // 1. The CPU
    cpu u_cpu (
        .clk              (clk),
        .rst_n            (rst_n),
        .instr_address    (instr_address),
        .instr_rdata      (instr_rdata),
        .data_address     (data_address),
        .data_writedata   (data_writedata),
        .data_writeenable (data_writeenable),
        .data_byteenable  (data_byteenable),
        .data_rdata       (data_rdata)
    );

    // 2. Instruction Memory (Loads our compiled test program)
    memory #(
        .WORDS(256),
        .mem_init("test_rv32i_full_clean.hex") 
    ) u_imem (
        .clk          (clk),
        .rst_n        (rst_n),
        .address      (instr_address),
        .write_data   (32'd0),
        .write_enable (1'b0),
        .byte_enable  (4'b0000),
        .read_data    (instr_rdata)
    );

    // 3. Data Memory (Starts empty, CPU will write results here)
    memory #(
        .WORDS(256),
        .mem_init("") 
    ) u_dmem (
        .clk          (clk),
        .rst_n        (rst_n),
        .address      (data_address),
        .write_data   (data_writedata),
        .write_enable (data_writeenable),
        .byte_enable  (data_byteenable),
        .read_data    (data_rdata)
    );

    // Waveform dumping (Optional but highly recommended for debugging)
    initial begin
        // Create the folder if it doesn't exist: mkdir -p ../../sim/ISA_TESTS
        $dumpfile("../../sim/ISA_TESTS/cpu_wave.vcd");
        $dumpvars(0, tb_top);
    end

endmodule