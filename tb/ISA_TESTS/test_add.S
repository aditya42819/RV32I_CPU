/* test_add.S - Directed test for ADD instruction */

.section .text
.global _start

_start:
    /* 1. Setup the signature base address (0x1000) */
    lui   x10, 0x1          /* x10 = 0x1000 (Upper Immediate) */

    /* 2. Test 1: Positive + Positive */
    addi  x1, x0, 10        /* x1 = 10 */
    addi  x2, x0, 20        /* x2 = 20 */
    add   x3, x1, x2        /* x3 = x1 + x2 = 30 */
    sw    x3, 0(x10)        /* Store result at 0x1000 (signature[0]) */

    /* 3. Test 2: Negative + Positive (Overflow check) */
    addi  x4, x0, -5        /* x4 = -5 (0xFFFFFFFB) */
    add   x5, x3, x4        /* x5 = 30 + (-5) = 25 */
    sw    x5, 4(x10)        /* Store result at 0x1004 (signature[1]) */

    /* 4. Test 3: Zero behavior (x0 must remain 0) */
    add   x6, x1, x0        /* x6 = 10 + 0 = 10 */
    sw    x6, 8(x10)        /* Store result at 0x1008 (signature[2]) */

    /* 5. Signal Test Complete */
    /* Write magic value 0xDEADBEEF to address 0x0FFC */
    addi  x11, x10, -4      /* x11 = 0x1000 - 4 = 0x0FFC */
       li    x12, 0xDEADBEEF   /* Assembler handles the lui/addi math */
    sw    x12, 0(x11)       /* Store magic value at 0x0FFC */

    /* 6. Infinite loop to halt the CPU */
done:
    j done