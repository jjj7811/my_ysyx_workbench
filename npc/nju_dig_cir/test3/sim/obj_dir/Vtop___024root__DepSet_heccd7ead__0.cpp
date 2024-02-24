// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if ((4U & (IData)(vlSelf->op))) {
        if ((2U & (IData)(vlSelf->op))) {
            if ((1U & (IData)(vlSelf->op))) {
                vlSelf->result = (((IData)(vlSelf->a) 
                                   == (IData)(vlSelf->top__DOT__b_reg))
                                   ? 1U : 0U);
            } else if (((1U & ((IData)(vlSelf->a) >> 3U)) 
                        == (1U & ((IData)(vlSelf->top__DOT__b_reg) 
                                  >> 3U)))) {
                vlSelf->result = (((IData)(vlSelf->a) 
                                   < (IData)(vlSelf->top__DOT__b_reg))
                                   ? 1U : 0U);
            } else {
                if ((IData)(((~ ((IData)(vlSelf->a) 
                                 >> 3U)) & ((IData)(vlSelf->top__DOT__b_reg) 
                                            >> 3U)))) {
                    vlSelf->result = 0U;
                }
                if ((IData)((((IData)(vlSelf->a) >> 3U) 
                             & (~ ((IData)(vlSelf->top__DOT__b_reg) 
                                   >> 3U))))) {
                    vlSelf->result = 1U;
                }
            }
        } else {
            vlSelf->result = ((1U & (IData)(vlSelf->op))
                               ? ((IData)(vlSelf->a) 
                                  ^ (IData)(vlSelf->top__DOT__b_reg))
                               : ((IData)(vlSelf->a) 
                                  | (IData)(vlSelf->top__DOT__b_reg)));
        }
    } else if ((2U & (IData)(vlSelf->op))) {
        vlSelf->result = (0xfU & ((1U & (IData)(vlSelf->op))
                                   ? ((IData)(vlSelf->a) 
                                      & (IData)(vlSelf->top__DOT__b_reg))
                                   : (~ (IData)(vlSelf->a))));
    } else if ((1U & (IData)(vlSelf->op))) {
        vlSelf->top__DOT__b_reg = (0xfU & ((IData)(1U) 
                                           + (~ (IData)(vlSelf->top__DOT__b_reg))));
        vlSelf->out = (1U & (((IData)(vlSelf->a) + (IData)(vlSelf->top__DOT__b_reg)) 
                             >> 4U));
        vlSelf->result = (0xfU & ((IData)(vlSelf->a) 
                                  + (IData)(vlSelf->top__DOT__b_reg)));
    } else {
        vlSelf->out = (1U & (((IData)(vlSelf->a) + (IData)(vlSelf->top__DOT__b_reg)) 
                             >> 4U));
        vlSelf->result = (0xfU & ((IData)(vlSelf->a) 
                                  + (IData)(vlSelf->top__DOT__b_reg)));
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test3/sim/vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test3/sim/vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->op & 0xf8U))) {
        Verilated::overWidthError("op");}
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
