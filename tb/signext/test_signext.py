import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test_signext(dut):

    # =========================================================
    # I-TYPE
    # =========================================================

    # Positive immediate: +10
    # I-type immediate occupies raw_src[24:13]

    dut.raw_src.value = 10 << 13
    dut.imm_source.value = 0

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 10, \
        "I-type positive immediate failed"

    # Negative immediate: -5
    # 12-bit representation of -5 = 0xFFB

    dut.raw_src.value = 0xFFB << 13
    dut.imm_source.value = 0

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 0xFFFFFFFB, \
        "I-type negative immediate failed"


    # =========================================================
    # S-TYPE
    # =========================================================

    # Positive immediate: +20
    #
    # imm[11:5] -> raw_src[24:18]
    # imm[4:0]  -> raw_src[4:0]

    s_imm = 20

    dut.raw_src.value = (
        ((s_imm >> 5) << 18) |
        (s_imm & 0x1F)
    )

    dut.imm_source.value = 1

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 20, \
        "S-type positive immediate failed"


    # =========================================================
    # B-TYPE
    # =========================================================

    # Positive branch offset: +16
    #
    # 16 = 0000000010000
    #
    # imm[4:1] = 1000
    # imm[0]   = 0
    #
    # imm[4:1] occupies raw_src[4:1]

    dut.raw_src.value = 0
    dut.raw_src.value = 0b1000 << 1
    dut.imm_source.value = 2

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 16, \
        "B-type positive immediate failed"


    # =========================================================
    # U-TYPE
    # =========================================================

    # Upper immediate = 0x12345
    #
    # U-type places it in bits [31:12]

    dut.raw_src.value = 0x12345 << 5
    dut.imm_source.value = 4

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 0x12345000, \
        "U-type immediate failed"


    # =========================================================
    # J-TYPE
    # =========================================================

    # Positive jump offset: +16
    #
    # 16 = 000000000000000010000
    #
    # imm[4:1] = 1000
    # imm[0]   = 0
    #
    # For J-type:
    #
    # imm[10:1] -> raw_src[23:14]
    #
    # Therefore imm[4:1] -> raw_src[17:14]

    dut.raw_src.value = 0
    dut.raw_src.value = 0b1000 << 14
    dut.imm_source.value = 3

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 16, \
        "J-type positive immediate failed"


    # =========================================================
    # DEFAULT
    # =========================================================

    dut.raw_src.value = 0
    dut.imm_source.value = 7

    await Timer(1, unit="ns")

    assert dut.immediate.value.to_unsigned() == 0, \
        "Default immediate failed"


    print("SIGNEXT TEST PASSED")