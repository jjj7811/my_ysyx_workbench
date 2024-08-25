// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/hehe/ysyx-workbench/npc/build/Top.sv", 58, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_exit = VL_RAND_RESET_I(1);
    vlSelf->io_coreRun = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT___memory_io_imem_inst = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT___core_io_dmem_addr = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___ebreakModule_exit_ebreak = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___pc_plus4_T = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___GEN = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__core__DOT___GEN_0 = VL_RAND_RESET_I(17);
    vlSelf->Top__DOT__core__DOT___GEN_1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__csignals_0 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__core__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__csignals_1 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT___GEN_4 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT__csignals_5 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__core__DOT__op1_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__casez_tmp = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_31 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_9 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_11 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_18 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___alu_out_T_22 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT___br_flg_T_13 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT___GEN_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__core__DOT__exitEbreakReg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__core__DOT____VdfgTmp_hbc800c22__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__VdfgTmp_hf51a5acc__0 = 0;
    vlSelf->__VdfgTmp_h0d09a3a3__0 = 0;
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
