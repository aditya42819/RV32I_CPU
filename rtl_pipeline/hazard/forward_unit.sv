`timescale 1ns/1ps
module forward_unit (
    input  logic [4:0] rs1E, rs2E, rdM, rdW,
    input  logic       reg_writeM, reg_writeW, is_loadM,
    output logic [1:0] forwardAE, forwardBE
);
    always_comb begin
        if      (reg_writeM && !is_loadM && (rdM!=5'd0) && (rdM==rs1E)) forwardAE = 2'b10;
        else if (reg_writeW && (rdW!=5'd0) && (rdW==rs1E))              forwardAE = 2'b01;
        else                                                            forwardAE = 2'b00;
    end
    always_comb begin
        if      (reg_writeM && !is_loadM && (rdM!=5'd0) && (rdM==rs2E)) forwardBE = 2'b10;
        else if (reg_writeW && (rdW!=5'd0) && (rdW==rs2E))              forwardBE = 2'b01;
        else                                                            forwardBE = 2'b00;
    end
endmodule