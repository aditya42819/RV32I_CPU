// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.cpu__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.cpu__DOT__data_rdata = vlSelfRef.data_rdata;
    vlSelfRef.cpu__DOT__pc = vlSelfRef.cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.cpu__DOT__instr_rdata = vlSelfRef.instr_rdata;
    vlSelfRef.cpu__DOT__u_pc__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__u_regfile__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__u_pc__DOT__reset = (1U & (~ (IData)(vlSelfRef.cpu__DOT__rst_n)));
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

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlySet__cpu__DOT__u_regfile__DOT__registers__v0;
    __VdlySet__cpu__DOT__u_regfile__DOT__registers__v0 = 0;
    IData/*31:0*/ __VdlyVal__cpu__DOT__u_regfile__DOT__registers__v32;
    __VdlyVal__cpu__DOT__u_regfile__DOT__registers__v32 = 0;
    CData/*4:0*/ __VdlyDim0__cpu__DOT__u_regfile__DOT__registers__v32;
    __VdlyDim0__cpu__DOT__u_regfile__DOT__registers__v32 = 0;
    CData/*0:0*/ __VdlySet__cpu__DOT__u_regfile__DOT__registers__v32;
    __VdlySet__cpu__DOT__u_regfile__DOT__registers__v32 = 0;
    // Body
    __VdlySet__cpu__DOT__u_regfile__DOT__registers__v0 = 0U;
    __VdlySet__cpu__DOT__u_regfile__DOT__registers__v32 = 0U;
    if (vlSelfRef.cpu__DOT__u_regfile__DOT__rst) {
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 1U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 2U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 3U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 4U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 5U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 6U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 7U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 8U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 9U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xaU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xbU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xcU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xdU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xeU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0xfU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x10U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x11U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x12U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x13U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x14U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x15U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x16U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x17U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x18U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x19U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1aU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1bU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1cU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1dU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1eU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x1fU;
        vlSelfRef.cpu__DOT__u_regfile__DOT__i = 0x20U;
        __VdlySet__cpu__DOT__u_regfile__DOT__registers__v0 = 1U;
    } else if (((IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__write_enable) 
                & (0U != (IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__rd)))) {
        __VdlyVal__cpu__DOT__u_regfile__DOT__registers__v32 
            = vlSelfRef.cpu__DOT__u_regfile__DOT__write_data;
        __VdlyDim0__cpu__DOT__u_regfile__DOT__registers__v32 
            = vlSelfRef.cpu__DOT__u_regfile__DOT__rd;
        __VdlySet__cpu__DOT__u_regfile__DOT__registers__v32 = 1U;
    }
    if (__VdlySet__cpu__DOT__u_regfile__DOT__registers__v0) {
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[1U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[2U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[3U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[4U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[5U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[6U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[7U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[8U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[9U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xaU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xbU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xcU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xdU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xeU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0xfU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x10U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x11U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x12U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x13U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x14U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x15U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x16U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x17U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x18U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x19U] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1aU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1bU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1cU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1dU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1eU] = 0U;
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[0x1fU] = 0U;
    }
    if (__VdlySet__cpu__DOT__u_regfile__DOT__registers__v32) {
        vlSelfRef.cpu__DOT__u_regfile__DOT__registers[__VdlyDim0__cpu__DOT__u_regfile__DOT__registers__v32] 
            = __VdlyVal__cpu__DOT__u_regfile__DOT__registers__v32;
    }
    vlSelfRef.cpu__DOT__u_regfile__DOT__data1 = ((0U 
                                                  == (IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__rs1))
                                                  ? 0U
                                                  : 
                                                 vlSelfRef.cpu__DOT__u_regfile__DOT__registers
                                                 [vlSelfRef.cpu__DOT__u_regfile__DOT__rs1]);
    vlSelfRef.cpu__DOT__u_regfile__DOT__data2 = ((0U 
                                                  == (IData)(vlSelfRef.cpu__DOT__u_regfile__DOT__rs2))
                                                  ? 0U
                                                  : 
                                                 vlSelfRef.cpu__DOT__u_regfile__DOT__registers
                                                 [vlSelfRef.cpu__DOT__u_regfile__DOT__rs2]);
    vlSelfRef.cpu__DOT__read_reg1 = vlSelfRef.cpu__DOT__u_regfile__DOT__data1;
    vlSelfRef.cpu__DOT__read_reg2 = vlSelfRef.cpu__DOT__u_regfile__DOT__data2;
    vlSelfRef.cpu__DOT__u_store_decoder__DOT__reg_read 
        = vlSelfRef.cpu__DOT__read_reg2;
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
    vlSelfRef.cpu__DOT__alu_src2 = ((IData)(vlSelfRef.cpu__DOT__alu_src)
                                     ? vlSelfRef.cpu__DOT__immediate
                                     : vlSelfRef.cpu__DOT__read_reg2);
    vlSelfRef.cpu__DOT__u_alu__DOT__src2 = vlSelfRef.cpu__DOT__alu_src2;
    vlSelfRef.cpu__DOT__u_alu__DOT__shamt = (0x1fU 
                                             & vlSelfRef.cpu__DOT__u_alu__DOT__src2);
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__u_pc__DOT__pc = ((IData)(vlSelfRef.cpu__DOT__u_pc__DOT__reset)
                                          ? 0U : vlSelfRef.cpu__DOT__u_pc__DOT__next_pc);
    vlSelfRef.cpu__DOT__pc = vlSelfRef.cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.cpu__DOT__instr_address = vlSelfRef.cpu__DOT__pc;
    vlSelfRef.cpu__DOT__pc_plus4 = ((IData)(4U) + vlSelfRef.cpu__DOT__pc);
    vlSelfRef.instr_address = vlSelfRef.cpu__DOT__instr_address;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__alu_src1 = ((0x17U == (IData)(vlSelfRef.cpu__DOT__opcode))
                                     ? vlSelfRef.cpu__DOT__pc
                                     : vlSelfRef.cpu__DOT__read_reg1);
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
    vlSelfRef.cpu__DOT__u_alu__DOT__src1 = vlSelfRef.cpu__DOT__alu_src1;
    vlSelfRef.cpu__DOT__u_pc__DOT__next_pc = vlSelfRef.cpu__DOT__pc_next;
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

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl\\cpu.sv", 5, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl\\cpu.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl\\cpu.sv", 5, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
