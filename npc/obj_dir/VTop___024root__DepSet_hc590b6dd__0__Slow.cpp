// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void VTop___024unit____Vdpiimwrap_ebreak_TOP____024unit();

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_exit = vlSelf->Top__DOT__core__DOT__exitEbreakReg;
    vlSelf->Top__DOT__core__DOT___pc_plus4_T = ((IData)(4U) 
                                                + vlSelf->Top__DOT__core__DOT__pc_reg);
    vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data 
        = vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
        [(0x3fffU & ((IData)(3U) + vlSelf->Top__DOT__core__DOT__pc_reg))];
    vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data 
        = vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
        [(0x3fffU & ((IData)(1U) + vlSelf->Top__DOT__core__DOT__pc_reg))];
    vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data 
        = vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
        [(0x3fffU & vlSelf->Top__DOT__core__DOT__pc_reg)];
    vlSelf->Top__DOT__core__DOT___GEN_1 = ((0x37U == 
                                            (0x7fU 
                                             & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data))) 
                                           | (0x17U 
                                              == (0x7fU 
                                                  & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data))));
    vlSelf->__VdfgTmp_h0d09a3a3__0 = (((IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data) 
                                       << 8U) | (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data));
    vlSelf->Top__DOT__core__DOT___GEN = ((0x380U & 
                                          ((IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data) 
                                           << 3U)) 
                                         | (0x7fU & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)));
    vlSelf->__VdfgTmp_hf51a5acc__0 = ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                       [(0x3fffU & 
                                         ((IData)(2U) 
                                          + vlSelf->Top__DOT__core__DOT__pc_reg))] 
                                       << 0x10U) | (IData)(vlSelf->__VdfgTmp_h0d09a3a3__0));
    vlSelf->Top__DOT__core__DOT____VdfgTmp_hbc800c22__0 
        = ((0x6fU == (0x7fU & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data))) 
           | (0x67U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)));
    vlSelf->Top__DOT__core__DOT___GEN_4 = ((0x113U 
                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                           | (0x193U 
                                              == (IData)(vlSelf->Top__DOT__core__DOT___GEN)));
    vlSelf->Top__DOT__core__DOT___GEN_2 = ((0x63U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                           | ((0xe3U 
                                               == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                              | ((0x2e3U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                 | ((0x3e3U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                    | ((0x263U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                       | (0x363U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))))));
    vlSelf->Top__DOT__core__DOT___GEN_0 = ((0x1fc00U 
                                            & ((IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data) 
                                               << 9U)) 
                                           | (IData)(vlSelf->Top__DOT__core__DOT___GEN));
    vlSelf->Top__DOT___memory_io_imem_inst = (((IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data) 
                                               << 0x18U) 
                                              | vlSelf->__VdfgTmp_hf51a5acc__0);
    vlSelf->Top__DOT__core__DOT__csignals_0 = (((0x103U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                | ((0x123U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                   | ((0x33U 
                                                       == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                      | (0x13U 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))))
                                                ? 1U
                                                : (
                                                   (0x8033U 
                                                    == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                    ? 2U
                                                    : 
                                                   ((0x3b3U 
                                                     == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                     ? 3U
                                                     : 
                                                    ((0x333U 
                                                      == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                      ? 4U
                                                      : 
                                                     ((0x233U 
                                                       == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                       ? 5U
                                                       : 
                                                      ((0x393U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                        ? 3U
                                                        : 
                                                       ((0x313U 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                         ? 4U
                                                         : 
                                                        ((0x213U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                          ? 5U
                                                          : 
                                                         ((0xb3U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                           ? 6U
                                                           : 
                                                          ((0x2b3U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                            ? 7U
                                                            : 
                                                           ((0x82b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                             ? 8U
                                                             : 
                                                            ((0x93U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                              ? 6U
                                                              : 
                                                             ((0x293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                               ? 7U
                                                               : 
                                                              ((0x8293U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                                ? 8U
                                                                : 
                                                               ((0x133U 
                                                                 == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                                 ? 9U
                                                                 : 
                                                                ((0x1b3U 
                                                                  == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                                  ? 0xaU
                                                                  : 
                                                                 ((0x113U 
                                                                   == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                   ? 9U
                                                                   : 
                                                                  ((0x193U 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                    ? 0xaU
                                                                    : 
                                                                   ((0x63U 
                                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                     ? 0xbU
                                                                     : 
                                                                    ((0xe3U 
                                                                      == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                      ? 0xcU
                                                                      : 
                                                                     ((0x2e3U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                       ? 0xeU
                                                                       : 
                                                                      ((0x3e3U 
                                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                        ? 0x10U
                                                                        : 
                                                                       ((0x263U 
                                                                         == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                         ? 0xdU
                                                                         : 
                                                                        ((0x363U 
                                                                          == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                          ? 0xfU
                                                                          : 
                                                                         ((0x6fU 
                                                                           == 
                                                                           (0x7fU 
                                                                            & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                                           ? 1U
                                                                           : 
                                                                          ((0x67U 
                                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                            ? 0x11U
                                                                            : (IData)(vlSelf->Top__DOT__core__DOT___GEN_1)))))))))))))))))))))))))));
    vlSelf->Top__DOT__core__DOT___GEN_3 = ((0x123U 
                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                           | ((0x33U 
                                               == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                              | ((0x13U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                 | ((0x8033U 
                                                     == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                    | ((0x3b3U 
                                                        == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                       | ((0x333U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                          | ((0x233U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | ((0x393U 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                                | ((0x313U 
                                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                                   | ((0x213U 
                                                                       == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                                      | ((0xb3U 
                                                                          == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                         | ((0x2b3U 
                                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                            | ((0x82b3U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                               | ((0x93U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                                | ((0x293U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                                | ((0x8293U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                                | ((0x133U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                                | ((0x1b3U 
                                                                                == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                                                | ((0x113U 
                                                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                                                | ((0x193U 
                                                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                                                | (IData)(vlSelf->Top__DOT__core__DOT___GEN_2)))))))))))))))))))));
    if ((0x100073U == vlSelf->Top__DOT___memory_io_imem_inst)) {
        VTop___024unit____Vdpiimwrap_ebreak_TOP____024unit();
        vlSelf->Top__DOT__core__DOT___ebreakModule_exit_ebreak = 1U;
    } else {
        vlSelf->Top__DOT__core__DOT___ebreakModule_exit_ebreak = 0U;
    }
    vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
        = vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory
        [(0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                   >> 0x14U))];
    vlSelf->Top__DOT__core__DOT__csignals_5 = ((0x103U 
                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                ? 1U
                                                : ((IData)(vlSelf->Top__DOT__core__DOT___GEN_3)
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelf->Top__DOT__core__DOT____VdfgTmp_hbc800c22__0) 
                                                    << 1U)));
    vlSelf->Top__DOT__core__DOT__csignals_1 = (((0x103U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                | (IData)(vlSelf->Top__DOT__core__DOT___GEN_3))
                                                ? 0U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                    ? 1U
                                                    : 
                                                   ((0x67U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 0U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                      ? 2U
                                                      : 
                                                     (0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))))));
    vlSelf->Top__DOT__core__DOT__casez_tmp = (((0x103U 
                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                ? 0U
                                                : (
                                                   (0x123U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                    ? 0U
                                                    : 
                                                   ((0x33U 
                                                     == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                     ? 0U
                                                     : 
                                                    ((0x13U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                      ? 0U
                                                      : 
                                                     (((((0x8033U 
                                                          == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                         | (0x3b3U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                        | (0x333U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                       | (0x233U 
                                                          == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                       ? 0U
                                                       : 
                                                      ((((0x393U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                         | (0x313U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                        | (0x213U 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                        ? 0U
                                                        : 
                                                       ((((0xb3U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                          | (0x2b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x82b3U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                         ? 0U
                                                         : 
                                                        ((((0x93U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x293U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x8293U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                          ? 0U
                                                          : 
                                                         (((0x133U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x1b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 0U
                                                           : 
                                                          ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                            ? 0U
                                                            : 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                             ? 0U
                                                             : 
                                                            ((0x6fU 
                                                              == 
                                                              (0x7fU 
                                                               & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                              ? 4U
                                                              : 
                                                             ((0x67U 
                                                               == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                               ? 0U
                                                               : 
                                                              (4U 
                                                               & (1U 
                                                                  | ((IData)(vlSelf->Top__DOT__core__DOT___GEN_1) 
                                                                     << 2U))))))))))))))))
                                               ? ((
                                                   (0x103U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                    ? 2U
                                                    : 
                                                   ((0x123U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 2U
                                                     : 
                                                    ((0x33U 
                                                      == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                      ? 0U
                                                      : 
                                                     ((0x13U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                       ? 2U
                                                       : 
                                                      (((((0x8033U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                          | (0x3b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x333U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                        | (0x233U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                        ? 0U
                                                        : 
                                                       ((((0x393U 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                          | (0x313U 
                                                             == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                         | (0x213U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                         ? 2U
                                                         : 
                                                        ((((0xb3U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x2b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x82b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                          ? 0U
                                                          : 
                                                         ((((0x93U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                           | (0x8293U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 2U
                                                           : 
                                                          (((0x133U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x1b3U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                            ? 0U
                                                            : 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                             ? 2U
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                              ? 0U
                                                              : 
                                                             ((0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                               ? 0U
                                                               : 
                                                              ((0x67U 
                                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                ? 2U
                                                                : 
                                                               (2U 
                                                                & 1U))))))))))))))
                                                   ? 0U
                                                   : 
                                                  (((0x103U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 0U
                                                     : 
                                                    ((0x123U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                      ? 1U
                                                      : 
                                                     ((0x33U 
                                                       == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                       ? 1U
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                        ? 0U
                                                        : 
                                                       (((((0x8033U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x3b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x333U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x233U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                         ? 1U
                                                         : 
                                                        ((((0x393U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                           | (0x313U 
                                                              == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                          | (0x213U 
                                                             == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                          ? 0U
                                                          : 
                                                         ((((0xb3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x2b3U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                           | (0x82b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 1U
                                                           : 
                                                          ((((0x93U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x293U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                            | (0x8293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                            ? 0U
                                                            : 
                                                           (((0x133U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x1b3U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                             ? 1U
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                              ? 0U
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                               ? 1U
                                                               : 
                                                              ((0x6fU 
                                                                == 
                                                                (0x7fU 
                                                                 & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                                ? 0U
                                                                : 
                                                               ((0x67U 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                 ? 0U
                                                                 : 1U)))))))))))))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelf->Top__DOT___memory_io_imem_inst)
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->Top__DOT___memory_io_imem_inst 
                                                                 >> 0x1fU))) 
                                                     << 0x14U) 
                                                    | ((0xff000U 
                                                        & vlSelf->Top__DOT___memory_io_imem_inst) 
                                                       | ((0x800U 
                                                           & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                                >> 0x14U)))))))
                                               : ((
                                                   (0x103U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                    ? 2U
                                                    : 
                                                   ((0x123U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 2U
                                                     : 
                                                    ((0x33U 
                                                      == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                      ? 0U
                                                      : 
                                                     ((0x13U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                       ? 2U
                                                       : 
                                                      (((((0x8033U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                          | (0x3b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x333U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                        | (0x233U 
                                                           == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                        ? 0U
                                                        : 
                                                       ((((0x393U 
                                                           == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                          | (0x313U 
                                                             == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                         | (0x213U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                         ? 2U
                                                         : 
                                                        ((((0xb3U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x2b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x82b3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                          ? 0U
                                                          : 
                                                         ((((0x93U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                           | (0x8293U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 2U
                                                           : 
                                                          (((0x133U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x1b3U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                            ? 0U
                                                            : 
                                                           ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                             ? 2U
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                              ? 0U
                                                              : 
                                                             ((0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                               ? 0U
                                                               : 
                                                              ((0x67U 
                                                                == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                ? 2U
                                                                : 
                                                               (2U 
                                                                & 1U))))))))))))))
                                                   ? 
                                                  (((0x103U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 0U
                                                     : 
                                                    ((0x123U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                      ? 1U
                                                      : 
                                                     ((0x33U 
                                                       == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                       ? 1U
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                        ? 0U
                                                        : 
                                                       (((((0x8033U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x3b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x333U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x233U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                         ? 1U
                                                         : 
                                                        ((((0x393U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                           | (0x313U 
                                                              == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                          | (0x213U 
                                                             == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                          ? 0U
                                                          : 
                                                         ((((0xb3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x2b3U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                           | (0x82b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 1U
                                                           : 
                                                          ((((0x93U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x293U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                            | (0x8293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                            ? 0U
                                                            : 
                                                           (((0x133U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x1b3U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                             ? 1U
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                              ? 0U
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                               ? 1U
                                                               : 
                                                              ((0x6fU 
                                                                == 
                                                                (0x7fU 
                                                                 & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                                ? 0U
                                                                : 
                                                               ((0x67U 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                 ? 0U
                                                                 : 1U)))))))))))))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->Top__DOT___memory_io_imem_inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                             >> 7U))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->Top__DOT___memory_io_imem_inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelf->Top__DOT___memory_io_imem_inst 
                                                       >> 0x14U)))
                                                   : 
                                                  (((0x103U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                     ? 0U
                                                     : 
                                                    ((0x123U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                      ? 1U
                                                      : 
                                                     ((0x33U 
                                                       == vlSelf->Top__DOT__core__DOT___GEN_0)
                                                       ? 1U
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                        ? 0U
                                                        : 
                                                       (((((0x8033U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                           | (0x3b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                          | (0x333U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                         | (0x233U 
                                                            == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                         ? 1U
                                                         : 
                                                        ((((0x393U 
                                                            == (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                                           | (0x313U 
                                                              == (IData)(vlSelf->Top__DOT__core__DOT___GEN))) 
                                                          | (0x213U 
                                                             == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))
                                                          ? 0U
                                                          : 
                                                         ((((0xb3U 
                                                             == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                            | (0x2b3U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                           | (0x82b3U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                           ? 1U
                                                           : 
                                                          ((((0x93U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x293U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0)) 
                                                            | (0x8293U 
                                                               == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                            ? 0U
                                                            : 
                                                           (((0x133U 
                                                              == vlSelf->Top__DOT__core__DOT___GEN_0) 
                                                             | (0x1b3U 
                                                                == vlSelf->Top__DOT__core__DOT___GEN_0))
                                                             ? 1U
                                                             : 
                                                            ((IData)(vlSelf->Top__DOT__core__DOT___GEN_4)
                                                              ? 0U
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                               ? 1U
                                                               : 
                                                              ((0x6fU 
                                                                == 
                                                                (0x7fU 
                                                                 & (IData)(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data)))
                                                                ? 0U
                                                                : 
                                                               ((0x67U 
                                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                                 ? 0U
                                                                 : 1U)))))))))))))
                                                    ? 
                                                   ((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                         >> 0x14U)))
                                                     ? vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data
                                                     : 0U)
                                                    : 0U)));
    vlSelf->Top__DOT__core__DOT__op1_data = ((0U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_1))
                                              ? ((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                                      >> 0xfU)))
                                                  ? 
                                                 vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory
                                                 [(0x1fU 
                                                   & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                                      >> 0xfU))]
                                                  : 0U)
                                              : ((1U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__csignals_1))
                                                  ? vlSelf->Top__DOT__core__DOT__pc_reg
                                                  : 0U));
    vlSelf->Top__DOT__core__DOT___br_flg_T_13 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                 < vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_31 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                  + vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_4 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                 - vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_7 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                 & vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_9 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                 | vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_11 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                  ^ vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT__core__DOT___alu_out_T_18 = (vlSelf->Top__DOT__core__DOT__op1_data 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSelf->Top__DOT__core__DOT__casez_tmp));
    vlSelf->Top__DOT__core__DOT___alu_out_T_22 = VL_SHIFTRS_III(32,32,5, vlSelf->Top__DOT__core__DOT__op1_data, 
                                                                (0x1fU 
                                                                 & vlSelf->Top__DOT__core__DOT__casez_tmp));
    vlSelf->Top__DOT__core__DOT___GEN_7 = VL_LTS_III(32, vlSelf->Top__DOT__core__DOT__op1_data, vlSelf->Top__DOT__core__DOT__casez_tmp);
    vlSelf->Top__DOT___core_io_dmem_addr = ((1U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                             ? vlSelf->Top__DOT__core__DOT___alu_out_T_31
                                             : ((2U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                 ? vlSelf->Top__DOT__core__DOT___alu_out_T_4
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                  ? vlSelf->Top__DOT__core__DOT___alu_out_T_7
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                   ? vlSelf->Top__DOT__core__DOT___alu_out_T_9
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                    ? vlSelf->Top__DOT__core__DOT___alu_out_T_11
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                     ? 
                                                    (vlSelf->Top__DOT__core__DOT__op1_data 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelf->Top__DOT__core__DOT__casez_tmp))
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                      ? vlSelf->Top__DOT__core__DOT___alu_out_T_18
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                       ? vlSelf->Top__DOT__core__DOT___alu_out_T_22
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                        ? vlSelf->Top__DOT__core__DOT___GEN_7
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                         ? (IData)(vlSelf->Top__DOT__core__DOT___br_flg_T_13)
                                                         : 
                                                        ((0x11U 
                                                          == (IData)(vlSelf->Top__DOT__core__DOT__csignals_0))
                                                          ? 
                                                         (0xfffffffeU 
                                                          & vlSelf->Top__DOT__core__DOT___alu_out_T_31)
                                                          : 0U)))))))))));
}
