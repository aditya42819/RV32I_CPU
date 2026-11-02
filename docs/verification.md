# Verification notes

## Directed pipeline smoke program

The shared six-word program is:

```text
00500093
00a00113
002081b3
00302023
00002203
0000006f
```

It performs `addi`, `add`, `sw`, `lw`, then loops with `jal x0, 0`. Expected architectural effects are:

- x1 = 5
- x2 = 10
- x3 = 15
- data-memory word at byte address 0 = 15
- x4 = 15 after the load

The supplied waveform captures document the user's directed simulation run and are included as visual evidence. For repeatable verification, retain the exact testbench, simulator command, memory-model behavior, and a pass/fail check of these expected values together.

## Existing repository test materials

The repository contains multiple generations of test material. The ISA test Makefile targets the earlier `rtl/cpu.sv` implementation and its associated testbench; it should not be treated as an invocation for `rtl_pipeline/cpu.sv`. The pipeline-oriented ISA testbench is separate. Check the specific testbench's parameters and dependencies before using a run command.

Generated simulator outputs in the repository are historical artifacts and do not, by themselves, identify the RTL revision, test command, or a machine-readable pass/fail summary.

## FPGA reports

The included Vivado images show a successful implementation summary for part `xc7a100tcsg324-1`, with WNS +0.191 ns, TNS 0 ns, and no failing endpoints reported in the screenshot. They are report snapshots rather than a reproducible build record: the source commit, tool version, clock constraints, and project settings are not embedded in the images.

## Scope of claims

The smoke test is a directed functional check for the instructions listed above, not exhaustive RV32I verification or formal verification. The board wrapper currently supplies NOP instruction data and zero D-cache read data, so FPGA bring-up evidence must not be described as an on-board run of the smoke program.
