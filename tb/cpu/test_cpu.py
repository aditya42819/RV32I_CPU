import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


async def reset(dut):
    dut.rst_n.value = 0

    for _ in range(2):
        await RisingEdge(dut.clk)

    dut.rst_n.value = 1


@cocotb.test()
async def test_rv32i_cpu_integration(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    await reset(dut)

    for _ in range(15):
        await RisingEdge(dut.clk)

    await Timer(1, unit="ns")

    registers = dut.u_cpu.u_regfile.registers

    assert int(registers[3].value) == 0x00000080
    assert int(registers[5].value) == 0x00000123
    assert int(registers[8].value) == 30
    assert int(registers[9].value) == 30
    assert int(registers[10].value) == 2

    data_memory = dut.u_dmem.mem

    assert int(data_memory[16].value) == 0x01238000
    assert int(data_memory[17].value) == 30