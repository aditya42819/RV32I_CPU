`timescale 1ns/1ps

module cpu_harness (
    input logic clk,
    input logic rst_n
);

    logic [31:0] instr_address;
    logic [31:0] instr_rdata;

    logic [31:0] data_address;
    logic [31:0] data_writedata;
    logic [31:0] data_rdata;
    logic        data_writeenable;
    logic [3:0]  data_byteenable;

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

    memory #(
        .WORDS(64),
        .mem_init("test_imemory.hex")
    ) u_imem (
        .clk          (clk),
        .rst_n        (rst_n),
        .address      (instr_address),
        .write_data   (32'd0),
        .write_enable (1'b0),
        .byte_enable  (4'b0000),
        .read_data    (instr_rdata)
    );

    memory #(
        .WORDS(64),
        .mem_init("test_dmemory.hex")
    ) u_dmem (
        .clk          (clk),
        .rst_n        (rst_n),
        .address      (data_address),
        .write_data   (data_writedata),
        .write_enable (data_writeenable),
        .byte_enable  (data_byteenable),
        .read_data    (data_rdata)
    );

    initial begin
        $dumpfile("../../sim/cpu/cpu_wave.vcd");
        $dumpvars(0, cpu_harness);
    end

endmodule