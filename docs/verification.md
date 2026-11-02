# Verification notes

This project has verification material from more than one development stage. Keep the single-cycle tests, pipeline testbench, and later directed waveform run distinct: they use different testbenches and different CPU variants.

## 1. Single-cycle integration check

The Cocotb setup in `tb/cpu/` selects the earlier `rtl/cpu.sv` implementation through `cpu_harness.sv`. Its Makefile uses Icarus Verilog and Cocotb. The checked-in test resets the design, runs 15 rising edges, and then asserts selected state:

- x3 = `0x00000080`
- x5 = `0x00000123`
- x8 = `30`
- x9 = `30`
- x10 = `2`
- data-memory index 16 = `0x01238000`
- data-memory index 17 = `30`

This checks an integrated instruction/data path against concrete expected state. It is a test definition in the repository; the source files alone do not tell us which revision or whether that exact test was run in the user's final verification session.

A second legacy setup, `tb/ISA_TESTS/Makefile`, also compiles `rtl/cpu.sv` with `tb_top.sv`. The testbench loads `test_rv32i_full_clean.hex`, while its Cocotb test watches data writes for a termination word (`0xDEADBEEF` at `0x0FFC`) and checks a memory signature covering shifts, jumps, and signed/unsigned loads. Again, it belongs to the earlier `rtl/cpu.sv` path, not the pipelined core.

## 2. Pipeline-oriented testbench

`tb/ISA_TESTS/tb_isa.sv` is a separate SystemVerilog testbench for the pipeline CPU. It connects AXI BRAM slave models to the instruction and data sides, takes instruction and expected-register files through `+HEX` and `+EXP`, records debug writeback into a shadow register file, then compares x1–x31 against the expected values after 60 clock cycles.

This bench requires the pipelined CPU and its dependencies from `rtl_pipeline/`. Do not combine `rtl/cpu.sv` and `rtl_pipeline/cpu.sv` in one build: both declare a module named `cpu`. The legacy Makefiles under `tb/cpu/` and `tb/ISA_TESTS/` explicitly select `rtl/cpu.sv`; they are not build commands for the pipeline design.

## 3. Directed pipeline waveform run

The screenshots supplied for this project show a separate directed simulation using the following six instruction words:

```text
00500093
00a00113
002081b3
00302023
00002203
0000006f
```

The sequence is `addi x1, x0, 5`; `addi x2, x0, 10`; `add x3, x1, x2`; `sw x3, 0(x0)`; `lw x4, 0(x0)`; and `jal x0, 0`. The expected results are x1=5, x2=10, x3=15, the word at data-memory byte address 0=15, and x4=15. The user reports resolving the earlier x3 issue and verifying the run. The two included waveform images are the visual records supplied for that directed test.

The specific `tb_riscv.sv` and `my_test.hex` files used for that run were discussed in the project chat but are not present in the current repository tree. Including those exact files, their simulator command, and an automated pass/fail assertion would make this particular waveform run reproducible from a clean checkout.

## 4. FPGA implementation report snapshots

The supplied Vivado screenshots show device `xc7a100tcsg324-1`, post-synthesis estimates of 3,774 LUTs, 64 LUTRAMs, and 7,350 flip-flops, and post-implementation utilization of 3,706 LUTs, 62 LUTRAMs, 7,350 flip-flops, 6 I/Os, and 1 BUFG. The screenshot shows setup WNS +0.191 ns, TNS 0 ns, no failing endpoints, and estimated on-chip power 0.118 W.

These are report snapshots. They do not show the exact source commit, Vivado version, project settings, or full constraints, so the figures are not independently reproducible from the images alone.

## Scope

The single-cycle integration checks, the pipeline testbench, the directed waveform program, and the Vivado reports demonstrate different parts of the project. The six-word waveform test is targeted evidence for the instructions and memory behavior in that program; it is not exhaustive RV32I compliance or formal verification.

The checked-in FPGA wrapper `top.sv` ties instruction data to `32'h00000013` (NOP) and D-cache read data to zero. The FPGA video therefore documents board bring-up/activity, not execution of the six-word simulation program from an on-board instruction memory.
