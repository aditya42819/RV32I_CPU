import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_memory(dut):

    # Start the clock
    cocotb.start_soon(
        Clock(dut.clk, 10, unit="ns").start()
    )

    # Initial values
    dut.rst_n.value = 1
    dut.write_enable.value = 0
    dut.byte_enable.value = 0
    dut.address.value = 0
    dut.write_data.value = 0

    # ---------------------------------------------------------
    # TEST 1: WRITE A FULL 32-BIT WORD
    # ---------------------------------------------------------

    dut.address.value = 0
    dut.write_data.value = 0x12345678
    dut.byte_enable.value = 0b1111
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    dut.write_enable.value = 0

    # Read the same address
    dut.address.value = 0

    await Timer(1, unit="ns")

    assert dut.read_data.value.to_unsigned() == 0x12345678, \
        "Full word write/read failed"

    # ---------------------------------------------------------
    # TEST 2: WRITE TO A SECOND ADDRESS
    # ---------------------------------------------------------

    dut.address.value = 4
    dut.write_data.value = 0xABCDEF01
    dut.byte_enable.value = 0b1111
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    dut.write_enable.value = 0

    dut.address.value = 4

    await Timer(1, unit="ns")

    assert dut.read_data.value.to_unsigned() == 0xABCDEF01, \
        "Second memory location failed"

    # ---------------------------------------------------------
    # TEST 3: BYTE ENABLE
    # ---------------------------------------------------------
    # First write a known value
    # Then change only byte 0.

    dut.address.value = 8
    dut.write_data.value = 0x12345678
    dut.byte_enable.value = 0b1111
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    # Now change only the lowest byte
    dut.write_data.value = 0x000000AA
    dut.byte_enable.value = 0b0001

    await RisingEdge(dut.clk)

    dut.write_enable.value = 0
    dut.address.value = 8

    await Timer(1, unit="ns")

    assert dut.read_data.value.to_unsigned() == 0x123456AA, \
        "Byte enable 0 failed"

    # ---------------------------------------------------------
    # TEST 4: WRITE ONLY BYTE 1
    # ---------------------------------------------------------

    dut.write_data.value = 0x0000BB00
    dut.byte_enable.value = 0b0010
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    dut.write_enable.value = 0

    await Timer(1, unit="ns")

    assert dut.read_data.value.to_unsigned() == 0x1234BBAA, \
        "Byte enable 1 failed"

   