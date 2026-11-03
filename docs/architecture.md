# Architecture notes

## Five-stage pipeline

The pipelined core in `rtl_pipeline/cpu.sv` has IF, ID, EX, MEM, and WB stages with stage registers between them. The design includes:

- forwarding from later pipeline stages to the EX-stage operands;
- load-use hazard detection, with stall and flush controls;
- branch/jump target and redirect handling;
- instruction fetch through an I-cache and data accesses through a D-cache;
- AXI-style read and write channels at the core boundary.

Both `rtl/cpu.sv` and `rtl_pipeline/cpu.sv` define a module named `cpu`. Select only one implementation in a build.

## Cache hierarchy present in RTL

These blocks exist in the checked-in pipeline RTL and are instantiated by the D-cache/core, not just shown in the diagram:

- **I-cache** — `rtl_pipeline/cache/icache.sv`: default 8 sets, 2 ways, and 4 32-bit words per line; handles read hits and requests a line fill on a miss.
- **D-cache** — `rtl_pipeline/cache/dcache.sv`: default parameters declare 8 sets, 2 ways, and 4 words per line; it tracks valid/dirty state, uses replacement state, handles read/write hits, and manages misses and evictions.
- **Victim cache** — `rtl_pipeline/cache/victim_cache.sv`: instantiated by the D-cache with depth 2 and 24-bit tags. It stores 128-bit cache lines and checks its entries by tag on a D-cache miss.
- **Write buffer** — `rtl_pipeline/cache/write_buffer.sv`: instantiated by the D-cache with depth 4. It queues write addresses, data, and byte strobes and drives the external AXI write address/data channels and response handling.

### D-cache configuration review

The D-cache RTL contains configuration mismatches that should be resolved before making broad claims about cache correctness. It declares `NUM_SETS=8` but extracts a four-bit set index from `core_addr[7:4]`; indices 8–15 do not fit an eight-entry set array. It also declares `NUM_WAYS=2`, while the PLRU victim-selection logic can produce way indices 0–3. The module wiring confirms the victim-cache and write-buffer blocks are instantiated, but these parameter/index mismatches mean cache hit/miss/eviction behavior needs targeted validation after the configuration is corrected.

The system diagram is a high-level view. Some blocks describe logical functions within a module rather than separate RTL modules; use the RTL files above for exact module boundaries and current implementation.

## FPGA wrapper and evidence boundary

The repository’s `top.sv` instantiates the pipeline CPU and connects its write path to an AXI GPIO block. However, instruction read data is assigned the NOP encoding `32'h00000013`, D-cache read data is assigned zero, and read-channel ready/valid/last signals are stubbed. Thus, the board-level wrapper can show clock/reset/wrapper/LED activity, but it is not a memory-backed execution of the ISA test program.

The supplied Vivado utilization, timing, and power screenshots are snapshots for the project as configured. Since the read paths are tied off, synthesis may trim logic that a real instruction/data memory connection would keep. Do not use these numbers as the resource cost or timing of the complete memory-connected processor without a new implementation run.
