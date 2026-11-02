# Architecture notes

## Pipeline

The pipelined core in `rtl_pipeline/cpu.sv` uses five stages:

1. **IF** — program-counter and instruction-fetch path.
2. **ID** — instruction decode and register-file reads.
3. **EX** — ALU, branch/jump decision, and address calculation.
4. **MEM** — data access through the D-cache path.
5. **WB** — result selection and register-file writeback.

Pipeline state is carried by stage registers. The design includes forwarding and hazard/stall/flush control to manage dependencies and control-flow changes.

## Memory hierarchy and bus

The pipeline CPU instantiates instruction- and data-cache modules, with AXI-style memory interfaces at the external boundary. The D-cache RTL contains its control/state handling and supporting victim-cache/write-buffer logic.

The attached architecture drawing is a useful system-level map, but it contains more conceptual detail than can be inferred as separate instantiated RTL blocks. In particular, the drawing's standalone “Reader” labels should be read as logical data-path functions unless a separate module is present in the current RTL.

## FPGA wrapper status

The repository has a separate FPGA wrapper in `top.sv`. In the checked-in version, instruction data is tied to `32'h00000013` (the RISC-V NOP encoding), and D-cache read data is tied to zero. The board-level integration therefore does not demonstrate execution of an externally loaded program through instruction memory. The FPGA clip and Vivado reports are useful implementation/bring-up evidence, with that integration boundary stated clearly.

## Implemented variants

Both `rtl/cpu.sv` and `rtl_pipeline/cpu.sv` declare a module named `cpu`. Keep the two variants out of the same compile invocation; select the one intended for the run.
