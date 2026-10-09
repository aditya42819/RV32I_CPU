`timescale 1ns/1ps
import cpu_package::*;

module control (
    input  logic [6:0] opcode,
    input  logic [2:0] funct3,
    input  logic [6:0] funct7,

    output logic [3:0] alu_control,
    output logic [2:0] imm_source,
    output logic       alu_src,
    output logic       reg_write,
    output logic       mem_write,
    output logic [1:0] result_src,
    output logic       branch,
    output logic       jump,
    output logic [2:0] branch_type
);


always_comb begin
    alu_control = ALU_ADD;
    imm_source  = IMM_I;
    alu_src     = ALU_SRC_REG;
    reg_write   = 1'b0;
    mem_write   = 1'b0;
    result_src  = WRITEBACK_ALU;
    branch      = 1'b0;
    jump        = 1'b0;
    branch_type = BR_BEQ;

    case (opcode)

        OPCODE_RTYPE: begin
            reg_write = 1'b1;

            case (funct3)
                3'b000: alu_control = funct7[5] ? ALU_SUB : ALU_ADD;
                3'b001: alu_control = ALU_SLL;
                3'b010: alu_control = ALU_SLT;
                3'b011: alu_control = ALU_SLTU;
                3'b100: alu_control = ALU_XOR;
                3'b101: alu_control = funct7[5] ? ALU_SRA : ALU_SRL;
                3'b110: alu_control = ALU_OR;
                3'b111: alu_control = ALU_AND;
                default: alu_control = ALU_ADD;
            endcase
        end

        OPCODE_ITYPE: begin
            reg_write  = 1'b1;
            alu_src    = ALU_SRC_IMM;
            imm_source = IMM_I;

            case (funct3)
                3'b000: alu_control = ALU_ADD;
                3'b001: alu_control = ALU_SLL;
                3'b010: alu_control = ALU_SLT;
                3'b011: alu_control = ALU_SLTU;
                3'b100: alu_control = ALU_XOR;
                3'b101: alu_control = funct7[5] ? ALU_SRA : ALU_SRL;
                3'b110: alu_control = ALU_OR;
                3'b111: alu_control = ALU_AND;
                default: alu_control = ALU_ADD;
            endcase
        end

        OPCODE_LOAD: begin
            alu_control = ALU_ADD;
            alu_src = ALU_SRC_IMM;
            imm_source = IMM_I;
            reg_write = 1'b1;
            result_src = WRITEBACK_MEMORY;
        end

        OPCODE_STORE: begin
            alu_control = ALU_ADD;
            alu_src = ALU_SRC_IMM;
            imm_source = IMM_S;
            mem_write = 1'b1;
        end

        OPCODE_BRANCH: begin
            alu_control = ALU_SUB;
            imm_source = IMM_B;
            branch = 1'b1;

            case (funct3)
                3'b000: branch_type = BR_BEQ;
                3'b001: branch_type = BR_BNE;
                3'b100: branch_type = BR_BLT;
                3'b101: branch_type = BR_BGE;
                3'b110: branch_type = BR_BLTU;
                3'b111: branch_type = BR_BGEU;
                default: branch_type = BR_BEQ;
            endcase
        end

        OPCODE_JAL: begin
            imm_source = IMM_J;
            reg_write = 1'b1;
            result_src = WRITEBACK_PC4;
            jump = 1'b1;
        end

        OPCODE_JALR: begin
            alu_control = ALU_ADD;
            alu_src = ALU_SRC_IMM;
            imm_source = IMM_I;
            reg_write = 1'b1;
            result_src = WRITEBACK_PC4;
            jump = 1'b1;
        end

        OPCODE_LUI: begin
            imm_source = IMM_U;
            reg_write = 1'b1;
            result_src = WRITEBACK_IMM;
        end

        OPCODE_AUIPC: begin
            alu_control = ALU_ADD;
            alu_src = ALU_SRC_IMM;
            imm_source = IMM_U;
            reg_write = 1'b1;
        end

        default: begin
            alu_control = ALU_ADD;
        end

    endcase
end

endmodule