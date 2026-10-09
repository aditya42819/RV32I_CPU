`timescale 1ns/1ps
module if_id_reg (
    input  logic        clk, rst_n, flush, stall,
    input  logic [31:0] pcF, pcplus4F, instrF,
    output logic [31:0] pcD, pcplus4D, instrD
);
    always_ff @(posedge clk) begin
        if (!rst_n || flush) begin
            pcD <= 32'd0; 
             pcplus4D <= 32'd4;  
             instrD <= 32'd0;
        end else if (!stall) begin
            pcD <= pcF;   
             pcplus4D <= pcplus4F; 
              instrD <= instrF;
        end
        // stall: hold
    end
endmodule