`timescale 1ns/1ps


module memory #(
    parameter int WORDS = 128,
    parameter string mem_init = ""
) (
    input logic        clk,
    input logic [31:0] address,
    input logic [31:0] write_data,
    input logic        write_enable,
    input logic        rst_n,
    input logic [3:0]  byte_enable,

    output logic [31:0] read_data
);

    logic [31:0] mem [0:WORDS-1];

    // MEMORY INITIALIZATION

    initial begin
        if (mem_init != "") begin
            $display("Loading memory from %s", mem_init);
            $readmemh(mem_init, mem);
        end
    end

    // WRITE LOGIC

    always_ff @(posedge clk) begin
        if (!rst_n) begin

        end

        else if (write_enable) begin
            if (address[1:0] != 2'b00) begin
                $fatal(1, "Misaligned write at address %h", address);
            end

            else begin

                if (byte_enable[0])
                    mem[address[31:2]][7:0] <= write_data[7:0];

                if (byte_enable[1])
                    mem[address[31:2]][15:8] <= write_data[15:8];

                if (byte_enable[2])
                    mem[address[31:2]][23:16] <= write_data[23:16];

                if (byte_enable[3])
                    mem[address[31:2]][31:24] <= write_data[31:24];

            end
        end
    end

    // READ LOGIC

    always_comb begin
        read_data = 32'h00000000;

        if (address[1:0] != 2'b00) begin
          //  $fatal(1, "Misaligned read at address %h", address); //add later
        end

        else begin
            read_data = mem[address[31:2]];
        end
    end

endmodule