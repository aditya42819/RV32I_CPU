// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_cpu_package.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_cpu);
    __Vhier.remove(0, &__Vscope_cpu_package);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_alu);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_control);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_pc);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_reader);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_regfile);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_signext);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__u_store_decoder);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__cpu_package{this, Verilated::catName(namep, "cpu_package")}
{
        // Check resources
        Verilated::stackCheck(39);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__cpu_package = &TOP__cpu_package;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__cpu_package.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu.configure(this, name(), "cpu", "cpu", "cpu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_alu.configure(this, name(), "cpu.u_alu", "u_alu", "alu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_control.configure(this, name(), "cpu.u_control", "u_control", "control", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_pc.configure(this, name(), "cpu.u_pc", "u_pc", "program_counter", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_reader.configure(this, name(), "cpu.u_reader", "u_reader", "reader", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_regfile.configure(this, name(), "cpu.u_regfile", "u_regfile", "regfile", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_signext.configure(this, name(), "cpu.u_signext", "u_signext", "signext", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__u_store_decoder.configure(this, name(), "cpu.u_store_decoder", "u_store_decoder", "load_store_decoder", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu_package.configure(this, name(), "cpu_package", "cpu_package", "cpu_package", -9, VerilatedScope::SCOPE_PACKAGE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_cpu);
    __Vhier.add(0, &__Vscope_cpu_package);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_alu);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_control);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_pc);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_reader);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_regfile);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_signext);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__u_store_decoder);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_address", &(TOP.data_address), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_byteenable", &(TOP.data_byteenable), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_rdata", &(TOP.data_rdata), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_writedata", &(TOP.data_writedata), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_writeenable", &(TOP.data_writeenable), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"instr_address", &(TOP.instr_address), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"instr_rdata", &(TOP.instr_rdata), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_control", &(TOP.cpu__DOT__alu_control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_last_bit", &(TOP.cpu__DOT__alu_last_bit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_src", &(TOP.cpu__DOT__alu_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_src1", &(TOP.cpu__DOT__alu_src1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_src2", &(TOP.cpu__DOT__alu_src2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_zero", &(TOP.cpu__DOT__alu_zero), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"branch", &(TOP.cpu__DOT__branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"branch_taken", &(TOP.cpu__DOT__branch_taken), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"branch_type", &(TOP.cpu__DOT__branch_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_address", &(TOP.cpu__DOT__data_address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_byteenable", &(TOP.cpu__DOT__data_byteenable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_rdata", &(TOP.cpu__DOT__data_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_writedata", &(TOP.cpu__DOT__data_writedata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_writeenable", &(TOP.cpu__DOT__data_writeenable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"funct3", &(TOP.cpu__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"funct7", &(TOP.cpu__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu.varInsert(__Vfinal,"imm_source", &(TOP.cpu__DOT__imm_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"immediate", &(TOP.cpu__DOT__immediate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"instr_address", &(TOP.cpu__DOT__instr_address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"instr_rdata", &(TOP.cpu__DOT__instr_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"jump", &(TOP.cpu__DOT__jump), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"load_data", &(TOP.cpu__DOT__load_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"mem_write", &(TOP.cpu__DOT__mem_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"opcode", &(TOP.cpu__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc", &(TOP.cpu__DOT__pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc_next", &(TOP.cpu__DOT__pc_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc_plus4", &(TOP.cpu__DOT__pc_plus4), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc_target", &(TOP.cpu__DOT__pc_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"rd", &(TOP.cpu__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"read_reg1", &(TOP.cpu__DOT__read_reg1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"read_reg2", &(TOP.cpu__DOT__read_reg2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"reg_write", &(TOP.cpu__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"result_src", &(TOP.cpu__DOT__result_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"rst_n", &(TOP.cpu__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"store_data", &(TOP.cpu__DOT__store_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"writeback_data", &(TOP.cpu__DOT__writeback_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"alu_control", &(TOP.cpu__DOT__u_alu__DOT__alu_control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__u_alu__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"last_bit", &(TOP.cpu__DOT__u_alu__DOT__last_bit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"shamt", &(TOP.cpu__DOT__u_alu__DOT__shamt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"src1", &(TOP.cpu__DOT__u_alu__DOT__src1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"src2", &(TOP.cpu__DOT__u_alu__DOT__src2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_alu.varInsert(__Vfinal,"zero", &(TOP.cpu__DOT__u_alu__DOT__zero), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"alu_control", &(TOP.cpu__DOT__u_control__DOT__alu_control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"alu_src", &(TOP.cpu__DOT__u_control__DOT__alu_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"branch", &(TOP.cpu__DOT__u_control__DOT__branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"branch_type", &(TOP.cpu__DOT__u_control__DOT__branch_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"funct3", &(TOP.cpu__DOT__u_control__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"funct7", &(TOP.cpu__DOT__u_control__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"imm_source", &(TOP.cpu__DOT__u_control__DOT__imm_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"jump", &(TOP.cpu__DOT__u_control__DOT__jump), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"mem_write", &(TOP.cpu__DOT__u_control__DOT__mem_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"opcode", &(TOP.cpu__DOT__u_control__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"reg_write", &(TOP.cpu__DOT__u_control__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_control.varInsert(__Vfinal,"result_src", &(TOP.cpu__DOT__u_control__DOT__result_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__u_pc.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__u_pc__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_pc.varInsert(__Vfinal,"next_pc", &(TOP.cpu__DOT__u_pc__DOT__next_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_pc.varInsert(__Vfinal,"pc", &(TOP.cpu__DOT__u_pc__DOT__pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_pc.varInsert(__Vfinal,"reset", &(TOP.cpu__DOT__u_pc__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__u_reader__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"funct3", &(TOP.cpu__DOT__u_reader__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"mem_data", &(TOP.cpu__DOT__u_reader__DOT__mem_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"offset", &(TOP.cpu__DOT__u_reader__DOT__offset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"read_data", &(TOP.cpu__DOT__u_reader__DOT__read_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_reader.varInsert(__Vfinal,"sign_extend", &(TOP.cpu__DOT__u_reader__DOT__sign_extend), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__u_regfile__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"data1", &(TOP.cpu__DOT__u_regfile__DOT__data1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"data2", &(TOP.cpu__DOT__u_regfile__DOT__data2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"i", &(TOP.cpu__DOT__u_regfile__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"rd", &(TOP.cpu__DOT__u_regfile__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"registers", &(TOP.cpu__DOT__u_regfile__DOT__registers), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,31 ,31,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__u_regfile__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__u_regfile__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__u_regfile__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"write_data", &(TOP.cpu__DOT__u_regfile__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_regfile.varInsert(__Vfinal,"write_enable", &(TOP.cpu__DOT__u_regfile__DOT__write_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__u_signext.varInsert(__Vfinal,"imm_source", &(TOP.cpu__DOT__u_signext__DOT__imm_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_signext.varInsert(__Vfinal,"immediate", &(TOP.cpu__DOT__u_signext__DOT__immediate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_signext.varInsert(__Vfinal,"raw_src", &(TOP.cpu__DOT__u_signext__DOT__raw_src), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,24,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__u_store_decoder__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"byte_enable", &(TOP.cpu__DOT__u_store_decoder__DOT__byte_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"data", &(TOP.cpu__DOT__u_store_decoder__DOT__data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"funct3", &(TOP.cpu__DOT__u_store_decoder__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"offset", &(TOP.cpu__DOT__u_store_decoder__DOT__offset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__u_store_decoder.varInsert(__Vfinal,"reg_read", &(TOP.cpu__DOT__u_store_decoder__DOT__reg_read), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_ADD", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_ADD))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_AND", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_AND))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_OR", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_OR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SLL", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SLL))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SLT", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SLT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SLTU", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SLTU))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SRA", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SRA))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SRC_IMM", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SRC_IMM))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SRC_REG", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SRC_REG))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SRL", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SRL))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_SUB", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_SUB))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"ALU_XOR", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.ALU_XOR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BEQ", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BEQ))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BGE", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BGE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BGEU", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BGEU))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BLT", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BLT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BLTU", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BLTU))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"BR_BNE", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.BR_BNE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"IMM_B", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.IMM_B))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"IMM_I", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.IMM_I))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"IMM_J", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.IMM_J))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"IMM_S", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.IMM_S))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"IMM_U", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.IMM_U))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_AUIPC", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_AUIPC))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_BRANCH", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_BRANCH))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_ITYPE", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_ITYPE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_JAL", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_JAL))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_JALR", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_JALR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_LOAD", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_LOAD))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_LUI", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_LUI))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_RTYPE", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_RTYPE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"OPCODE_STORE", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.OPCODE_STORE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"WRITEBACK_ALU", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.WRITEBACK_ALU))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"WRITEBACK_IMM", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.WRITEBACK_IMM))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"WRITEBACK_MEMORY", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.WRITEBACK_MEMORY))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu_package.varInsert(__Vfinal,"WRITEBACK_PC4", const_cast<void*>(static_cast<const void*>(&(TOP__cpu_package.WRITEBACK_PC4))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
    }
}
