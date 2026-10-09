.section .text
.global _start

_start:
    /* Setup signature base address */
    lui   x10, 0x1          /* x10 = 0x1000 */

    /* --- SUB Tests --- */
    addi  x1, x0, 10        /* x1 = 10 */
    addi  x2, x0, 20        /* x2 = 20 */
    sub   x3, x1, x2        /* x3 = 10 - 20 = -10 */
    sw    x3, 0(x10)        /* Store at 0x1000 */

    addi  x4, x0, -5        /* x4 = -5 */
    sub   x5, x3, x4        /* x5 = -10 - (-5) = -5 */
    sw    x5, 4(x10)        /* Store at 0x1004 */

    sub   x6, x1, x0        /* x6 = 10 - 0 = 10 */
    sw    x6, 8(x10)        /* Store at 0x1008 */

    /* --- SLT vs SLTU Trap (The Ultimate Test) --- */
    addi  x11, x0, -1       /* x11 = -1 (0xFFFFFFFF) */
    addi  x12, x0, 1        /* x12 = 1  (0x00000001) */

    slt   x13, x11, x12     /* Signed: Is -1 < 1? YES -> x13 = 1 */
    sw    x13, 12(x10)      /* Store at 0x100C */

    sltu  x14, x11, x12     /* Unsigned: Is 0xFFFFFFFF < 0x00000001? NO -> x14 = 0 */
    sw    x14, 16(x10)      /* Store at 0x1010 */

    /* --- Bitwise Logic Tests --- */
    /* We use 'li' because these numbers are too big for 'addi' (which only takes 12 bits) */
    li    x15, 0xFF00FF00   
    li    x16, 0x0FF00FF0   

    or    x17, x15, x16     /* 0xFF00FF00 | 0x0FF00FF0 = 0xFFF0FFF0 */
    sw    x17, 20(x10)      /* Store at 0x1014 */

    and   x18, x15, x16     /* 0xFF00FF00 & 0x0FF00FF0 = 0x0F000F00 */
    sw    x18, 24(x10)      /* Store at 0x1018 */

    xor   x19, x15, x16     /* 0xFF00FF00 ^ 0x0FF00FF0 = 0xF0F0F0F0 */
    sw    x19, 28(x10)      /* Store at 0x101C */

    /* --- Termination Signal --- */
    li    x20, 0xDEADBEEF
    li    x21, 0x0FFC
    sw    x20, 0(x21)       /* Write magic value to 0x0FFC */

done:
    j done                  /* Infinite loop */j