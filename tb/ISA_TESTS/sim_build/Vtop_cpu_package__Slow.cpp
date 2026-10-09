// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_cpu_package.h"

// Parameter definitions for Vtop_cpu_package
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_RTYPE;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_ITYPE;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_LOAD;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_STORE;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_BRANCH;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_JALR;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_JAL;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_LUI;
constexpr CData/*6:0*/ Vtop_cpu_package::OPCODE_AUIPC;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_ADD;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SUB;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_AND;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_OR;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_XOR;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SLL;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SRL;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SRA;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SLT;
constexpr CData/*3:0*/ Vtop_cpu_package::ALU_SLTU;
constexpr CData/*0:0*/ Vtop_cpu_package::ALU_SRC_REG;
constexpr CData/*0:0*/ Vtop_cpu_package::ALU_SRC_IMM;
constexpr CData/*2:0*/ Vtop_cpu_package::IMM_I;
constexpr CData/*2:0*/ Vtop_cpu_package::IMM_S;
constexpr CData/*2:0*/ Vtop_cpu_package::IMM_B;
constexpr CData/*2:0*/ Vtop_cpu_package::IMM_J;
constexpr CData/*2:0*/ Vtop_cpu_package::IMM_U;
constexpr CData/*1:0*/ Vtop_cpu_package::WRITEBACK_ALU;
constexpr CData/*1:0*/ Vtop_cpu_package::WRITEBACK_MEMORY;
constexpr CData/*1:0*/ Vtop_cpu_package::WRITEBACK_PC4;
constexpr CData/*1:0*/ Vtop_cpu_package::WRITEBACK_IMM;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BEQ;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BNE;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BLT;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BGE;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BLTU;
constexpr CData/*2:0*/ Vtop_cpu_package::BR_BGEU;


void Vtop_cpu_package___ctor_var_reset(Vtop_cpu_package* vlSelf);

Vtop_cpu_package::Vtop_cpu_package(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_cpu_package___ctor_var_reset(this);
}

void Vtop_cpu_package::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_cpu_package::~Vtop_cpu_package() {
}
