// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CPU_PACKAGE_H_
#define VERILATED_VTOP_CPU_PACKAGE_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_cpu_package final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*6:0*/ OPCODE_RTYPE = 0x33U;
    static constexpr CData/*6:0*/ OPCODE_ITYPE = 0x13U;
    static constexpr CData/*6:0*/ OPCODE_LOAD = 3U;
    static constexpr CData/*6:0*/ OPCODE_STORE = 0x23U;
    static constexpr CData/*6:0*/ OPCODE_BRANCH = 0x63U;
    static constexpr CData/*6:0*/ OPCODE_JALR = 0x67U;
    static constexpr CData/*6:0*/ OPCODE_JAL = 0x6fU;
    static constexpr CData/*6:0*/ OPCODE_LUI = 0x37U;
    static constexpr CData/*6:0*/ OPCODE_AUIPC = 0x17U;
    static constexpr CData/*3:0*/ ALU_ADD = 0U;
    static constexpr CData/*3:0*/ ALU_SUB = 1U;
    static constexpr CData/*3:0*/ ALU_AND = 2U;
    static constexpr CData/*3:0*/ ALU_OR = 3U;
    static constexpr CData/*3:0*/ ALU_XOR = 4U;
    static constexpr CData/*3:0*/ ALU_SLL = 5U;
    static constexpr CData/*3:0*/ ALU_SRL = 6U;
    static constexpr CData/*3:0*/ ALU_SRA = 7U;
    static constexpr CData/*3:0*/ ALU_SLT = 8U;
    static constexpr CData/*3:0*/ ALU_SLTU = 9U;
    static constexpr CData/*0:0*/ ALU_SRC_REG = 0U;
    static constexpr CData/*0:0*/ ALU_SRC_IMM = 1U;
    static constexpr CData/*2:0*/ IMM_I = 0U;
    static constexpr CData/*2:0*/ IMM_S = 1U;
    static constexpr CData/*2:0*/ IMM_B = 2U;
    static constexpr CData/*2:0*/ IMM_J = 3U;
    static constexpr CData/*2:0*/ IMM_U = 4U;
    static constexpr CData/*1:0*/ WRITEBACK_ALU = 0U;
    static constexpr CData/*1:0*/ WRITEBACK_MEMORY = 1U;
    static constexpr CData/*1:0*/ WRITEBACK_PC4 = 2U;
    static constexpr CData/*1:0*/ WRITEBACK_IMM = 3U;
    static constexpr CData/*2:0*/ BR_BEQ = 0U;
    static constexpr CData/*2:0*/ BR_BNE = 1U;
    static constexpr CData/*2:0*/ BR_BLT = 4U;
    static constexpr CData/*2:0*/ BR_BGE = 5U;
    static constexpr CData/*2:0*/ BR_BLTU = 6U;
    static constexpr CData/*2:0*/ BR_BGEU = 7U;

    // CONSTRUCTORS
    Vtop_cpu_package(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_cpu_package();
    VL_UNCOPYABLE(Vtop_cpu_package);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
