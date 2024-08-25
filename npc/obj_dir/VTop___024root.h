// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class VTop__Syms;
class VTop___024unit;


class VTop___024root final : public VerilatedModule {
  public:
    // CELLS
    VTop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_exit,0,0);
    VL_IN8(io_coreRun,0,0);
    CData/*0:0*/ Top__DOT__core__DOT___ebreakModule_exit_ebreak;
    CData/*0:0*/ Top__DOT__core__DOT___GEN_1;
    CData/*4:0*/ Top__DOT__core__DOT__csignals_0;
    CData/*0:0*/ Top__DOT__core__DOT___GEN_2;
    CData/*0:0*/ Top__DOT__core__DOT___GEN_3;
    CData/*1:0*/ Top__DOT__core__DOT__csignals_1;
    CData/*0:0*/ Top__DOT__core__DOT___GEN_4;
    CData/*1:0*/ Top__DOT__core__DOT__csignals_5;
    CData/*0:0*/ Top__DOT__core__DOT___br_flg_T_13;
    CData/*0:0*/ Top__DOT__core__DOT__exitEbreakReg;
    CData/*0:0*/ Top__DOT__core__DOT____VdfgTmp_hbc800c22__0;
    CData/*7:0*/ Top__DOT__memory__DOT___mem_ext_R0_data;
    CData/*7:0*/ Top__DOT__memory__DOT___mem_ext_R1_data;
    CData/*7:0*/ Top__DOT__memory__DOT___mem_ext_R3_data;
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ Top__DOT__core__DOT___GEN;
    SData/*15:0*/ __VdfgTmp_h0d09a3a3__0;
    IData/*31:0*/ Top__DOT___memory_io_imem_inst;
    IData/*31:0*/ Top__DOT___core_io_dmem_addr;
    IData/*31:0*/ Top__DOT__core__DOT___regfile_ext_R0_data;
    IData/*31:0*/ Top__DOT__core__DOT__pc_reg;
    IData/*31:0*/ Top__DOT__core__DOT___pc_plus4_T;
    IData/*16:0*/ Top__DOT__core__DOT___GEN_0;
    IData/*31:0*/ Top__DOT__core__DOT__op1_data;
    IData/*31:0*/ Top__DOT__core__DOT__casez_tmp;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_31;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_4;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_7;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_9;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_11;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_18;
    IData/*31:0*/ Top__DOT__core__DOT___alu_out_T_22;
    IData/*31:0*/ Top__DOT__core__DOT___GEN_7;
    IData/*23:0*/ __VdfgTmp_hf51a5acc__0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> Top__DOT__core__DOT__regfile_ext__DOT__Memory;
    VlUnpacked<CData/*7:0*/, 16384> Top__DOT__memory__DOT__mem_ext__DOT__Memory;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
