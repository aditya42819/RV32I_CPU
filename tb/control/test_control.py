import cocotb
from cocotb.triggers import Timer


# RISC-V opcodes
OPCODE_RTYPE  = 0b0110011
OPCODE_ITYPE  = 0b0010011
OPCODE_LOAD   = 0b0000011
OPCODE_STORE  = 0b0100011
OPCODE_BRANCH = 0b1100011
OPCODE_JAL    = 0b1101111
OPCODE_JALR   = 0b1100111
OPCODE_LUI    = 0b0110111
OPCODE_AUIPC  = 0b0010111


# ALU operations
ALU_ADD  = 0
ALU_SUB  = 1
ALU_AND  = 2
ALU_OR   = 3
ALU_XOR  = 4
ALU_SLL  = 5
ALU_SRL  = 6
ALU_SRA  = 7
ALU_SLT  = 8
ALU_SLTU = 9


async def drive(dut, opcode, funct3=0, funct7=0):
    dut.opcode.value = opcode
    dut.funct3.value = funct3
    dut.funct7.value = funct7
    await Timer(1, units="ns")


@cocotb.test
async def test_control(dut):

    # ---------------------------------------------------------
    # ADD
    # ---------------------------------------------------------

    await drive(dut, OPCODE_RTYPE, 0b000, 0b0000000)

    assert dut.alu_control.value == ALU_ADD
    assert dut.reg_write.value == 1
    assert dut.mem_write.value == 0
    assert dut.alu_src.value == 0


    # ---------------------------------------------------------
    # SUB
    # ---------------------------------------------------------

    await drive(dut, OPCODE_RTYPE, 0b000, 0b0100000)

    assert dut.alu_control.value == ALU_SUB
    assert dut.reg_write.value == 1


    # ---------------------------------------------------------
    # AND
    # ---------------------------------------------------------

    await drive(dut, OPCODE_RTYPE, 0b111, 0)

    assert dut.alu_control.value == ALU_AND
    assert dut.reg_write.value == 1


    # ---------------------------------------------------------
    # OR
    # ---------------------------------------------------------

    await drive(dut, OPCODE_RTYPE, 0b110, 0)

    assert dut.alu_control.value == ALU_OR


    # ---------------------------------------------------------
    # XOR
    # ---------------------------------------------------------

    await drive(dut, OPCODE_RTYPE, 0b100, 0)

    assert dut.alu_control.value == ALU_XOR


    # ---------------------------------------------------------
    # ADDI
    # ---------------------------------------------------------

    await drive(dut, OPCODE_ITYPE, 0b000, 0)

    assert dut.alu_control.value == ALU_ADD
    assert dut.alu_src.value == 1
    assert dut.reg_write.value == 1
    assert dut.mem_write.value == 0


    # ---------------------------------------------------------
    # LW
    # ---------------------------------------------------------

    await drive(dut, OPCODE_LOAD, 0b010, 0)

    assert dut.alu_control.value == ALU_ADD
    assert dut.alu_src.value == 1
    assert dut.reg_write.value == 1
    assert dut.mem_write.value == 0
    assert dut.result_src.value == 1


    # ---------------------------------------------------------
    # SW
    # ---------------------------------------------------------

    await drive(dut, OPCODE_STORE, 0b010, 0)

    assert dut.alu_control.value == ALU_ADD
    assert dut.alu_src.value == 1
    assert dut.reg_write.value == 0
    assert dut.mem_write.value == 1


    # ---------------------------------------------------------
    # BEQ
    # ---------------------------------------------------------

    await drive(dut, OPCODE_BRANCH, 0b000, 0)

    assert dut.alu_control.value == ALU_SUB
    assert dut.alu_src.value == 0
    assert dut.branch.value == 1
    assert dut.reg_write.value == 0


    # ---------------------------------------------------------
    # BNE
    # ---------------------------------------------------------

    await drive(dut, OPCODE_BRANCH, 0b001, 0)

    assert dut.branch.value == 1
    assert dut.branch_type.value == 0b001


    # ---------------------------------------------------------
    # BLT
    # ---------------------------------------------------------

    await drive(dut, OPCODE_BRANCH, 0b100, 0)

    assert dut.branch_type.value == 0b100


    # ---------------------------------------------------------
    # JAL
    # ---------------------------------------------------------

    await drive(dut, OPCODE_JAL, 0, 0)

    assert dut.jump.value == 1
    assert dut.reg_write.value == 1
    assert dut.result_src.value == 2


    # ---------------------------------------------------------
    # JALR
    # ---------------------------------------------------------

    await drive(dut, OPCODE_JALR, 0, 0)

    assert dut.jump.value == 1
    assert dut.reg_write.value == 1
    assert dut.alu_src.value == 1


    # ---------------------------------------------------------
    # LUI
    # ---------------------------------------------------------

    await drive(dut, OPCODE_LUI, 0, 0)

    assert dut.reg_write.value == 1
    assert dut.result_src.value == 3


    # ---------------------------------------------------------
    # AUIPC
    # ---------------------------------------------------------

    await drive(dut, OPCODE_AUIPC, 0, 0)

    assert dut.reg_write.value == 1
    assert dut.alu_src.value == 1


    print("CONTROL TEST PASSED")