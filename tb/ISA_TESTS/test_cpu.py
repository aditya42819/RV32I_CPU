import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import os

# ============================================================================
# TEST CONFIGURATION
# ============================================================================
TERMINATION_ADDR = 0x0FFC
TERMINATION_MAGIC = 0xDEADBEEF
MAX_CYCLES = 5000

EXPECTED_SIGNATURE = {
    # --- Shifts ---
    0x1000: 0x00000010,  # SLL (Shift Left Logical)
    0x1004: 0x08000000,  # SRL (Shift Right Logical - Zero fills)
    0x1008: 0xF8000000,  # SRA (Shift Right Arithmetic - Sign bit fills)
    
    # --- Jumps ---
    0x100C: 0x00000001,  # JAL Pass
    0x1010: 0x00000001,  # JALR Pass
    
    # --- Loads (The Sign-Extension Trap) ---
    0x1020: 0xDEADBEEF,  # LW  (Full word)
    0x1024: 0xFFFFBEEF,  # LH  (Sign-extended half word: 0xBEEF is negative)
    0x1028: 0xFFFFFFEF,  # LB  (Sign-extended byte: 0xEF is negative)
    0x102C: 0x0000BEEF,  # LHU (Zero-extended half word)
    0x1030: 0x000000EF,  # LBU (Zero-extended byte)
}
# ============================================================================
# MAIN TEST
# ============================================================================
@cocotb.test()
async def test_add_instruction(dut):
    """Test ADD instruction with signature-based verification."""
    
    # 1. Generate a 10ns (100MHz) clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    # 2. Reset the CPU
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    
    # 3. Run simulation and monitor memory interface
    cycles = 0
    terminated = False
    memory_writes = {}  # Python dictionary acting as our Data Memory model
    
    dut._log.info("Starting simulation...")
    
    while cycles < MAX_CYCLES and not terminated:
        await RisingEdge(dut.clk)
        cycles += 1
        
        # Monitor the CPU's data memory interface
        # Note: Check your cpu.sv port names. Assuming standard names based on handoff.
        if dut.data_writeenable.value == 1:
            addr = int(dut.data_address.value)
            data = int(dut.data_writedata.value)
            
            # Record the write in our Python memory model
            memory_writes[addr] = data
            
            # Check for the termination signal
            if addr == TERMINATION_ADDR and data == TERMINATION_MAGIC:
                terminated = True
                dut._log.info(f"Termination signal detected at cycle {cycles}!")
    
    # 4. Verify the test actually finished
    if not terminated:
        raise AssertionError(f"CPU did not terminate within {MAX_CYCLES} cycles. It might be stuck.")
    
    # 5. Signature Verification
    dut._log.info("=== SIGNATURE VERIFICATION ===")
    all_passed = True
    
    for addr, expected_val in EXPECTED_SIGNATURE.items():
        actual_val = memory_writes.get(addr, 0xDEADBEEF) # Default to magic if missing
        
        if actual_val == expected_val:
            status = "PASS"
        else:
            status = "FAIL"
            all_passed = False
            
        dut._log.info(
            f"Memory[0x{addr:04X}] = 0x{actual_val:08X} "
            f"(Expected: 0x{expected_val:08X}) [{status}]"
        )
    
    # 6. Final Assertion
    if all_passed:
        dut._log.info("=== ALL CHECKS PASSED ===")
    else:
        raise AssertionError("One or more signature checks failed! Check the logs above.")