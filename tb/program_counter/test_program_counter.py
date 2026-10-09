
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_reset_and_increment(dut):

    # A clock is a repeating 0 -> 1 -> 0 signal.  One full cycle is 10 ns.
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Keep reset high for one rising edge.  The RTL must set PC to zero.
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert int(dut.pc.value) == 0, (
        f"PC should be 0 during reset, but was {int(dut.pc.value)}"
    )

    # With reset low, the PC must add 4 at every rising edge.
    dut.reset.value = 0
    for expected_pc in (4, 8, 12, 16):
        await RisingEdge(dut.clk)
        await Timer(1, unit="ns")

        actual_pc = int(dut.pc.value)
        assert actual_pc == expected_pc, (
            f"Expected PC = {expected_pc}, but got {actual_pc}"
        )
