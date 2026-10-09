`timescale 1ns/1ps

import cpu_package::*;

module reader (
    input  logic [31:0] mem_data,
    input  logic [31:0] alu_result,
    input  logic [2:0]  funct3,

    output logic [31:0] read_data
);

logic [1:0] offset;
logic       sign_extend;

assign offset = alu_result[1:0];
assign sign_extend = ~funct3[2];

always_comb begin
    read_data = 32'b0;

    case (funct3)

        3'b000, 3'b100: begin // LB / LBU
            case (offset)
                2'b00: read_data = {{24{sign_extend & mem_data[7]}},  mem_data[7:0]};
                2'b01: read_data = {{24{sign_extend & mem_data[15]}}, mem_data[15:8]};
                2'b10: read_data = {{24{sign_extend & mem_data[23]}}, mem_data[23:16]};
                2'b11: read_data = {{24{sign_extend & mem_data[31]}}, mem_data[31:24]};
            endcase
        end

        3'b001, 3'b101: begin // LH / LHU
            case (offset)
                2'b00: read_data = {{16{sign_extend & mem_data[15]}}, mem_data[15:0]};
                2'b10: read_data = {{16{sign_extend & mem_data[31]}}, mem_data[31:16]};
                default: read_data = 32'b0;
            endcase
        end

        3'b010: begin // LW
            if (offset == 2'b00)
                read_data = mem_data;
        end

        default: begin
            read_data = 32'b0;
        end

    endcase
end

endmodule