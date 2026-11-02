# Project journey: from single-cycle CPU to pipeline

## Starting point: learn the datapath by building it

I began this project by studying computer-architecture concepts from the Harris & Harris book I was using, then translating those ideas into a working SystemVerilog processor. I chose a single-cycle design as my first implementation because it makes the instruction path easier to reason about: fetch an instruction, decode it, read operands, perform an operation or calculate an address, and update architectural state.

That first CPU was my baseline. It gave me practical experience with the core building blocks:

- the program counter and sequential/redirected PC updates;
- instruction fields and immediate generation;
- control decoding for instruction behavior;
- a register file and ALU datapath;
- load/store address and writeback paths;
- connecting modules into a top-level processor.

The repository preserves this earlier design under `rtl/`. The test materials also reflect the early stage of the project, which is why not every existing simulation command is for the later pipelined CPU.

## Why move to a pipeline?

Once I understood the single-cycle datapath, I wanted to explore a more realistic processor organization. I divided the work into five stages—IF, ID, EX, MEM, and WB—with registers between the stages. This allows multiple instructions to occupy different stages at once, but it also creates new correctness problems: an instruction can need a result that an earlier instruction has not written back yet, a branch can make fetched instructions irrelevant, and a memory interface can take more than one cycle.

The pipeline therefore required additional control and visibility into timing. I added forwarding selection and hazard/stall/flush logic, and used waveform inspection to follow the PC, instructions in the pipeline, control signals, register writeback, and memory handshakes. This is the central shift in the project: the processor is no longer only a datapath; it is a datapath coordinated across several cycles and several in-flight instructions.

## Adding the memory subsystem

The pipelined CPU connects to instruction- and data-cache RTL and exposes AXI-style memory channels. The data side includes control for requests and response flow, as well as supporting victim-cache and write-buffer logic. This expanded the project from a small CPU core into a larger integration exercise involving ready/valid handshakes, cache behavior, and memory-side stalls.

The architecture diagram is a map of that design intent. The RTL should remain the authority for exact module boundaries: some blocks in the drawing are logical functions within a larger RTL module.

## How I exercised the pipeline

The shared directed program uses six words:

```text
00500093  addi x1, x0, 5
00a00113  addi x2, x0, 10
002081b3  add  x3, x1, x2
00302023  sw   x3, 0(x0)
00002203  lw   x4, 0(x0)
0000006f  jal  x0, 0
```

This sequence is useful because it checks a dependency chain and a simple memory round trip:

1. Set x1 to 5.
2. Set x2 to 10.
3. Add those values into x3, exercising a dependency on the preceding writes.
4. Store x3 to data-memory byte address 0.
5. Load the word back into x4.
6. Jump to the same instruction, leaving the processor in a visible loop.

The expected final values are x1=5, x2=10, x3=15, memory[0]=15, and x4=15. I used the simulator waveforms to inspect instruction movement, forwarding and control activity, and the load/store interface. The screenshots in this repository are visual records of that directed run. They should be read as targeted functional evidence, not as a full instruction-set certification.

## Moving to the FPGA

After working through simulation, I brought the design into Vivado for synthesis and implementation and used an FPGA board demonstration to observe activity on the physical board. The supplied report captures show the target part, utilization, setup timing summary, and estimated on-chip power. The video records the board bring-up.

There is an important integration boundary in the current repository: `top.sv` ties instruction data to the NOP encoding and D-cache read data to zero. The FPGA clip therefore documents board-level activity and implementation work; it does not show the six-word test program being fetched from an on-board instruction memory. The program’s functional behavior is instead represented by the simulation evidence.

## What I learned

This project took me from understanding the single-cycle instruction path to managing a pipelined design with dependencies, control-flow changes, and memory handshakes. Along the way I practiced:

- writing modular SystemVerilog and connecting a datapath;
- separating combinational control from sequential state;
- reasoning about forwarding and pipeline hazards;
- tracking timing-dependent behavior in waveforms;
- integrating cache and AXI-style interfaces;
- running a design through FPGA synthesis and implementation;
- communicating design intent with an architecture diagram and documenting integration limits.

The most useful next step for anyone continuing the project is to make the test flow reproducible for the pipelined core, with an explicit compile list and machine-checked assertions for the expected register and memory values. The current repo contains test materials from different development stages, so the intended CPU variant must be selected deliberately.
