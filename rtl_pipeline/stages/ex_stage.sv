`timescale 1ns/1ps
import cpu_package::*;

module ex_stage (
    input  logic [31:0] pcE,
    input  logic [31:0] rd1E,
    input  logic [31:0] rd2E,
    input  logic [31:0] immedE,
    input  logic [3:0]  alu_controlE,
    input  logic        alu_srcE,
    input  logic        branchE,
    input  logic        jumpE,
    input  logic [2:0]  branch_typeE,
    input  logic [31:0] wdM,
    input  logic [31:0] wdW,
    input  logic [1:0]  forwardAE,
    input  logic [1:0]  forwardBE,
    input  logic [4:0]  rdE,
    input  logic [31:0] pcplus4E,
    input  logic        mem_writeE,
    input  logic        reg_writeE,
    input  logic [1:0]  result_srcE,
    output logic [31:0] alu_resultE,
    output logic [31:0] pc_targetE,
    output logic        pc_srcE,
    output logic [31:0] writeDataE,
    output logic [4:0]  rdE_out,
    output logic [31:0] immE_out,
    output logic [31:0] pcplus4E_out,
    output logic        mem_writeE_out,
    output logic        reg_writeE_out,
    output logic [1:0]  result_srcE_out
);

    logic [31:0] srcA, srcB_fwd, srcB;

    always_comb begin
        case (forwardAE)
            2'b10:   srcA = wdM;
            2'b01:   srcA = wdW;
            default: srcA = rd1E;
        endcase
    end

    always_comb begin
        case (forwardBE)
            2'b10:   srcB_fwd = wdM;
            2'b01:   srcB_fwd = wdW;
            default: srcB_fwd = rd2E;
        endcase
    end

    assign srcB = alu_srcE ? immedE : srcB_fwd;

    logic zeroE, last_bitE;
    alu u_alu (
        .alu_control (alu_controlE),
        .src1        (srcA),
        .src2        (srcB),
        .alu_result  (alu_resultE),
        .zero        (zeroE),
        .last_bit    (last_bitE)
    );

    logic branch_taken;
    always_comb begin
        case (branch_typeE)
            BR_BEQ:  branch_taken = (srcA == srcB_fwd);
            BR_BNE:  branch_taken = (srcA != srcB_fwd);
            BR_BLT:  branch_taken = ($signed(srcA) <  $signed(srcB_fwd));
            BR_BGE:  branch_taken = ($signed(srcA) >= $signed(srcB_fwd));
            BR_BLTU: branch_taken = (srcA <  srcB_fwd);
            BR_BGEU: branch_taken = (srcA >= srcB_fwd);
            default: branch_taken = 1'b0;
        endcase
    end

    logic jalrE;
    assign jalrE      = jumpE & alu_srcE;
    assign pc_targetE = jalrE ? (srcA + immedE) : (pcE + immedE);

    assign pc_srcE = jumpE | (branchE & branch_taken);

    // Store data: same forwarding decision as operand B
    always_comb begin
        case (forwardBE)
            2'b10:   writeDataE = wdM;
            2'b01:   writeDataE = wdW;
            default: writeDataE = rd2E;
        endcase
    end

    assign rdE_out         = rdE;
    assign pcplus4E_out    = pcplus4E;
    assign mem_writeE_out  = mem_writeE;
    assign reg_writeE_out  = reg_writeE;
    assign result_srcE_out = result_srcE;
    assign immE_out        = immedE;

endmodule