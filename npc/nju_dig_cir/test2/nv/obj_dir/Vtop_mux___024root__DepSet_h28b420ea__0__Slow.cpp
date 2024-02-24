// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_mux.h for the primary calling header

#include "verilated.h"

#include "Vtop_mux___024root.h"

VL_ATTR_COLD void Vtop_mux___024root___eval_static(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop_mux___024root___eval_initial__TOP(Vtop_mux___024root* vlSelf);

VL_ATTR_COLD void Vtop_mux___024root___eval_initial(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_initial\n"); );
    // Body
    Vtop_mux___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop_mux___024root___eval_initial__TOP(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list[1U] = 0U;
}

VL_ATTR_COLD void Vtop_mux___024root___eval_final(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop_mux___024root___eval_triggers__stl(Vtop_mux___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__stl(Vtop_mux___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___eval_stl(Vtop_mux___024root* vlSelf);

VL_ATTR_COLD void Vtop_mux___024root___eval_settle(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop_mux___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop_mux___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/nju_dig_cir/test1_nv/vsrc/top_mux.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop_mux___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__stl(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop_mux___024root___ico_sequent__TOP__0(Vtop_mux___024root* vlSelf);

VL_ATTR_COLD void Vtop_mux___024root___eval_stl(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop_mux___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__ico(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__act(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_mux___024root___dump_triggers__nba(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_mux___024root___ctor_var_reset(Vtop_mux___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_mux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_mux___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = 0;
    vlSelf->b = 0;
    vlSelf->s = 0;
    vlSelf->y = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top_mux__DOT__i0__DOT__i0__DOT__pair_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top_mux__DOT__i0__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top_mux__DOT__i0__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__lut_out = 0;
    vlSelf->top_mux__DOT__i0__DOT__i0__DOT__hit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
