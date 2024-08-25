// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->Top__DOT__core__DOT__pc_reg),32);
        bufp->chgIData(oldp+1,(vlSelf->Top__DOT___memory_io_imem_inst),32);
        bufp->chgIData(oldp+2,(vlSelf->Top__DOT___core_io_dmem_addr),32);
        bufp->chgIData(oldp+3,(((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                 [(0x3fffU & ((IData)(3U) 
                                              + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                 << 0x18U) | ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                               [(0x3fffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                               << 0x10U) 
                                              | ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                                  [
                                                  (0x3fffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                                  << 8U) 
                                                 | vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                                 [(0x3fffU 
                                                   & vlSelf->Top__DOT___core_io_dmem_addr)])))),32);
        bufp->chgCData(oldp+4,(((0x103U != (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                                & (0x123U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))),2);
        bufp->chgIData(oldp+5,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                 >> 0x14U)))
                                 ? vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data
                                 : 0U)),32);
        bufp->chgCData(oldp+6,(vlSelf->Top__DOT__core__DOT__csignals_0),5);
        bufp->chgCData(oldp+7,(vlSelf->Top__DOT__core__DOT__csignals_1),2);
        bufp->chgCData(oldp+8,(vlSelf->Top__DOT__core__DOT__csignals_5),2);
        bufp->chgIData(oldp+9,(vlSelf->Top__DOT__core__DOT__op1_data),32);
        bufp->chgIData(oldp+10,(vlSelf->Top__DOT__core__DOT__casez_tmp),32);
        bufp->chgBit(oldp+11,(vlSelf->Top__DOT__core__DOT__exitEbreakReg));
        bufp->chgBit(oldp+12,(vlSelf->Top__DOT__core__DOT___ebreakModule_exit_ebreak));
        bufp->chgCData(oldp+13,((0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+14,(vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data),32);
        bufp->chgCData(oldp+15,((0x1fU & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                          >> 0xfU))),5);
        bufp->chgIData(oldp+16,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory
                                [(0x1fU & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                           >> 0xfU))]),32);
        bufp->chgCData(oldp+17,((0x1fU & ((IData)(vlSelf->__VdfgTmp_h0d09a3a3__0) 
                                          >> 7U))),5);
        bufp->chgBit(oldp+18,(((1U == ((0x103U == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                        ? 1U : ((0x123U 
                                                 == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                                 ? 0U
                                                 : 
                                                (((0x33U 
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
                                                                                | (IData)(vlSelf->Top__DOT__core__DOT___GEN_4))))))))))))))))))
                                                  ? 1U
                                                  : 
                                                 ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT____VdfgTmp_hbc800c22__0) 
                                                   | (IData)(vlSelf->Top__DOT__core__DOT___GEN_1))))))) 
                               & (0U != (0x1fU & ((IData)(vlSelf->__VdfgTmp_h0d09a3a3__0) 
                                                  >> 7U))))));
        bufp->chgIData(oldp+19,(((1U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_5))
                                  ? ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                      [(0x3fffU & ((IData)(3U) 
                                                   + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                      << 0x18U) | (
                                                   (vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                                    [
                                                    (0x3fffU 
                                                     & ((IData)(2U) 
                                                        + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                                    << 0x10U) 
                                                   | ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                                       [
                                                       (0x3fffU 
                                                        & ((IData)(1U) 
                                                           + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                                       << 8U) 
                                                      | vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                                      [
                                                      (0x3fffU 
                                                       & vlSelf->Top__DOT___core_io_dmem_addr)])))
                                  : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_5))
                                      ? ((IData)(4U) 
                                         + vlSelf->Top__DOT__core__DOT__pc_reg)
                                      : vlSelf->Top__DOT___core_io_dmem_addr))),32);
        bufp->chgIData(oldp+20,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[0]),32);
        bufp->chgIData(oldp+21,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[1]),32);
        bufp->chgIData(oldp+22,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[2]),32);
        bufp->chgIData(oldp+23,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[3]),32);
        bufp->chgIData(oldp+24,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[4]),32);
        bufp->chgIData(oldp+25,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[5]),32);
        bufp->chgIData(oldp+26,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[6]),32);
        bufp->chgIData(oldp+27,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[7]),32);
        bufp->chgIData(oldp+28,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[8]),32);
        bufp->chgIData(oldp+29,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[9]),32);
        bufp->chgIData(oldp+30,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[10]),32);
        bufp->chgIData(oldp+31,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[11]),32);
        bufp->chgIData(oldp+32,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[12]),32);
        bufp->chgIData(oldp+33,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[13]),32);
        bufp->chgIData(oldp+34,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[14]),32);
        bufp->chgIData(oldp+35,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[15]),32);
        bufp->chgIData(oldp+36,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[16]),32);
        bufp->chgIData(oldp+37,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[17]),32);
        bufp->chgIData(oldp+38,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[18]),32);
        bufp->chgIData(oldp+39,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[19]),32);
        bufp->chgIData(oldp+40,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[20]),32);
        bufp->chgIData(oldp+41,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[21]),32);
        bufp->chgIData(oldp+42,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[22]),32);
        bufp->chgIData(oldp+43,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[23]),32);
        bufp->chgIData(oldp+44,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[24]),32);
        bufp->chgIData(oldp+45,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[25]),32);
        bufp->chgIData(oldp+46,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[26]),32);
        bufp->chgIData(oldp+47,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[27]),32);
        bufp->chgIData(oldp+48,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[28]),32);
        bufp->chgIData(oldp+49,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[29]),32);
        bufp->chgIData(oldp+50,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[30]),32);
        bufp->chgIData(oldp+51,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[31]),32);
        bufp->chgSData(oldp+52,((0x3fffU & vlSelf->Top__DOT__core__DOT__pc_reg)),14);
        bufp->chgCData(oldp+53,(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data),8);
        bufp->chgSData(oldp+54,((0x3fffU & ((IData)(1U) 
                                            + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
        bufp->chgCData(oldp+55,(vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data),8);
        bufp->chgSData(oldp+56,((0x3fffU & ((IData)(2U) 
                                            + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
        bufp->chgCData(oldp+57,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                [(0x3fffU & ((IData)(2U) 
                                             + vlSelf->Top__DOT__core__DOT__pc_reg))]),8);
        bufp->chgSData(oldp+58,((0x3fffU & ((IData)(3U) 
                                            + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
        bufp->chgCData(oldp+59,(vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data),8);
        bufp->chgSData(oldp+60,((0x3fffU & vlSelf->Top__DOT___core_io_dmem_addr)),14);
        bufp->chgCData(oldp+61,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                [(0x3fffU & vlSelf->Top__DOT___core_io_dmem_addr)]),8);
        bufp->chgSData(oldp+62,((0x3fffU & ((IData)(1U) 
                                            + vlSelf->Top__DOT___core_io_dmem_addr))),14);
        bufp->chgCData(oldp+63,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                [(0x3fffU & ((IData)(1U) 
                                             + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
        bufp->chgSData(oldp+64,((0x3fffU & ((IData)(2U) 
                                            + vlSelf->Top__DOT___core_io_dmem_addr))),14);
        bufp->chgCData(oldp+65,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                [(0x3fffU & ((IData)(2U) 
                                             + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
        bufp->chgSData(oldp+66,((0x3fffU & ((IData)(3U) 
                                            + vlSelf->Top__DOT___core_io_dmem_addr))),14);
        bufp->chgCData(oldp+67,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                [(0x3fffU & ((IData)(3U) 
                                             + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
        bufp->chgBit(oldp+68,(((0x103U != (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                               & (0x123U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))));
        bufp->chgCData(oldp+69,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                  >> 0x14U)))
                                  ? (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                     >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+70,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                  >> 0x14U)))
                                  ? (0xffU & (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                              >> 0x10U))
                                  : 0U)),8);
        bufp->chgCData(oldp+71,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                  >> 0x14U)))
                                  ? (0xffU & (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                              >> 8U))
                                  : 0U)),8);
        bufp->chgCData(oldp+72,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                                  >> 0x14U)))
                                  ? (0xffU & vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data)
                                  : 0U)),8);
    }
    bufp->chgBit(oldp+73,(vlSelf->clock));
    bufp->chgBit(oldp+74,(vlSelf->reset));
    bufp->chgBit(oldp+75,(vlSelf->io_exit));
    bufp->chgBit(oldp+76,(vlSelf->io_coreRun));
    bufp->chgBit(oldp+77,((1U & (~ (IData)(vlSelf->io_coreRun)))));
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
