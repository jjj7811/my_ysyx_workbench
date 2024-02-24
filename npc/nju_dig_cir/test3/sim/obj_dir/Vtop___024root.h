// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(A,3,0);
    VL_IN8(B,3,0);
    VL_IN8(Ci,0,0);
    VL_OUT8(S,3,0);
    VL_OUT8(Co,0,0);
    CData/*0:0*/ top__DOT____Vcellinp__u2__Ci;
    CData/*0:0*/ top__DOT____Vcellinp__u3__Ci;
    CData/*0:0*/ top__DOT____Vcellinp__u4__Ci;
    CData/*0:0*/ top__DOT__u1__DOT__sum_1;
    CData/*0:0*/ top__DOT__u2__DOT__sum_1;
    CData/*0:0*/ top__DOT__u3__DOT__sum_1;
    CData/*0:0*/ top__DOT__u4__DOT__sum_1;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
