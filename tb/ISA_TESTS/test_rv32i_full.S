.section .text
.global _start

_start:
    /* Setup signature base address */
    lui   x10, 0x1          /* x10 = 0x1000 (Signature Region) */

    /* =========================================
       SECTION 1: SHIFTS (SLL, SRL, SRA)
       ========================================= */
    li    x1, 0x80000001    /* A negative number with bits at both ends */
    
    sll   x2, x1, 4         /* Shift Left Logical:  0x00000010 */
    sw    x2, 0(x10)        /* Store at 0x1000 */

    srl   x3, x1, 4         /* Shift Right Logical: 0x08000000 (Zero fills from left) */
    sw    x3, 4(x10)        /* Store at 0x1004 */

    sra   x4, x1, 4         /* Shift Right Arithmetic: 0xF8000000 (Sign bit fills from left) */
    sw    x4, 8(x10)        /* Store at 0x1008 */

    /* =========================================
       SECTION 2: JUMPS (JAL, JALR)
       We use the "Branch Trap" method to test if the PC actually moved.
       ========================================= */
    
    /* Test JAL */
    li    x5, 0x00000001    /* Default PASS value */
    jal   x6, jal_pass      /* Jump over the fail code */
    
    li    x5, 0x0000BAD5    /* FAIL value (Should be skipped) */
    sw    x5, 12(x10)       /* Store FAIL at 0x100C */
    j     jalr_test         /* Skip pass code */

jal_pass:
    sw    x5, 12(x10)       /* Store PASS (0x0001) at 0x100C */

    /* Test JALR */
jalr_test:
    li    x5, 0x00000001    /* Default PASS value */
    la    x7, jalr_pass     /* Load address of target into x7 */
    jalr  x6, x7, 0         /* Jump to address in x7 */
    
    li    x5, 0x0000BAD6    /* FAIL value (Should be skipped) */
    sw    x5, 16(x10)       /* Store FAIL at 0x1010 */
    j     load_test         /* Skip pass code */

jalr_pass:
    sw    x5, 16(x10)       /* Store PASS (0x0001) at 0x1010 */

    /* =========================================
       SECTION 3: LOADS & STORES (LW, LH, LB, LHU, LBU)
       The Ultimate Sign-Extension Trap
       ========================================= */
load_test:
    /* 1. Write a known pattern to Data Memory at address 0x0200 */
    li    x8, 0xDEADBEEF    
    li    x9, 0x0200        
    sw    x8, 0(x9)         /* Memory[0x0200] = 0xDEADBEEF */

    /* 2. Read it back in different sizes */
    lw    x11, 0(x9)        /* Load Word:    0xDEADBEEF */
    sw    x11, 32(x10)      /* Store at 0x1020 */

    lh    x12, 0(x9)        /* Load Half:    0xFFFFBEEF (Sign-extended 0xBEEF) */
    sw    x12, 36(x10)      /* Store at 0x1024 */

    lb    x13, 0(x9)        /* Load Byte:    0xFFFFFFEF (Sign-extended 0xEF) */
    sw    x13, 40(x10)      /* Store at 0x1028 */

    lhu   x14, 0(x9)        /* Load Half Unsigned: 0x0000BEEF (Zero-extended) */
    sw    x14, 44(x10)      /* Store at 0x102C */

    lbu   x15, 0(x9)        /* Load Byte Unsigned: 0x000000EF (Zero-extended) */
    sw    x15, 48(x10)      /* Store at 0x1030 */

    /* =========================================
       TERMINATION SIGNAL
       ========================================= */
done:
    li    x20, 0xDEADBEEF
    li    x21, 0x0FFC
    sw    x20, 0(x21)       /* Write magic value to 0x0FFC */

halt:
    j halt                  /* Infinite loop */