`timescale 1ns/1ps

module tb_id;

    // ---------- 1. Clock & Reset ----------
    logic clk = 0;
    always #5 clk = ~clk;
    logic rst_n = 0;

    // ---------- 2. Wires: The "Daisy Chain" ----------
    // IF stage wires
    logic [31:0] pcF, pcplus4F, instrF;

    // IF/ID register wires (F -> D)
    logic [31:0] pcD, pcplus4D, instrD;

    // ID stage outputs (D -> going into ID/EX register)
    logic [31:0] pcD_out, pcplus4D_out;
    logic [31:0] rd1D, rd2D, immedD;
    logic [4:0]  rs1D, rs2D, rdD;
    logic [3:0]  alu_controlD;
    logic        alu_srcD, reg_writeD, mem_writeD, branchD, jumpD;
    logic [1:0]  result_srcD;
    logic [2:0]  branch_typeD;

    // ID/EX register wires (D -> E)
    logic [31:0] pcE, pcplus4E, rd1E, rd2E, immedE;
    logic [4:0]  rs1E, rs2E, rdE;
    logic [3:0]  alu_controlE;
    logic        alu_srcE, reg_writeE, mem_writeE, branchE, jumpE;
    logic [1:0]  result_srcE;
    logic [2:0]  branch_typeE;

    // ---------- 3. Instantiating the Chain ----------

    // 1. IF Stage
    if_stage u_if (
        .clk(clk), .rst_n(rst_n), .stall(1'b0),
        .pcF(pcF), .pcplus4F(pcplus4F)
    );

    // 2. Instruction Memory
    memory #(.WORDS(256), .mem_init("test_add_clean.hex")) u_imem (
        .clk(clk), .rst_n(rst_n),
        .address(pcF),
        .write_data(32'd0), .write_enable(1'b0), .byte_enable(4'b0),
        .read_data(instrF)
    );

    // 3. IF/ID Register
    if_id_reg u_if_id (
        .clk(clk), .rst_n(rst_n),
        .pcF(pcF), .pcplus4F(pcplus4F), .instrF(instrF),
        .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD)
    );

    // 4. ID Stage
    id_stage u_id (
        .clk(clk),
        .pcD(pcD), .pcplus4D(pcplus4D), .instrD(instrD),
        
        // Dummy WB signals (tied to 0 because WB stage doesn't exist yet!)
        .reg_writeW(1'b0), .rdW(5'b0), .wdW(32'b0),
        
        // Outputs to ID/EX register
        .pcD_out(pcD_out), .pcplus4D_out(pcplus4D_out),
        .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD),
        .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD),
        .alu_controlD(alu_controlD),
        .alu_srcD(alu_srcD), .reg_writeD(reg_writeD), .mem_writeD(mem_writeD),
        .result_srcD(result_srcD), .branchD(branchD), .jumpD(jumpD),
        .branch_typeD(branch_typeD)
    );

    // 5. ID/EX Register
    id_ex_reg u_id_ex (
        .clk(clk), .rst_n(rst_n),
        .pcD(pcD_out), .pcplus4D(pcplus4D_out),
        .rd1D(rd1D), .rd2D(rd2D), .immedD(immedD),
        .rs1D(rs1D), .rs2D(rs2D), .rdD(rdD),
        .alu_controlD(alu_controlD),
        .alu_srcD(alu_srcD), .reg_writeD(reg_writeD), .mem_writeD(mem_writeD),
        .result_srcD(result_srcD), .branchD(branchD), .jumpD(jumpD),
        .branch_typeD(branch_typeD),
        
        // Outputs (E stage)
        .pcE(pcE), .pcplus4E(pcplus4E),
        .rd1E(rd1E), .rd2E(rd2E), .immedE(immedE),
        .rs1E(rs1E), .rs2E(rs2E), .rdE(rdE),
        .alu_controlE(alu_controlE),
        .alu_srcE(alu_srcE), .reg_writeE(reg_writeE), .mem_writeE(mem_writeE),
        .result_srcE(result_srcE), .branchE(branchE), .jumpE(jumpE),
        .branch_typeE(branch_typeE)
    );

    // ---------- 4. Stimulus ----------
    initial begin
        rst_n = 0;
        repeat (2) @(posedge clk); // Hold reset
        rst_n = 1;                 // Release reset
        repeat (15) @(posedge clk);// Run for 15 cycles
        $finish;
    end

    // ---------- 5. Observation ----------
    // We print the instruction in ID (instrD) and the latched results in E
    always @(posedge clk) begin
        if (rst_n) begin
            $display("t=%0t | instrD=%h | E-Stage Latched: rs1=%d rs2=%d rd=%d imm=%h alu_ctrl=%h reg_write=%b",
                     $time, instrD, rs1E, rs2E, rdE, immedE, alu_controlE, reg_writeE);
        end
    end

endmodule