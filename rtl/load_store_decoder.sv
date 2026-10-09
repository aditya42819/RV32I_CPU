`timescale 1ns/1ps

import cpu_package::*;

module load_store_decoder (
    input  logic [31:0] alu_result,
    input  logic [2:0]  funct3,
    input  logic [31:0] reg_read,

    output logic [31:0] data,
    output logic [3:0]  byte_enable
);

logic [1:0] offset;

assign offset = alu_result[1:0];

always_comb begin
    data = 32'b0;
    byte_enable = 4'b0000;

    case (funct3)

        3'b000: begin // SB
            case (offset)
                2'b00: begin
                    data = reg_read & 32'h000000FF;
                    byte_enable = 4'b0001;
                end
                2'b01: begin
                    data = (reg_read & 32'h000000FF) << 8;
                    byte_enable = 4'b0010;
                end
                2'b10: begin
                    data = (reg_read & 32'h000000FF) << 16;
                    byte_enable = 4'b0100;
                end
                2'b11: begin
                    data = (reg_read & 32'h000000FF) << 24;
                    byte_enable = 4'b1000;
                end
            endcase
        end

        3'b001: begin // SH
            case (offset)
                2'b00: begin
                    data = reg_read & 32'h0000FFFF;
                    byte_enable = 4'b0011;
                end
                2'b10: begin
                    data = (reg_read & 32'h0000FFFF) << 16;
                    byte_enable = 4'b1100;
                end
            endcase
        end

        3'b010: begin // SW
            if (offset == 2'b00) begin
                data = reg_read;
                byte_enable = 4'b1111;
            end
        end

        default: begin
            data = 32'b0;
            byte_enable = 4'b0000;
        end

    endcase
end

endmodule