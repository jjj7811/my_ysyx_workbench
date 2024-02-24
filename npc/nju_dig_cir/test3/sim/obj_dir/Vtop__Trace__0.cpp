// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT____Vcellinp__u2__Ci));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__u1__DOT__sum_1));
        bufp->chgBit(oldp+2,(((IData)(vlSelf->top__DOT__u2__DOT__sum_1) 
                              ^ (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))));
        bufp->chgBit(oldp+3,(vlSelf->top__DOT____Vcellinp__u3__Ci));
        bufp->chgBit(oldp+4,(((IData)(vlSelf->top__DOT__u2__DOT__sum_1) 
                              & (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__u2__DOT__sum_1));
        bufp->chgBit(oldp+6,(((IData)(vlSelf->top__DOT__u3__DOT__sum_1) 
                              ^ (IData)(vlSelf->top__DOT____Vcellinp__u3__Ci))));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT____Vcellinp__u4__Ci));
        bufp->chgBit(oldp+8,(((IData)(vlSelf->top__DOT__u3__DOT__sum_1) 
                              & (IData)(vlSelf->top__DOT____Vcellinp__u3__Ci))));
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__u3__DOT__sum_1));
        bufp->chgBit(oldp+10,(((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                               ^ (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))));
        bufp->chgBit(oldp+11,(((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                               & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))));
        bufp->chgBit(oldp+12,(vlSelf->top__DOT__u4__DOT__sum_1));
    }
    bufp->chgCData(oldp+13,(vlSelf->A),4);
    bufp->chgCData(oldp+14,(vlSelf->B),4);
    bufp->chgBit(oldp+15,(vlSelf->Ci));
    bufp->chgCData(oldp+16,(vlSelf->S),4);
    bufp->chgBit(oldp+17,(vlSelf->Cos));
    bufp->chgCData(oldp+18,(((8U & ((0xfffffff8U & 
                                     ((IData)(vlSelf->A) 
                                      & (IData)(vlSelf->B))) 
                                    | (((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                                        & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci)) 
                                       << 3U))) | (
                                                   ((IData)(vlSelf->top__DOT____Vcellinp__u4__Ci) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->top__DOT____Vcellinp__u3__Ci) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))))),4);
    bufp->chgBit(oldp+19,((1U & ((((IData)(vlSelf->A) 
                                   & (IData)(vlSelf->B)) 
                                  >> 3U) | ((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                                            & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))))));
    bufp->chgBit(oldp+20,((1U & (IData)(vlSelf->A))));
    bufp->chgBit(oldp+21,((1U & (IData)(vlSelf->B))));
    bufp->chgBit(oldp+22,(((IData)(vlSelf->top__DOT__u1__DOT__sum_1) 
                           ^ (IData)(vlSelf->Ci))));
    bufp->chgBit(oldp+23,((1U & ((IData)(vlSelf->A) 
                                 & (IData)(vlSelf->B)))));
    bufp->chgBit(oldp+24,(((IData)(vlSelf->top__DOT__u1__DOT__sum_1) 
                           & (IData)(vlSelf->Ci))));
    bufp->chgBit(oldp+25,((1U & ((IData)(vlSelf->A) 
                                 >> 1U))));
    bufp->chgBit(oldp+26,((1U & ((IData)(vlSelf->B) 
                                 >> 1U))));
    bufp->chgBit(oldp+27,((1U & (((IData)(vlSelf->A) 
                                  & (IData)(vlSelf->B)) 
                                 >> 1U))));
    bufp->chgBit(oldp+28,((1U & ((IData)(vlSelf->A) 
                                 >> 2U))));
    bufp->chgBit(oldp+29,((1U & ((IData)(vlSelf->B) 
                                 >> 2U))));
    bufp->chgBit(oldp+30,((1U & (((IData)(vlSelf->A) 
                                  & (IData)(vlSelf->B)) 
                                 >> 2U))));
    bufp->chgBit(oldp+31,((1U & ((IData)(vlSelf->A) 
                                 >> 3U))));
    bufp->chgBit(oldp+32,((1U & ((IData)(vlSelf->B) 
                                 >> 3U))));
    bufp->chgBit(oldp+33,((1U & (((IData)(vlSelf->A) 
                                  & (IData)(vlSelf->B)) 
                                 >> 3U))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
