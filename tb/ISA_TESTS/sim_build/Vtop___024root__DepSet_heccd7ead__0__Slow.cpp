// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__u_pc__DOT__clk__0 
        = vlSelfRef.cpu__DOT__u_pc__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__u_regfile__DOT__clk__0 
        = vlSelfRef.cpu__DOT__u_regfile__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../rtl\\cpu.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.cpu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.cpu__DOT__data_rdata = vlSelfRef.data_rdata;
    vlSelfRef.cpu__DOT__pc = vlSelfRef.cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.cpu__DOT__instr_rdata = vlSelfRef.instr_rdata;
    vlSelfRef.cpu__DOT__u_pc__DOT__reset = (1U & (~ (IData)(vlSelfRef.cpu__DOT__rst_n)));
    vlSelfRef.cpu__DOT__u_pc__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__u_regfile__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__u_reader__DOT__mem_data = vlSelfRef.cpu__DOT__data_rdata;
    vlSelfRef.cpu__DOT__instr_address = vlSelfRef.cpu__DOT__pc;
    vlSelfRef.cpu__DOT__pc_plus4 = ((IData)(4U) + vlSelfRef.cpu__DOT__pc);
    vlSelfRef.cpu__DOT__rd = (0x1fU & (vlSelfRef.cpu__DOT__instr_rdata 
                                       >> 7U));
    vlSelfRef.cpu__DOT__funct7 = (vlSelfRef.cpu__DOT__instr_rdata 
                                  >> 0x19U);
    vlSelfRef.cpu__DOT__rs1 = (0x1fU & (vlSelfRef.cpu__DOT__instr_rdata 
                                        >> 0xfU));
    vlSelfRef.cpu__DOT__funct3 = (7U & (vlSelfRef.cpu__DOT__instr_rdata 
                                        >> 0xcU));
    vlSelfRef.cpu__DOT__u_signext__DOT__raw_src = (vlSelfRef.cpu__DOT__instr_rdata 
                                                   >> 7U);
    vlSelfRef.cpu__DOT__rs2 = (0x1fU & (vlSelfRef.cpu__DOT__instr_rdata 
                                        >> 0x14U));
    vlSelfRef.cpu__DOT__opcode = (0x7fU & vlSelfRef.cpu__DOT__instr_rdata);
    vlSelfRef.cpu__DOT__u_regfile__DOT__rst = vlSelfRef.cpu__DOT__u_pc__DOT__reset;
    vlSelfRef.instr_address = vlSelfRef.cpu__DOT__instr_address;
    vlSelfRef.cpu__DOT__u_regfile__DOT__rd = vlSelfRef.cpu__DOT__rd;
    vlSelfRef.cpu__DOT__u_control__DOT__funct7 = vlSelfRef.cpu__DOT__funct7;
    vlSelfRef.cpu__DOT__u_regfile__DOT__rs1 = vlSelfRef.cpu__DOT__rs1;
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__funct3 
        = vlSelfRef.cpu__DOT__funct3;
    vlSelfRef.cpu__DOT__u_reader__DOT__funct3 = vlSelfRef.cpu__DOT__funct3;
    vlSelfRef.cpu__DOT__u_control__DOT__funct3 = vlSelfRef.cpu__DOT__funct3;
    vlSelfRef.cpu__DOT__u_regfile__DOT__rs2 = vlSelfRef.cpu__DOT__rs2;
    vlSelfRef.cpu__DOT__u_control__DOT__opcode = vlSelfRef.cpu__DOT__opcode;
    vlSelfRef.cpu__DOT__u_regfile__DOT__data1 = ((0U 
                                                  == (IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__rs1))
                                                  ? 0U
                                                  : 
                                                 vlSelfRef.cpu__DOT__u_regfile__DOT__registers
                                                 [vlSelfRef.cpu__DOT__u_regfile__DOT__rs1]);
    vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend 
        = (1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3) 
                    >> 2U)));
    vlSelfRef.cpu__DOT__u_regfile__DOT__data2 = ((0U 
                                                  == (IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__rs2))
                                                  ? 0U
                                                  : 
                                                 vlSelfRef.cpu__DOT__u_regfile__DOT__registers
                                                 [vlSelfRef.cpu__DOT__u_regfile__DOT__rs2]);
    vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__mem_write = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                  >> 6U)))) {
        if ((0x20U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                                vlSelfRef.cpu__DOT__u_control__DOT__mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.cpu__DOT__u_control__DOT__result_src = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__branch = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__jump = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__branch_type = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 0U;
    vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 0U;
    if ((0x40U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                                vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                                vlSelfRef.cpu__DOT__u_control__DOT__result_src = 2U;
                                vlSelfRef.cpu__DOT__u_control__DOT__jump = 1U;
                                vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 3U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__result_src = 2U;
                            vlSelfRef.cpu__DOT__u_control__DOT__jump = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 0U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 2U;
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                                vlSelfRef.cpu__DOT__u_control__DOT__branch = 1U;
                                vlSelfRef.cpu__DOT__u_control__DOT__branch_type 
                                    = ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                        ? ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                ? 7U
                                                : 6U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                ? 5U
                                                : 4U))
                                        : ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                             ? 1U : 0U)));
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                                vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
            } else if ((8U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (~ (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode)))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
                        }
                    } else {
                        vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
                    }
                } else {
                    vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
                }
            } else {
                vlSelfRef.cpu__DOT__u_control__DOT__alu_control 
                    = ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                        ? 0U : ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                                 ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                                     ? 1U : 0U) : 0U));
            }
        } else {
            vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
        }
    } else if ((0x20U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__result_src = 3U;
                            vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 4U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                    }
                }
            }
            if ((8U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
            } else if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((1U & (~ (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode)))) {
                        vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
                    }
                } else {
                    vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
                }
            } else {
                vlSelfRef.cpu__DOT__u_control__DOT__alu_control 
                    = ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                        ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                            ? ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                     ? ((0x20U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct7))
                                         ? 7U : 6U)
                                     : 4U)) : ((2U 
                                                & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                    ? 5U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct7))
                                                     ? 1U
                                                     : 0U))))
                            : 0U) : 0U);
            }
        } else {
            vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 1U;
                        }
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 1U;
                        }
                    }
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 4U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                        vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 1U;
                        vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 0U;
                    }
                }
            }
            vlSelfRef.cpu__DOT__u_control__DOT__alu_control 
                = ((8U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                    ? 0U : ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                             ? 0U : ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                                      ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))
                                          ? ((4U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                              ? ((2U 
                                                  & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                   ? 2U
                                                   : 3U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                   ? 
                                                  ((0x20U 
                                                    & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 4U))
                                              : ((2U 
                                                  & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                   ? 9U
                                                   : 8U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__funct3))
                                                   ? 5U
                                                   : 0U)))
                                          : 0U) : 0U)));
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__alu_src = 1U;
                            vlSelfRef.cpu__DOT__u_control__DOT__imm_source = 0U;
                        }
                    }
                }
            }
            vlSelfRef.cpu__DOT__u_control__DOT__alu_control = 0U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_control__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__u_control__DOT__result_src = 1U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.cpu__DOT__read_reg1 = vlSelfRef.cpu__DOT__u_regfile__DOT__data1;
    vlSelfRef.cpu__DOT__read_reg2 = vlSelfRef.cpu__DOT__u_regfile__DOT__data2;
    vlSelfRef.cpu__DOT__reg_write = vlSelfRef.cpu__DOT__u_control__DOT__reg_write;
    vlSelfRef.cpu__DOT__mem_write = vlSelfRef.cpu__DOT__u_control__DOT__mem_write;
    vlSelfRef.cpu__DOT__result_src = vlSelfRef.cpu__DOT__u_control__DOT__result_src;
    vlSelfRef.cpu__DOT__branch = vlSelfRef.cpu__DOT__u_control__DOT__branch;
    vlSelfRef.cpu__DOT__jump = vlSelfRef.cpu__DOT__u_control__DOT__jump;
    vlSelfRef.cpu__DOT__branch_type = vlSelfRef.cpu__DOT__u_control__DOT__branch_type;
    vlSelfRef.cpu__DOT__alu_control = vlSelfRef.cpu__DOT__u_control__DOT__alu_control;
    vlSelfRef.cpu__DOT__alu_src = vlSelfRef.cpu__DOT__u_control__DOT__alu_src;
    vlSelfRef.cpu__DOT__imm_source = vlSelfRef.cpu__DOT__u_control__DOT__imm_source;
    vlSelfRef.cpu__DOT__alu_src1 = ((0x17U == (IData)(vlSelfRef.cpu__DOT__opcode))
                                     ? vlSelfRef.cpu__DOT__pc
                                     : vlSelfRef.cpu__DOT__read_reg1);
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read 
        = vlSelfRef.cpu__DOT__read_reg2;
    vlSelfRef.cpu__DOT__u_regfile__DOT__write_enable 
        = vlSelfRef.cpu__DOT__reg_write;
    vlSelfRef.cpu__DOT__data_writeenable = vlSelfRef.cpu__DOT__mem_write;
    vlSelfRef.cpu__DOT__branch_taken = ((4U & (IData)(vlSelfRef.cpu__DOT__branch_type))
                                         ? ((2U & (IData)(vlSelfRef.cpu__DOT__branch_type))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.cpu__DOT__branch_type))
                                                 ? 
                                                (vlSelfRef.cpu__DOT__read_reg1 
                                                 >= vlSelfRef.cpu__DOT__read_reg2)
                                                 : 
                                                (vlSelfRef.cpu__DOT__read_reg1 
                                                 < vlSelfRef.cpu__DOT__read_reg2))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.cpu__DOT__branch_type))
                                                 ? 
                                                VL_GTES_III(32, vlSelfRef.cpu__DOT__read_reg1, vlSelfRef.cpu__DOT__read_reg2)
                                                 : 
                                                VL_LTS_III(32, vlSelfRef.cpu__DOT__read_reg1, vlSelfRef.cpu__DOT__read_reg2)))
                                         : ((1U & (~ 
                                                   ((IData)(vlSelfRef.cpu__DOT__branch_type) 
                                                    >> 1U))) 
                                            && ((1U 
                                                 & (IData)(vlSelfRef.cpu__DOT__branch_type))
                                                 ? 
                                                (vlSelfRef.cpu__DOT__read_reg1 
                                                 != vlSelfRef.cpu__DOT__read_reg2)
                                                 : 
                                                (vlSelfRef.cpu__DOT__read_reg1 
                                                 == vlSelfRef.cpu__DOT__read_reg2))));
    vlSelfRef.cpu__DOT__u_alu__DOT__alu_control = vlSelfRef.cpu__DOT__alu_control;
    vlSelfRef.cpu__DOT__u_signext__DOT__imm_source 
        = vlSelfRef.cpu__DOT__imm_source;
    vlSelfRef.cpu__DOT__u_alu__DOT__src1 = vlSelfRef.cpu__DOT__alu_src1;
    vlSelfRef.data_writeenable = vlSelfRef.cpu__DOT__data_writeenable;
    vlSelfRef.cpu__DOT__u_signext__DOT__immediate = 
        ((4U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
          ? ((2U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
              ? 0U : ((1U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
                       ? 0U : (0xfffff000U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                              << 7U))))
          : ((2U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
              ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
                  ? ((((- (IData)((1U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                         >> 0x18U)))) 
                       << 0x15U) | (0x100000U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                                 >> 4U))) 
                     | (((0xff000U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                      << 7U)) | (0x800U 
                                                 & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                                    >> 2U))) 
                        | (0x7feU & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                     >> 0xdU)))) : 
                 (((- (IData)((1U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                     >> 0x18U)))) << 0xdU) 
                  | (((0x1000U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                  >> 0xcU)) | (0x800U 
                                               & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                                  << 0xbU))) 
                     | ((0x7e0U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                   >> 0xdU)) | (0x1eU 
                                                & vlSelfRef.cpu__DOT__u_signext__DOT__raw_src)))))
              : ((1U & (IData)(vlSelfRef.cpu__DOT__u_signext__DOT__imm_source))
                  ? (((- (IData)((1U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                        >> 0x18U)))) 
                      << 0xcU) | ((0xfe0U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                             >> 0xdU)) 
                                  | (0x1fU & vlSelfRef.cpu__DOT__u_signext__DOT__raw_src)))
                  : (((- (IData)((1U & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                        >> 0x18U)))) 
                      << 0xcU) | (0xfffU & (vlSelfRef.cpu__DOT__u_signext__DOT__raw_src 
                                            >> 0xdU))))));
    vlSelfRef.cpu__DOT__immediate = vlSelfRef.cpu__DOT__u_signext__DOT__immediate;
    vlSelfRef.cpu__DOT__pc_target = (((IData)(vlSelfRef.cpu__DOT__jump) 
                                      & (0x67U == (IData)(vlSelfRef.cpu__DOT__opcode)))
                                      ? (0xfffffffeU 
                                         & (vlSelfRef.cpu__DOT__read_reg1 
                                            + vlSelfRef.cpu__DOT__immediate))
                                      : (vlSelfRef.cpu__DOT__pc 
                                         + vlSelfRef.cpu__DOT__immediate));
    vlSelfRef.cpu__DOT__pc_next = (((IData)(vlSelfRef.cpu__DOT__jump) 
                                    | ((IData)(vlSelfRef.cpu__DOT__branch) 
                                       & (IData)(vlSelfRef.cpu__DOT__branch_taken)))
                                    ? vlSelfRef.cpu__DOT__pc_target
                                    : vlSelfRef.cpu__DOT__pc_plus4);
    vlSelfRef.cpu__DOT__alu_src2 = ((IData)(vlSelfRef.cpu__DOT__alu_src)
                                     ? vlSelfRef.cpu__DOT__immediate
                                     : vlSelfRef.cpu__DOT__read_reg2);
    vlSelfRef.cpu__DOT__u_pc__DOT__next_pc = vlSelfRef.cpu__DOT__pc_next;
    vlSelfRef.cpu__DOT__u_alu__DOT__src2 = vlSelfRef.cpu__DOT__alu_src2;
    vlSelfRef.cpu__DOT__u_alu__DOT__shamt = (0x1fU 
                                             & vlSelfRef.cpu__DOT__u_alu__DOT__src2);
    vlSelfRef.cpu__DOT__u_alu__DOT__alu_result = ((8U 
                                                   & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                      ? 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      < vlSelfRef.cpu__DOT__u_alu__DOT__src2)
                                                      : 
                                                     VL_LTS_III(32, vlSelfRef.cpu__DOT__u_alu__DOT__src1, vlSelfRef.cpu__DOT__u_alu__DOT__src2))))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelfRef.cpu__DOT__u_alu__DOT__src1, (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__shamt))
                                                      : 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      >> (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__shamt)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                      ? 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      << (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__shamt))
                                                      : 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      ^ vlSelfRef.cpu__DOT__u_alu__DOT__src2)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                      ? 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      | vlSelfRef.cpu__DOT__u_alu__DOT__src2)
                                                      : 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      & vlSelfRef.cpu__DOT__u_alu__DOT__src2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.cpu__DOT__u_alu__DOT__alu_control))
                                                      ? 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      - vlSelfRef.cpu__DOT__u_alu__DOT__src2)
                                                      : 
                                                     (vlSelfRef.cpu__DOT__u_alu__DOT__src1 
                                                      + vlSelfRef.cpu__DOT__u_alu__DOT__src2)))));
    vlSelfRef.cpu__DOT__u_alu__DOT__zero = (0U == vlSelfRef.cpu__DOT__u_alu__DOT__alu_result);
    vlSelfRef.cpu__DOT__u_alu__DOT__last_bit = (1U 
                                                & vlSelfRef.cpu__DOT__u_alu__DOT__alu_result);
    vlSelfRef.cpu__DOT__alu_result = vlSelfRef.cpu__DOT__u_alu__DOT__alu_result;
    vlSelfRef.cpu__DOT__alu_zero = vlSelfRef.cpu__DOT__u_alu__DOT__zero;
    vlSelfRef.cpu__DOT__alu_last_bit = vlSelfRef.cpu__DOT__u_alu__DOT__last_bit;
    vlSelfRef.cpu__DOT__data_address = (0xfffffffcU 
                                        & vlSelfRef.cpu__DOT__alu_result);
    vlSelfRef.cpu__DOT__u_reader__DOT__alu_result = vlSelfRef.cpu__DOT__alu_result;
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__alu_result 
        = vlSelfRef.cpu__DOT__alu_result;
    vlSelfRef.data_address = vlSelfRef.cpu__DOT__data_address;
    vlSelfRef.cpu__DOT__u_reader__DOT__offset = (3U 
                                                 & vlSelfRef.cpu__DOT__u_reader__DOT__alu_result);
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset 
        = (3U & vlSelfRef.cpu__DOT__u_store_decoder__DOT__alu_result);
    vlSelfRef.cpu__DOT__u_reader__DOT__read_data = 0U;
    if ((4U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))) {
        vlSelfRef.cpu__DOT__u_reader__DOT__read_data 
            = ((2U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))
                ? 0U : ((1U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))
                         ? ((0U == (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                             ? (((- (IData)(((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                             & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                >> 0xfU)))) 
                                 << 0x10U) | (0xffffU 
                                              & vlSelfRef.cpu__DOT__u_reader__DOT__mem_data))
                             : ((2U == (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                 ? (((- (IData)(((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                 & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                    >> 0x1fU)))) 
                                     << 0x10U) | (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                  >> 0x10U))
                                 : 0U)) : ((2U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                                ? (
                                                   ((- (IData)(
                                                               ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                                & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                                   >> 0x1fU)))) 
                                                    << 8U) 
                                                   | (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                      >> 0x18U))
                                                : (
                                                   ((- (IData)(
                                                               ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                                & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                                   >> 0x17U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                         >> 0x10U))))
                                            : ((1U 
                                                & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                                ? (
                                                   ((- (IData)(
                                                               ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                                & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                                   >> 0xfU)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                         >> 8U)))
                                                : (
                                                   ((- (IData)(
                                                               ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                                & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & vlSelfRef.cpu__DOT__u_reader__DOT__mem_data))))));
    } else if ((2U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))) {
        if ((1U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))) {
            vlSelfRef.cpu__DOT__u_reader__DOT__read_data = 0U;
        } else if ((0U == (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))) {
            vlSelfRef.cpu__DOT__u_reader__DOT__read_data 
                = vlSelfRef.cpu__DOT__u_reader__DOT__mem_data;
        }
    } else {
        vlSelfRef.cpu__DOT__u_reader__DOT__read_data 
            = ((1U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__funct3))
                ? ((0U == (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                    ? (((- (IData)(((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                    & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                       >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelfRef.cpu__DOT__u_reader__DOT__mem_data))
                    : ((2U == (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                        ? (((- (IData)(((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                        & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                           >> 0x1fU)))) 
                            << 0x10U) | (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                         >> 0x10U))
                        : 0U)) : ((2U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                   ? ((1U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                       ? (((- (IData)(
                                                      ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                       & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                          >> 0x1fU)))) 
                                           << 8U) | 
                                          (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                           >> 0x18U))
                                       : (((- (IData)(
                                                      ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                       & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                          >> 0x17U)))) 
                                           << 8U) | 
                                          (0xffU & 
                                           (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                            >> 0x10U))))
                                   : ((1U & (IData)(vlSelfRef.cpu__DOT__u_reader__DOT__offset))
                                       ? (((- (IData)(
                                                      ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                       & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                          >> 0xfU)))) 
                                           << 8U) | 
                                          (0xffU & 
                                           (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                            >> 8U)))
                                       : (((- (IData)(
                                                      ((IData)(vlSelfRef.cpu__DOT__u_reader__DOT__sign_extend) 
                                                       & (vlSelfRef.cpu__DOT__u_reader__DOT__mem_data 
                                                          >> 7U)))) 
                                           << 8U) | 
                                          (0xffU & vlSelfRef.cpu__DOT__u_reader__DOT__mem_data)))));
    }
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 0U;
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__data = 0U;
    if ((0U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__funct3))) {
        if ((2U & (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
            if ((1U & (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
                vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 8U;
                vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                    = (0xff000000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read, 0x18U));
            } else {
                vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 4U;
                vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                    = (0xff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read, 0x10U));
            }
        } else if ((1U & (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 2U;
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                = (0xff00U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read, 8U));
        } else {
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 1U;
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                = (0xffU & vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read);
        }
    } else if ((1U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__funct3))) {
        if ((0U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 3U;
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                = (0xffffU & vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read);
        } else if ((2U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 0xcU;
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                = (0xffff0000U & VL_SHIFTL_III(32,32,32, vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read, 0x10U));
        }
    } else if ((2U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__funct3))) {
        if ((0U == (IData)(vlSelfRef.cpu__DOT__u_store_decoder__DOT__offset))) {
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 0xfU;
            vlSelfRef.cpu__DOT__u_store_decoder__DOT__data 
                = vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read;
        }
    } else {
        vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable = 0U;
        vlSelfRef.cpu__DOT__u_store_decoder__DOT__data = 0U;
    }
    vlSelfRef.cpu__DOT__load_data = vlSelfRef.cpu__DOT__u_reader__DOT__read_data;
    vlSelfRef.cpu__DOT__data_byteenable = vlSelfRef.cpu__DOT__u_store_decoder__DOT__byte_enable;
    vlSelfRef.cpu__DOT__store_data = vlSelfRef.cpu__DOT__u_store_decoder__DOT__data;
    vlSelfRef.cpu__DOT__writeback_data = ((2U & (IData)(vlSelfRef.cpu__DOT__result_src))
                                           ? ((1U & (IData)(vlSelfRef.cpu__DOT__result_src))
                                               ? vlSelfRef.cpu__DOT__immediate
                                               : vlSelfRef.cpu__DOT__pc_plus4)
                                           : ((1U & (IData)(vlSelfRef.cpu__DOT__result_src))
                                               ? vlSelfRef.cpu__DOT__load_data
                                               : vlSelfRef.cpu__DOT__alu_result));
    vlSelfRef.data_byteenable = vlSelfRef.cpu__DOT__data_byteenable;
    vlSelfRef.cpu__DOT__data_writedata = vlSelfRef.cpu__DOT__store_data;
    vlSelfRef.cpu__DOT__u_regfile__DOT__write_data 
        = vlSelfRef.cpu__DOT__writeback_data;
    vlSelfRef.data_writedata = vlSelfRef.cpu__DOT__data_writedata;
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge cpu.u_pc.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge cpu.u_regfile.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge cpu.u_pc.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge cpu.u_regfile.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->instr_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4712298193835340436ull);
    vlSelf->instr_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3181702806383829202ull);
    vlSelf->data_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12399113995991721601ull);
    vlSelf->data_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4260269432610748637ull);
    vlSelf->data_writedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1408799313583733727ull);
    vlSelf->data_writeenable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2069982532302530785ull);
    vlSelf->data_byteenable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13053730330819058510ull);
    vlSelf->cpu__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12949139165289987104ull);
    vlSelf->cpu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5456728620559131056ull);
    vlSelf->cpu__DOT__instr_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3936520719888904911ull);
    vlSelf->cpu__DOT__instr_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16274080183876760724ull);
    vlSelf->cpu__DOT__data_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12428148270138729995ull);
    vlSelf->cpu__DOT__data_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11401522026226022857ull);
    vlSelf->cpu__DOT__data_writedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9202195654121565737ull);
    vlSelf->cpu__DOT__data_writeenable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8330124290785187486ull);
    vlSelf->cpu__DOT__data_byteenable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5606715893928523774ull);
    vlSelf->cpu__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12979896101630030509ull);
    vlSelf->cpu__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11401018961025754907ull);
    vlSelf->cpu__DOT__pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4310843936023622037ull);
    vlSelf->cpu__DOT__pc_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7171532589129608696ull);
    vlSelf->cpu__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 971283180709441233ull);
    vlSelf->cpu__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 15165713946348169142ull);
    vlSelf->cpu__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12318826599970682371ull);
    vlSelf->cpu__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16010416863125722875ull);
    vlSelf->cpu__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11012281022938861904ull);
    vlSelf->cpu__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3308832043106885690ull);
    vlSelf->cpu__DOT__read_reg1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1524000216712112607ull);
    vlSelf->cpu__DOT__read_reg2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12531379444480071751ull);
    vlSelf->cpu__DOT__writeback_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6688806397709919019ull);
    vlSelf->cpu__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7657775539254847072ull);
    vlSelf->cpu__DOT__alu_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6994684356585826222ull);
    vlSelf->cpu__DOT__alu_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8284561064640361552ull);
    vlSelf->cpu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12522730548817195188ull);
    vlSelf->cpu__DOT__store_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17835715224475333759ull);
    vlSelf->cpu__DOT__load_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2855694472809663856ull);
    vlSelf->cpu__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2478348765490579174ull);
    vlSelf->cpu__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4586295343091075808ull);
    vlSelf->cpu__DOT__branch_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11462445275788987092ull);
    vlSelf->cpu__DOT__result_src = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7306516822111752830ull);
    vlSelf->cpu__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 720716836299198197ull);
    vlSelf->cpu__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15999734060210743814ull);
    vlSelf->cpu__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4199765347900879115ull);
    vlSelf->cpu__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7205763434794021222ull);
    vlSelf->cpu__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16306447583709703151ull);
    vlSelf->cpu__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17161198845646111129ull);
    vlSelf->cpu__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 400036621919628728ull);
    vlSelf->cpu__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15068204652965702680ull);
    vlSelf->cpu__DOT__u_pc__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8094507945756357889ull);
    vlSelf->cpu__DOT__u_pc__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14170024602359071758ull);
    vlSelf->cpu__DOT__u_pc__DOT__next_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3595059854755319963ull);
    vlSelf->cpu__DOT__u_pc__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2978640177218797512ull);
    vlSelf->cpu__DOT__u_control__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 465066177826455003ull);
    vlSelf->cpu__DOT__u_control__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1692811327434664302ull);
    vlSelf->cpu__DOT__u_control__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 1246365172366619728ull);
    vlSelf->cpu__DOT__u_control__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16708373535940201471ull);
    vlSelf->cpu__DOT__u_control__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9108733476322701284ull);
    vlSelf->cpu__DOT__u_control__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9385884602540577268ull);
    vlSelf->cpu__DOT__u_control__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17968800761577600846ull);
    vlSelf->cpu__DOT__u_control__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10230106553556322885ull);
    vlSelf->cpu__DOT__u_control__DOT__result_src = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4880269728270788385ull);
    vlSelf->cpu__DOT__u_control__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11271397897289880837ull);
    vlSelf->cpu__DOT__u_control__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15511537441773847242ull);
    vlSelf->cpu__DOT__u_control__DOT__branch_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16439039349637353868ull);
    vlSelf->cpu__DOT__u_signext__DOT__raw_src = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8189636183503737801ull);
    vlSelf->cpu__DOT__u_signext__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15323278110869069578ull);
    vlSelf->cpu__DOT__u_signext__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17274080643302953866ull);
    vlSelf->cpu__DOT__u_alu__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7489431873747486594ull);
    vlSelf->cpu__DOT__u_alu__DOT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1475516262229688051ull);
    vlSelf->cpu__DOT__u_alu__DOT__src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2372690239303861ull);
    vlSelf->cpu__DOT__u_alu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6050904133822432105ull);
    vlSelf->cpu__DOT__u_alu__DOT__zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17345679317027539494ull);
    vlSelf->cpu__DOT__u_alu__DOT__last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7973621845128292988ull);
    vlSelf->cpu__DOT__u_alu__DOT__shamt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1051730893694562770ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13231535020893896452ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11892424358436662232ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__reg_read = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13641385866434507968ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15532464993650744317ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__byte_enable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4928310387294452409ull);
    vlSelf->cpu__DOT__u_store_decoder__DOT__offset = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4232863702995479661ull);
    vlSelf->cpu__DOT__u_reader__DOT__mem_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14670126369984397491ull);
    vlSelf->cpu__DOT__u_reader__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 929533172187148087ull);
    vlSelf->cpu__DOT__u_reader__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5237098006090412609ull);
    vlSelf->cpu__DOT__u_reader__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8014056039986221712ull);
    vlSelf->cpu__DOT__u_reader__DOT__offset = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15518318706504885915ull);
    vlSelf->cpu__DOT__u_reader__DOT__sign_extend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6989241869963716205ull);
    vlSelf->cpu__DOT__u_regfile__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13316098665770986737ull);
    vlSelf->cpu__DOT__u_regfile__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12602038073922989030ull);
    vlSelf->cpu__DOT__u_regfile__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16069738887571325628ull);
    vlSelf->cpu__DOT__u_regfile__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9799411622938150831ull);
    vlSelf->cpu__DOT__u_regfile__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2346944672932603306ull);
    vlSelf->cpu__DOT__u_regfile__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14688367925079326540ull);
    vlSelf->cpu__DOT__u_regfile__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17161738823858085104ull);
    vlSelf->cpu__DOT__u_regfile__DOT__data1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1668507811028166818ull);
    vlSelf->cpu__DOT__u_regfile__DOT__data2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11688315303533600084ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->cpu__DOT__u_regfile__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15083210001309143018ull);
    }
    vlSelf->cpu__DOT__u_regfile__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5137903452191602868ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__u_pc__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10636307462209897141ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__u_regfile__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15446909330502702098ull);
}
