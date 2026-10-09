import cocotb
from cocotb.triggers import Timer


async def drive(dut, mem_data, alu_result, funct3):
    dut.mem_data.value = mem_data
    dut.alu_result.value = alu_result
    dut.funct3.value = funct3
    await Timer(1, units="ns")


@cocotb.test
async def test_reader(dut):

    # -------------------------
    # LB - signed byte
    # -------------------------

    # Byte 0 = 0x80 -> sign extend
    await drive(dut, 0x12345680, 0x1000, 0b000)
    assert dut.read_data.value.to_unsigned() == 0xFFFFFF80

    # Byte 1 = 0x80 -> sign extend
    await drive(dut, 0x12348000, 0x1001, 0b000)
    assert dut.read_data.value.to_unsigned() == 0xFFFFFF80

    # -------------------------
    # LBU - unsigned byte
    # -------------------------

    await drive(dut, 0x12345680, 0x1000, 0b100)
    assert dut.read_data.value.to_unsigned() == 0x00000080

    # -------------------------
    # LH - signed halfword
    # -------------------------

    # Lower half = 0x8000
    await drive(dut, 0x12348000, 0x1000, 0b001)
    assert dut.read_data.value.to_unsigned() == 0xFFFF8000

    # Upper half = 0x8000
    await drive(dut, 0x80001234, 0x1002, 0b001)
    assert dut.read_data.value.to_unsigned() == 0xFFFF8000

    # -------------------------
    # LHU - unsigned halfword
    # -------------------------

    await drive(dut, 0x12348000, 0x1000, 0b101)
    assert dut.read_data.value.to_unsigned() == 0x00008000

    await drive(dut, 0x80001234, 0x1002, 0b101)
    assert dut.read_data.value.to_unsigned() == 0x00008000

    # -------------------------
    # LW
    # -------------------------

    await drive(dut, 0x12345678, 0x1000, 0b010)
    assert dut.read_data.value.to_unsigned() == 0x12345678

    # -------------------------
    # Misaligned accesses
    # -------------------------

    # Misaligned LH
    await drive(dut, 0x12345678, 0x1001, 0b001)
    assert dut.read_data.value.to_unsigned() == 0

    # Misaligned LHU
    await drive(dut, 0x12345678, 0x1003, 0b101)
    assert dut.read_data.value.to_unsigned() == 0

    # Misaligned LW
    await drive(dut, 0x12345678, 0x1001, 0b010)
    assert dut.read_data.value.to_unsigned() == 0

    print("READER TEST PASSED")
    