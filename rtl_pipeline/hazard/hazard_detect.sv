`timescale 1ns/1ps

module hazard_detect (
    input  logic [4:0] rs1D,
    input  logic [4:0] rs2D,
    input  logic [4:0] rdE,
    input  logic       reg_writeE,
    input  logic       is_loadE,
    output logic       stallF,
    output logic       flushE
);
    logic load_use;
    assign load_use = reg_writeE && is_loadE && (rdE != 5'd0)
                      && ((rdE == rs1D) || (rdE == rs2D));
    assign stallF = load_use;
    assign flushE = load_use;
endmodule