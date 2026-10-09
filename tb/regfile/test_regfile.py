import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_regfile(dut):

    # Start clock
    cocotb.start_soon(
        Clock(dut.clk, 10, units="ns").start()
    )

    # RESET

    dut.rst.value = 1
    dut.write_enable.value = 0
    dut.rs1.value = 0
    dut.rs2.value = 0
    dut.rd.value = 0
    dut.write_data.value = 0

    # Wait for reset clock edge
    await RisingEdge(dut.clk)

    # Release reset
    dut.rst.value = 0

    # TEST x0

    dut.rs1.value = 0
    dut.rs2.value = 0

    await Timer(1, units="ns")

    assert dut.data1.value.integer == 0, "x0 read through rs1 is not zero"
    assert dut.data2.value.integer == 0, "x0 read through rs2 is not zero"

    dut.rd.value = 5
    dut.write_data.value = 123
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    dut.write_enable.value = 0

    # READ x5

    dut.rs1.value = 5

    await Timer(1, units="ns")

    assert dut.data1.value.integer == 123, "x5 does not contain 123"

    # TEST SECOND READ PORT
 

    dut.rs2.value = 5

    await Timer(1, units="ns")

    assert dut.data2.value.integer == 123, "x5 does not appear on rs2"

    # TRY TO WRITE x0 = 999
   

    dut.rd.value = 0
    dut.write_data.value = 999
    dut.write_enable.value = 1

    await RisingEdge(dut.clk)

    # Stop writing
    dut.write_enable.value = 0

    # Read x0
    dut.rs1.value = 0

    await Timer(1, units="ns")

    assert dut.data1.value.integer == 0, "x0 was modified"

    print("REGISTER FILE TEST PASSED")