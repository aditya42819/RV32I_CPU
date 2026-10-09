// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_cpu_package;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_cpu_package* __PVT__cpu_package;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ cpu__DOT__u_pc__DOT__clk;
        CData/*0:0*/ cpu__DOT__u_regfile__DOT__clk;
        VL_IN8(rst_n,0,0);
        VL_IN8(clk,0,0);
        VL_OUT8(data_writeenable,0,0);
        VL_OUT8(data_byteenable,3,0);
        CData/*0:0*/ cpu__DOT__rst_n;
        CData/*0:0*/ cpu__DOT__clk;
        CData/*0:0*/ cpu__DOT__data_writeenable;
        CData/*3:0*/ cpu__DOT__data_byteenable;
        CData/*6:0*/ cpu__DOT__opcode;
        CData/*6:0*/ cpu__DOT__funct7;
        CData/*4:0*/ cpu__DOT__rs1;
        CData/*4:0*/ cpu__DOT__rs2;
        CData/*4:0*/ cpu__DOT__rd;
        CData/*2:0*/ cpu__DOT__funct3;
        CData/*3:0*/ cpu__DOT__alu_control;
        CData/*2:0*/ cpu__DOT__imm_source;
        CData/*2:0*/ cpu__DOT__branch_type;
        CData/*1:0*/ cpu__DOT__result_src;
        CData/*0:0*/ cpu__DOT__alu_src;
        CData/*0:0*/ cpu__DOT__reg_write;
        CData/*0:0*/ cpu__DOT__mem_write;
        CData/*0:0*/ cpu__DOT__branch;
        CData/*0:0*/ cpu__DOT__jump;
        CData/*0:0*/ cpu__DOT__alu_zero;
        CData/*0:0*/ cpu__DOT__alu_last_bit;
        CData/*0:0*/ cpu__DOT__branch_taken;
        CData/*0:0*/ cpu__DOT__u_pc__DOT__reset;
        CData/*6:0*/ cpu__DOT__u_control__DOT__opcode;
        CData/*2:0*/ cpu__DOT__u_control__DOT__funct3;
        CData/*6:0*/ cpu__DOT__u_control__DOT__funct7;
        CData/*3:0*/ cpu__DOT__u_control__DOT__alu_control;
        CData/*2:0*/ cpu__DOT__u_control__DOT__imm_source;
        CData/*0:0*/ cpu__DOT__u_control__DOT__alu_src;
        CData/*0:0*/ cpu__DOT__u_control__DOT__reg_write;
        CData/*0:0*/ cpu__DOT__u_control__DOT__mem_write;
        CData/*1:0*/ cpu__DOT__u_control__DOT__result_src;
        CData/*0:0*/ cpu__DOT__u_control__DOT__branch;
        CData/*0:0*/ cpu__DOT__u_control__DOT__jump;
        CData/*2:0*/ cpu__DOT__u_control__DOT__branch_type;
        CData/*2:0*/ cpu__DOT__u_signext__DOT__imm_source;
        CData/*3:0*/ cpu__DOT__u_alu__DOT__alu_control;
        CData/*0:0*/ cpu__DOT__u_alu__DOT__zero;
        CData/*0:0*/ cpu__DOT__u_alu__DOT__last_bit;
        CData/*4:0*/ cpu__DOT__u_alu__DOT__shamt;
        CData/*2:0*/ cpu__DOT__u_store_decoder__DOT__funct3;
        CData/*3:0*/ cpu__DOT__u_store_decoder__DOT__byte_enable;
        CData/*1:0*/ cpu__DOT__u_store_decoder__DOT__offset;
        CData/*2:0*/ cpu__DOT__u_reader__DOT__funct3;
        CData/*1:0*/ cpu__DOT__u_reader__DOT__offset;
        CData/*0:0*/ cpu__DOT__u_reader__DOT__sign_extend;
        CData/*0:0*/ cpu__DOT__u_regfile__DOT__rst;
        CData/*4:0*/ cpu__DOT__u_regfile__DOT__rs1;
        CData/*4:0*/ cpu__DOT__u_regfile__DOT__rs2;
        CData/*4:0*/ cpu__DOT__u_regfile__DOT__rd;
        CData/*0:0*/ cpu__DOT__u_regfile__DOT__write_enable;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__u_pc__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__u_regfile__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(instr_address,31,0);
        VL_IN(instr_rdata,31,0);
    };
    struct {
        VL_IN(data_rdata,31,0);
        VL_OUT(data_address,31,0);
        VL_OUT(data_writedata,31,0);
        IData/*31:0*/ cpu__DOT__instr_address;
        IData/*31:0*/ cpu__DOT__instr_rdata;
        IData/*31:0*/ cpu__DOT__data_rdata;
        IData/*31:0*/ cpu__DOT__data_address;
        IData/*31:0*/ cpu__DOT__data_writedata;
        IData/*31:0*/ cpu__DOT__pc;
        IData/*31:0*/ cpu__DOT__pc_next;
        IData/*31:0*/ cpu__DOT__pc_plus4;
        IData/*31:0*/ cpu__DOT__pc_target;
        IData/*31:0*/ cpu__DOT__read_reg1;
        IData/*31:0*/ cpu__DOT__read_reg2;
        IData/*31:0*/ cpu__DOT__writeback_data;
        IData/*31:0*/ cpu__DOT__immediate;
        IData/*31:0*/ cpu__DOT__alu_src1;
        IData/*31:0*/ cpu__DOT__alu_src2;
        IData/*31:0*/ cpu__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__store_data;
        IData/*31:0*/ cpu__DOT__load_data;
        IData/*31:0*/ cpu__DOT__u_pc__DOT__next_pc;
        IData/*31:0*/ cpu__DOT__u_pc__DOT__pc;
        IData/*24:0*/ cpu__DOT__u_signext__DOT__raw_src;
        IData/*31:0*/ cpu__DOT__u_signext__DOT__immediate;
        IData/*31:0*/ cpu__DOT__u_alu__DOT__src1;
        IData/*31:0*/ cpu__DOT__u_alu__DOT__src2;
        IData/*31:0*/ cpu__DOT__u_alu__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__u_store_decoder__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__u_store_decoder__DOT__reg_read;
        IData/*31:0*/ cpu__DOT__u_store_decoder__DOT__data;
        IData/*31:0*/ cpu__DOT__u_reader__DOT__mem_data;
        IData/*31:0*/ cpu__DOT__u_reader__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__u_reader__DOT__read_data;
        IData/*31:0*/ cpu__DOT__u_regfile__DOT__write_data;
        IData/*31:0*/ cpu__DOT__u_regfile__DOT__data1;
        IData/*31:0*/ cpu__DOT__u_regfile__DOT__data2;
        IData/*31:0*/ cpu__DOT__u_regfile__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> cpu__DOT__u_regfile__DOT__registers;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
