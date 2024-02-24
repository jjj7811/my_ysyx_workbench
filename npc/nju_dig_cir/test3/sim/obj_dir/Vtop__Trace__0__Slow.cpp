// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+14,"A", false,-1, 3,0);
    tracep->declBus(c+15,"B", false,-1, 3,0);
    tracep->declBit(c+16,"Ci", false,-1);
    tracep->declBus(c+17,"S", false,-1, 3,0);
    tracep->declBit(c+18,"Co1", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+14,"A", false,-1, 3,0);
    tracep->declBus(c+15,"B", false,-1, 3,0);
    tracep->declBit(c+16,"Ci", false,-1);
    tracep->declBus(c+17,"S", false,-1, 3,0);
    tracep->declBit(c+18,"Co1", false,-1);
    tracep->declBus(c+19,"C", false,-1, 3,0);
    tracep->declBit(c+20,"Co", false,-1);
    tracep->pushNamePrefix("u1 ");
    tracep->declBit(c+21,"A", false,-1);
    tracep->declBit(c+22,"B", false,-1);
    tracep->declBit(c+16,"Ci", false,-1);
    tracep->declBit(c+23,"S", false,-1);
    tracep->declBit(c+1,"Co", false,-1);
    tracep->declBit(c+24,"c_1", false,-1);
    tracep->declBit(c+25,"c_2", false,-1);
    tracep->declBit(c+2,"sum_1", false,-1);
    tracep->pushNamePrefix("add_half_1 ");
    tracep->declBit(c+21,"A", false,-1);
    tracep->declBit(c+22,"B", false,-1);
    tracep->declBit(c+2,"S", false,-1);
    tracep->declBit(c+24,"C", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("add_half_2 ");
    tracep->declBit(c+2,"A", false,-1);
    tracep->declBit(c+16,"B", false,-1);
    tracep->declBit(c+23,"S", false,-1);
    tracep->declBit(c+25,"C", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u2 ");
    tracep->declBit(c+26,"A", false,-1);
    tracep->declBit(c+27,"B", false,-1);
    tracep->declBit(c+1,"Ci", false,-1);
    tracep->declBit(c+3,"S", false,-1);
    tracep->declBit(c+4,"Co", false,-1);
    tracep->declBit(c+28,"c_1", false,-1);
    tracep->declBit(c+5,"c_2", false,-1);
    tracep->declBit(c+6,"sum_1", false,-1);
    tracep->pushNamePrefix("add_half_1 ");
    tracep->declBit(c+26,"A", false,-1);
    tracep->declBit(c+27,"B", false,-1);
    tracep->declBit(c+6,"S", false,-1);
    tracep->declBit(c+28,"C", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("add_half_2 ");
    tracep->declBit(c+6,"A", false,-1);
    tracep->declBit(c+1,"B", false,-1);
    tracep->declBit(c+3,"S", false,-1);
    tracep->declBit(c+5,"C", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u3 ");
    tracep->declBit(c+29,"A", false,-1);
    tracep->declBit(c+30,"B", false,-1);
    tracep->declBit(c+4,"Ci", false,-1);
    tracep->declBit(c+7,"S", false,-1);
    tracep->declBit(c+8,"Co", false,-1);
    tracep->declBit(c+31,"c_1", false,-1);
    tracep->declBit(c+9,"c_2", false,-1);
    tracep->declBit(c+10,"sum_1", false,-1);
    tracep->pushNamePrefix("add_half_1 ");
    tracep->declBit(c+29,"A", false,-1);
    tracep->declBit(c+30,"B", false,-1);
    tracep->declBit(c+10,"S", false,-1);
    tracep->declBit(c+31,"C", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("add_half_2 ");
    tracep->declBit(c+10,"A", false,-1);
    tracep->declBit(c+4,"B", false,-1);
    tracep->declBit(c+7,"S", false,-1);
    tracep->declBit(c+9,"C", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u4 ");
    tracep->declBit(c+32,"A", false,-1);
    tracep->declBit(c+33,"B", false,-1);
    tracep->declBit(c+8,"Ci", false,-1);
    tracep->declBit(c+11,"S", false,-1);
    tracep->declBit(c+20,"Co", false,-1);
    tracep->declBit(c+34,"c_1", false,-1);
    tracep->declBit(c+12,"c_2", false,-1);
    tracep->declBit(c+13,"sum_1", false,-1);
    tracep->pushNamePrefix("add_half_1 ");
    tracep->declBit(c+32,"A", false,-1);
    tracep->declBit(c+33,"B", false,-1);
    tracep->declBit(c+13,"S", false,-1);
    tracep->declBit(c+34,"C", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("add_half_2 ");
    tracep->declBit(c+13,"A", false,-1);
    tracep->declBit(c+8,"B", false,-1);
    tracep->declBit(c+11,"S", false,-1);
    tracep->declBit(c+12,"C", false,-1);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT____Vcellinp__u2__Ci));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__u1__DOT__sum_1));
    bufp->fullBit(oldp+3,(((IData)(vlSelf->top__DOT__u2__DOT__sum_1) 
                           ^ (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))));
    bufp->fullBit(oldp+4,(vlSelf->top__DOT____Vcellinp__u3__Ci));
    bufp->fullBit(oldp+5,(((IData)(vlSelf->top__DOT__u2__DOT__sum_1) 
                           & (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__u2__DOT__sum_1));
    bufp->fullBit(oldp+7,(((IData)(vlSelf->top__DOT__u3__DOT__sum_1) 
                           ^ (IData)(vlSelf->top__DOT____Vcellinp__u3__Ci))));
    bufp->fullBit(oldp+8,(vlSelf->top__DOT____Vcellinp__u4__Ci));
    bufp->fullBit(oldp+9,(((IData)(vlSelf->top__DOT__u3__DOT__sum_1) 
                           & (IData)(vlSelf->top__DOT____Vcellinp__u3__Ci))));
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__u3__DOT__sum_1));
    bufp->fullBit(oldp+11,(((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                            ^ (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))));
    bufp->fullBit(oldp+12,(((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                            & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__u4__DOT__sum_1));
    bufp->fullCData(oldp+14,(vlSelf->A),4);
    bufp->fullCData(oldp+15,(vlSelf->B),4);
    bufp->fullBit(oldp+16,(vlSelf->Ci));
    bufp->fullCData(oldp+17,(vlSelf->S),4);
    bufp->fullBit(oldp+18,(vlSelf->Co1));
    bufp->fullCData(oldp+19,(((8U & ((0xfffffff8U & 
                                      ((IData)(vlSelf->A) 
                                       & (IData)(vlSelf->B))) 
                                     | (((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                                         & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci)) 
                                        << 3U))) | 
                              (((IData)(vlSelf->top__DOT____Vcellinp__u4__Ci) 
                                << 2U) | (((IData)(vlSelf->top__DOT____Vcellinp__u3__Ci) 
                                           << 1U) | (IData)(vlSelf->top__DOT____Vcellinp__u2__Ci))))),4);
    bufp->fullBit(oldp+20,((1U & ((((IData)(vlSelf->A) 
                                    & (IData)(vlSelf->B)) 
                                   >> 3U) | ((IData)(vlSelf->top__DOT__u4__DOT__sum_1) 
                                             & (IData)(vlSelf->top__DOT____Vcellinp__u4__Ci))))));
    bufp->fullBit(oldp+21,((1U & (IData)(vlSelf->A))));
    bufp->fullBit(oldp+22,((1U & (IData)(vlSelf->B))));
    bufp->fullBit(oldp+23,(((IData)(vlSelf->top__DOT__u1__DOT__sum_1) 
                            ^ (IData)(vlSelf->Ci))));
    bufp->fullBit(oldp+24,((1U & ((IData)(vlSelf->A) 
                                  & (IData)(vlSelf->B)))));
    bufp->fullBit(oldp+25,(((IData)(vlSelf->top__DOT__u1__DOT__sum_1) 
                            & (IData)(vlSelf->Ci))));
    bufp->fullBit(oldp+26,((1U & ((IData)(vlSelf->A) 
                                  >> 1U))));
    bufp->fullBit(oldp+27,((1U & ((IData)(vlSelf->B) 
                                  >> 1U))));
    bufp->fullBit(oldp+28,((1U & (((IData)(vlSelf->A) 
                                   & (IData)(vlSelf->B)) 
                                  >> 1U))));
    bufp->fullBit(oldp+29,((1U & ((IData)(vlSelf->A) 
                                  >> 2U))));
    bufp->fullBit(oldp+30,((1U & ((IData)(vlSelf->B) 
                                  >> 2U))));
    bufp->fullBit(oldp+31,((1U & (((IData)(vlSelf->A) 
                                   & (IData)(vlSelf->B)) 
                                  >> 2U))));
    bufp->fullBit(oldp+32,((1U & ((IData)(vlSelf->A) 
                                  >> 3U))));
    bufp->fullBit(oldp+33,((1U & ((IData)(vlSelf->B) 
                                  >> 3U))));
    bufp->fullBit(oldp+34,((1U & (((IData)(vlSelf->A) 
                                   & (IData)(vlSelf->B)) 
                                  >> 3U))));
}
