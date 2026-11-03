# Verification notes

## Official RISC-V ISA verification

The project owner reports running the **official RISC-V ISA verification tests**. This is a distinct verification activity from the repository's own directed test programs and waveform captures.

The pipeline ISA testbench **is checked in** at `tb/ISA_TESTS/tb_isa.sv`. It connects AXI BRAM slave models, accepts an instruction image through `+HEX` and expected register values through `+EXP`, records debug writeback into a shadow register file, and compares x1–x31 after 60 cycles. This is the pipeline-level ISA test path in the repository.

The project owner reports running the official RISC-V ISA verification tests. The current repository does not include the official suite version/name, target configuration, run command, or pass/fail transcript, so the testbench is present but the official run is not independently auditable from the checked-in files. To make it reproducible, include the suite/version and configuration, the exact test image and core source list, the run command or script, and the unedited pass/fail summary.

Do not mistake `tb/ISA_TESTS/test_rv32i_full.S` for the official suite. It is a project-directed assembly program. It checks SLL/SRL/SRA, JAL/JALR control flow, and LW/LH/LB/LHU/LBU data-width and extension behavior through a memory signature. Separate directed programs in the same directory cover arithmetic, branches, jumps, cache, and pipeline components. The Makefile in that directory selects the older `rtl/cpu.sv` CPU; it does not select `rtl_pipeline/cpu.sv`.

## Single-cycle integration tests

The Cocotb setup under `tb/cpu/` selects `rtl/cpu.sv` through `cpu_harness.sv`. Its checked-in test resets the processor, runs 15 clock cycles, then asserts values in x3, x5, x8, x9, x10 and data-memory words 16 and 17.

The legacy `tb/ISA_TESTS/Makefile` also targets `rtl/cpu.sv` and `tb_top.sv`. The associated signature test waits for a termination write and checks expected memory values. These are test definitions and historical run artifacts; they should not be presented as proof that the pipeline implementation passed the official suite.

## Pipeline-oriented testbench

`tb/ISA_TESTS/tb_isa.sv` is the pipeline-oriented ISA bench described above. It is separate from the older Makefiles and is a testbench, not itself a pass log. The evidence needed to show which official suite cases passed remains a run transcript or generated pass/fail table.

Never compile both CPU variants together: each declares a module named `cpu`.

## Directed waveform run

The supplied six-word waveform program was:

```text
00500093
00a00113
002081b3
00302023
00002203
0000006f
```

It performs two ADDIs, an ADD with dependent operands, a store, a load, and a self-looping JAL. Expected results are x1=5, x2=10, x3=15, memory word 0=15, and x4=15. The project owner reports resolving the x3 issue and verifying this run; the two included waveform images are the supplied visual evidence.

The specific `tb_riscv.sv` and `my_test.hex` files used for this run are not in the current repository. Include those exact files and a machine-checked pass/fail check if this run should be reproducible from a clean checkout.

## Vivado snapshot and FPGA wrapper

The supplied Vivado screenshots show part `xc7a100tcsg324-1`, post-synthesis estimates of 3,774 LUTs, 64 LUTRAMs, and 7,350 flip-flops, and post-implementation use of 3,706 LUTs, 62 LUTRAMs, 7,350 flip-flops, 6 I/Os, and 1 BUFG. The summary reports WNS +0.191 ns, TNS 0 ns, 0 failing endpoints, and estimated on-chip power 0.118 W.

The checked-in `top.sv` ties instruction read data to NOP and D-cache read data to zero, and stubs the read-channel handshake signals. The FPGA video therefore documents board/wrapper bring-up, not the processor executing the official ISA suite or the six-word program from real instruction memory.

Because the read paths are tied off, Vivado may have optimized away portions of the caches or core. Treat these figures as a snapshot of the configured wrapper/project, not as area/timing for the complete memory-connected CPU. A new implementation with real memories connected is needed for that claim.

## Scope

Official suite execution, project-directed tests, pipeline waveform inspection, and FPGA implementation are different evidence types. Keep their core variant, test program, command, and result separate when describing verification. None of the current artifacts establishes formal verification or full RV32I certification of the pipelined core.
