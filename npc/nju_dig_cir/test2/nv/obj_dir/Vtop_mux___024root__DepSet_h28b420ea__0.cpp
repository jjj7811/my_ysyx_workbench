// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_mux.h for the primary calling header

#include "verilated.h"

#include "Vtop_mux___024root.h"

VL_INLINE_OPT void Vtop_mux___024root___ico_sequent__TOP__0(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__hit = ((IData)(vlSelf->s) 
                                                   == 
                                                   vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list
                                                   [0U]);
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__hit = ((IData)(vlSelf->top_mux__DOT__i0__DOT__i0__DOT__hit) 
                                                   | ((IData)(vlSelf->s) 
                                                      == 
                                                      vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list
                                                      [1U]));
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__pair_list[0U] 
        = (2U | (IData)(vlSelf->b));
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__pair_list[1U] 
        = vlSelf->a;
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelf->b;
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelf->a;
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->s) == vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top_mux__DOT__i0__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top_mux__DOT__i0__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->s) == vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top_mux__DOT__i0__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->y = vlSelf->top_mux__DOT__i0__DOT__i0__DOT__lut_out;
}

void Vtop_mux___024root___eval_ico(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop_mux___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop_mux___024root___eval_act(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_act\n"); );
}

void Vtop_mux___024root___eval_nba(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_nba\n"); );
}

void Vtop_mux___024root___eval_triggers__ico(Vtop_mux___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__ico(Vtop_mux___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_mux___024root___eval_triggers__act(Vtop_mux___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__act(Vtop_mux___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__nba(Vtop_mux___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_mux___024root___eval(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop_mux___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop_mux___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test1_nv/vsrc/top_mux.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop_mux___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop_mux___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop_mux___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test1_nv/vsrc/top_mux.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop_mux___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop_mux___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test1_nv/vsrc/top_mux.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop_mux___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop_mux___024root___eval_debug_assertions(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xfeU))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xfeU))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((vlSelf->s & 0xfeU))) {
        Verilated::overWidthError("s");}
}
#endif  // VL_DEBUG
