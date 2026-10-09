import cocotb
from cocotb.triggers import Timer


async def drive(dut, alu_result, funct3, reg_read):
    dut.alu_result.value = alu_result
    dut.funct3.value = funct3
    dut.reg_read.value = reg_read
    await Timer(1, units="ns")


@cocotb.test
async def test_load_store_decoder(dut):

    # SB at offset 0
    await drive(dut, 0x1000, 0b000, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x00000078
    assert dut.byte_enable.value.to_unsigned() == 0b0001

    # SB at offset 1
    await drive(dut, 0x1001, 0b000, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x00007800
    assert dut.byte_enable.value.to_unsigned() == 0b0010

    # SB at offset 2
    await drive(dut, 0x1002, 0b000, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x00780000
    assert dut.byte_enable.value.to_unsigned() == 0b0100

    # SB at offset 3
    await drive(dut, 0x1003, 0b000, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x78000000
    assert dut.byte_enable.value.to_unsigned() == 0b1000

    # SH at offset 0
    await drive(dut, 0x1000, 0b001, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x00005678
    assert dut.byte_enable.value.to_unsigned() == 0b0011

    # SH at offset 2
    await drive(dut, 0x1002, 0b001, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x56780000
    assert dut.byte_enable.value.to_unsigned() == 0b1100

    # Misaligned SH
    await drive(dut, 0x1001, 0b001, 0x12345678)
    assert dut.byte_enable.value.to_unsigned() == 0

    # LW / SW at offset 0
    await drive(dut, 0x1000, 0b010, 0x12345678)
    assert dut.data.value.to_unsigned() == 0x12345678
    assert dut.byte_enable.value.to_unsigned() == 0b1111

    # Misaligned LW / SW
    await drive(dut, 0x1001, 0b010, 0x12345678)
    assert dut.byte_enable.value.to_unsigned() == 0

    print("LOAD/STORE DECODER TEST PASSED")