.section .text
.global _start

_start:
    /* Setup signature base address */
    lui   x10, 0x1          /* x10 = 0x1000 */

    /* =========================================
       TEST 1: BEQ (Branch if Equal) - TAKEN
       ========================================= */
    li    x1, 0x0000000A
    li    x2, 0x0000000A
    li    x3, 0x00000001    /* Default PASS value */
    
    beq   x1, x2, beq_pass  /* If x1 == x2, jump over the fail code */
    
    /* --- FALL THROUGH (Branch Failed) --- */
    li    x3, 0x0000BAD1    /* FAIL value */
    sw    x3, 0(x10)        /* Store FAIL at 0x1000 */
    j     test2             /* Skip the pass code */
    
    /* --- JUMP TARGET (Branch Passed) --- */
beq_pass:
    sw    x3, 0(x10)        /* Store PASS (0x0001) at 0x1000 */

    /* =========================================
       TEST 2: BNE (Branch if Not Equal) - TAKEN
       ========================================= */
test2:
    li    x1, 0x00000005
    li    x2, 0x0000000A
    li    x3, 0x00000001    /* Default PASS value */
    
    bne   x1, x2, bne_pass  /* If x1 != x2, jump over the fail code */
    
    /* --- FALL THROUGH (Branch Failed) --- */
    li    x3, 0x0000BAD2    /* FAIL value */
    sw    x3, 4(x10)        /* Store FAIL at 0x1004 */
    j     test3             /* Skip the pass code */
    
    /* --- JUMP TARGET (Branch Passed) --- */
bne_pass:
    sw    x3, 4(x10)        /* Store PASS (0x0001) at 0x1004 */

    /* =========================================
       TEST 3: BLT (Signed Branch Less Than)
       Is -1 < 1? (YES)
       ========================================= */
test3:
    li    x1, 0xFFFFFFFF    /* x1 = -1 (Signed) */
    li    x2, 0x00000001    /* x2 = 1  (Signed) */
    li    x3, 0x00000001    /* Default PASS value */
    
    blt   x1, x2, blt_pass  /* If -1 < 1, jump over fail code */
    
    /* --- FALL THROUGH (Branch Failed) --- */
    li    x3, 0x0000BAD3    /* FAIL value */
    sw    x3, 8(x10)        /* Store FAIL at 0x1008 */
    j     test4             /* Skip the pass code */
    
    /* --- JUMP TARGET (Branch Passed) --- */
blt_pass:
    sw    x3, 8(x10)        /* Store PASS (0x0001) at 0x1008 */

    /* =========================================
       TEST 4: BLTU (Unsigned Branch Less Than)
       Is 1 < 0xFFFFFFFF? (YES)
       ========================================= */
test4:
    li    x1, 0x00000001    /* x1 = 1 (Unsigned) */
    li    x2, 0xFFFFFFFF    /* x2 = 4,294,967,295 (Unsigned) */
    li    x3, 0x00000001    /* Default PASS value */
    
    bltu  x1, x2, bltu_pass /* If 1 < 4B, jump over fail code */
    
    /* --- FALL THROUGH (Branch Failed) --- */
    li    x3, 0x0000BAD4    /* FAIL value */
    sw    x3, 12(x10)       /* Store FAIL at 0x100C */
    j     done              /* Skip the pass code */
    
    /* --- JUMP TARGET (Branch Passed) --- */
bltu_pass:
    sw    x3, 12(x10)       /* Store PASS (0x0001) at 0x100C */

    /* =========================================
       TERMINATION SIGNAL
       ========================================= */
done:
    li    x20, 0xDEADBEEF
    li    x21, 0x0FFC
    sw    x20, 0(x21)       /* Write magic value to 0x0FFC */

halt:
    j halt                  /* Infinite loop */

