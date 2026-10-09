import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test_alu(dut):

    # ---------------------------------------------------------
    # ADD
    # ---------------------------------------------------------

    dut.src1.value = 10
    dut.src2.value = 5
    dut.alu_control.value = 0b0000

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 15
    assert dut.zero.value == 0
    assert dut.last_bit.value == 1

    # ---------------------------------------------------------
    # SUB
    # ---------------------------------------------------------

    dut.src1.value = 10
    dut.src2.value = 5
    dut.alu_control.value = 0b0001

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 5
    assert dut.zero.value == 0
    assert dut.last_bit.value == 1

    # ---------------------------------------------------------
    # AND
    # ---------------------------------------------------------

    dut.src1.value = 0b1010
    dut.src2.value = 0b1100
    dut.alu_control.value = 0b0010

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0b1000

    # ---------------------------------------------------------
    # OR
    # ---------------------------------------------------------

    dut.src1.value = 0b1010
    dut.src2.value = 0b1100
    dut.alu_control.value = 0b0011

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0b1110

    # ---------------------------------------------------------
    # XOR
    # ---------------------------------------------------------

    dut.src1.value = 0b1010
    dut.src2.value = 0b1100
    dut.alu_control.value = 0b0100

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0b0110

    # ---------------------------------------------------------
    # SLL
    # ---------------------------------------------------------

    dut.src1.value = 5
    dut.src2.value = 2
    dut.alu_control.value = 0b0101

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 20

    # ---------------------------------------------------------
    # SRL
    # ---------------------------------------------------------

    dut.src1.value = 20
    dut.src2.value = 2
    dut.alu_control.value = 0b0110

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 5

    # ---------------------------------------------------------
    # SRA
    # ---------------------------------------------------------

    # -16 >> 2 = -4
    dut.src1.value = 0xFFFFFFF0
    dut.src2.value = 2
    dut.alu_control.value = 0b0111

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0xFFFFFFFC

    # ---------------------------------------------------------
    # SLT - SIGNED
    # ---------------------------------------------------------

    # -5 < 3 → true
    dut.src1.value = 0xFFFFFFFB
    dut.src2.value = 3
    dut.alu_control.value = 0b1000

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 1

    # ---------------------------------------------------------
    # SLTU - UNSIGNED
    # ---------------------------------------------------------

    # 0xFFFFFFFF < 3 → false
    dut.src1.value = 0xFFFFFFFF
    dut.src2.value = 3
    dut.alu_control.value = 0b1001

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0

    # ---------------------------------------------------------
    # ZERO FLAG
    # ---------------------------------------------------------

    dut.src1.value = 10
    dut.src2.value = 10
    dut.alu_control.value = 0b0001

    await Timer(1, unit="ns")

    assert dut.alu_result.value.to_unsigned() == 0
    assert dut.zero.value == 1

    # ---------------------------------------------------------
    # LAST BIT
    # ---------------------------------------------------------

    dut.src1.value = 6
    dut.src2.value = 5
    dut.alu_control.value = 0b0000

    await Timer(1, unit="ns")

    # 6 + 5 = 11 = ...1011
    assert dut.alu_result.value.to_unsigned() == 11
    assert dut.last_bit.value == 1

    print("ALU TEST PASSED")