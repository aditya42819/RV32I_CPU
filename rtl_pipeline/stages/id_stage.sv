`timescale 1ns/1ps

module id_stage (
    input  logic        clk,            // needed ONLY because the regfile write port is clocked
     input logic       rst_n,   
    // Passengers arriving from the IF/ID register
    input  logic [31:0] pcD,
    input  logic [31:0] pcplus4D,
    input  logic [31:0] instrD,
    input  logic        reg_writeW,
    input  logic [4:0]  rdW,
    input  logic [31:0] wdW,

    // Passengers departing toward the ID/EX register
    output logic [31:0] pcD_out,
    output logic [31:0] pcplus4D_out,
    output logic [31:0] rd1D,
    output logic [31:0] rd2D,
    output logic [31:0] immedD,
    output logic [4:0]  rs1D,
    output logic [4:0]  rs2D,
    output logic [4:0]  rdD,
    output logic [3:0]  alu_controlD,
    output logic        alu_srcD,
    output logic        reg_writeD,
    output logic        mem_writeD,
    output logic [1:0]  result_srcD,
    output logic        branchD,
    output logic        jumpD,
    output logic [2:0]  branch_typeD
);

    // ---------- Section 1: Slice the instruction (pure wires) ----------
    logic [6:0] op;
    logic [4:0] rd, rs1, rs2;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign op     = instrD[6:0];
    assign rd     = instrD[11:7];
    assign funct3 = instrD[14:12];
    assign rs1    = instrD[19:15];
    assign rs2    = instrD[24:20];
    assign funct7 = instrD[31:25];

    // ---------- Section 2: Pass-throughs ----------
    // Passengers this stage does not process. They just cross the room.
    assign pcD_out      = pcD;
    assign pcplus4D_out = pcplus4D;
    assign rs1D         = rs1;
    assign rs2D         = rs2;
    assign rdD = reg_writeD ? rd : 5'd0;  

    // ---------- Section 3: Control unit ----------
    // imm_src is internal: produced here, consumed here by the extender.
    logic [2:0] imm_src;

    control u_control (                       // ADJUST port names to your control.sv
        .opcode          (op),
        .funct3      (funct3),
        .funct7      (funct7),
        .alu_control (alu_controlD),         // instance outputs drive module
        .alu_src     (alu_srcD),             // outputs directly: no temp wires
        .reg_write   (reg_writeD),
        .mem_write   (mem_writeD),
        .result_src  (result_srcD),
        .branch      (branchD),
        .jump        (jumpD),
        .branch_type (branch_typeD),
        .imm_source     (imm_src)
    );

    // ---------- Section 4: Immediate extension ----------
    signext u_ext (                           // ADJUST port names to your signext.sv
        .raw_src  (instrD [31:7]),
        .imm_source (imm_src),
        .immediate     (immedD)
    );

    // ---------- Section 5: Register file read ----------
        // ---------- Section 5: Register file read ----------
    regfile u_rf (                            
        .clk          (clk),
        .rst          (~rst_n),          
        .rs1          (rs1),           
        .rs2          (rs2),
        .rd           (rdW),           
        .write_data   (wdW),           
        .write_enable (reg_writeW),    
        .data1        (rd1D),         
        .data2        (rd2D)           
    );

endmodule