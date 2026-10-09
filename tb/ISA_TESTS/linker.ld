/* linker.ld */
MEMORY
{
    /* Instruction Memory: 4KB starting at 0x0000 */
    INSTR_MEM (rx) : ORIGIN = 0x00000000, LENGTH = 4K
    
    /* Data Memory: 4KB starting at 0x1000 */
    DATA_MEM (rw)  : ORIGIN = 0x00001000, LENGTH = 4K
}

SECTIONS
{
    /* Place all code in Instruction Memory */
    .text : {
        *(.text)
        *(.text.*)
    } > INSTR_MEM

    /* Place all data in Data Memory */
    .data : {
        *(.data)
        *(.data.*)
        *(.bss)
    } > DATA_MEM
}