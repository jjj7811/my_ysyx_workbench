// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


VL_ATTR_COLD void VTop___024root__trace_init_sub__TOP__0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+75,"reset", false,-1);
    tracep->declBit(c+76,"io_exit", false,-1);
    tracep->declBit(c+77,"io_coreRun", false,-1);
    tracep->pushNamePrefix("Top ");
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+75,"reset", false,-1);
    tracep->declBit(c+76,"io_exit", false,-1);
    tracep->declBit(c+77,"io_coreRun", false,-1);
    tracep->pushNamePrefix("core ");
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBit(c+78,"reset", false,-1);
    tracep->declBus(c+1,"io_imem_addr", false,-1, 31,0);
    tracep->declBus(c+2,"io_imem_inst", false,-1, 31,0);
    tracep->declBus(c+3,"io_dmem_addr", false,-1, 31,0);
    tracep->declBus(c+4,"io_dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+5,"io_dmem_wen", false,-1, 1,0);
    tracep->declBus(c+6,"io_dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+76,"io_exit", false,-1);
    tracep->declBus(c+1,"pc_reg", false,-1, 31,0);
    tracep->declBus(c+6,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+7,"csignals_0", false,-1, 4,0);
    tracep->declBus(c+8,"csignals_1", false,-1, 1,0);
    tracep->declBus(c+9,"csignals_5", false,-1, 1,0);
    tracep->declBus(c+10,"op1_data", false,-1, 31,0);
    tracep->declBus(c+11,"casez_tmp", false,-1, 31,0);
    tracep->declBus(c+3,"alu_out", false,-1, 31,0);
    tracep->declBit(c+12,"exitEbreakReg", false,-1);
    tracep->pushNamePrefix("ebreakModule ");
    tracep->declBus(c+2,"inst_i", false,-1, 31,0);
    tracep->declBit(c+13,"exit_ebreak", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile_ext ");
    tracep->declBus(c+14,"R0_addr", false,-1, 4,0);
    tracep->declBit(c+79,"R0_en", false,-1);
    tracep->declBit(c+74,"R0_clk", false,-1);
    tracep->declBus(c+15,"R0_data", false,-1, 31,0);
    tracep->declBus(c+16,"R1_addr", false,-1, 4,0);
    tracep->declBit(c+79,"R1_en", false,-1);
    tracep->declBit(c+74,"R1_clk", false,-1);
    tracep->declBus(c+17,"R1_data", false,-1, 31,0);
    tracep->declBus(c+18,"W0_addr", false,-1, 4,0);
    tracep->declBit(c+19,"W0_en", false,-1);
    tracep->declBit(c+74,"W0_clk", false,-1);
    tracep->declBus(c+20,"W0_data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+21+i*1,"Memory", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("memory ");
    tracep->declBit(c+74,"clock", false,-1);
    tracep->declBus(c+1,"io_imem_addr", false,-1, 31,0);
    tracep->declBus(c+2,"io_imem_inst", false,-1, 31,0);
    tracep->declBus(c+3,"io_dmem_addr", false,-1, 31,0);
    tracep->declBus(c+4,"io_dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+5,"io_dmem_wen", false,-1, 1,0);
    tracep->declBus(c+6,"io_dmem_wdata", false,-1, 31,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+53,"R0_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R0_en", false,-1);
    tracep->declBit(c+74,"R0_clk", false,-1);
    tracep->declBus(c+54,"R0_data", false,-1, 7,0);
    tracep->declBus(c+55,"R1_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R1_en", false,-1);
    tracep->declBit(c+74,"R1_clk", false,-1);
    tracep->declBus(c+56,"R1_data", false,-1, 7,0);
    tracep->declBus(c+57,"R2_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R2_en", false,-1);
    tracep->declBit(c+74,"R2_clk", false,-1);
    tracep->declBus(c+58,"R2_data", false,-1, 7,0);
    tracep->declBus(c+59,"R3_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R3_en", false,-1);
    tracep->declBit(c+74,"R3_clk", false,-1);
    tracep->declBus(c+60,"R3_data", false,-1, 7,0);
    tracep->declBus(c+61,"R4_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R4_en", false,-1);
    tracep->declBit(c+74,"R4_clk", false,-1);
    tracep->declBus(c+62,"R4_data", false,-1, 7,0);
    tracep->declBus(c+63,"R5_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R5_en", false,-1);
    tracep->declBit(c+74,"R5_clk", false,-1);
    tracep->declBus(c+64,"R5_data", false,-1, 7,0);
    tracep->declBus(c+65,"R6_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R6_en", false,-1);
    tracep->declBit(c+74,"R6_clk", false,-1);
    tracep->declBus(c+66,"R6_data", false,-1, 7,0);
    tracep->declBus(c+67,"R7_addr", false,-1, 13,0);
    tracep->declBit(c+79,"R7_en", false,-1);
    tracep->declBit(c+74,"R7_clk", false,-1);
    tracep->declBus(c+68,"R7_data", false,-1, 7,0);
    tracep->declBus(c+67,"W0_addr", false,-1, 13,0);
    tracep->declBit(c+69,"W0_en", false,-1);
    tracep->declBit(c+74,"W0_clk", false,-1);
    tracep->declBus(c+70,"W0_data", false,-1, 7,0);
    tracep->declBus(c+65,"W1_addr", false,-1, 13,0);
    tracep->declBit(c+69,"W1_en", false,-1);
    tracep->declBit(c+74,"W1_clk", false,-1);
    tracep->declBus(c+71,"W1_data", false,-1, 7,0);
    tracep->declBus(c+63,"W2_addr", false,-1, 13,0);
    tracep->declBit(c+69,"W2_en", false,-1);
    tracep->declBit(c+74,"W2_clk", false,-1);
    tracep->declBus(c+72,"W2_data", false,-1, 7,0);
    tracep->declBus(c+61,"W3_addr", false,-1, 13,0);
    tracep->declBit(c+69,"W3_en", false,-1);
    tracep->declBit(c+74,"W3_clk", false,-1);
    tracep->declBus(c+73,"W3_data", false,-1, 7,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VTop___024root__trace_init_top(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_top\n"); );
    // Body
    VTop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTop___024root__trace_register(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->Top__DOT__core__DOT__pc_reg),32);
    bufp->fullIData(oldp+2,(vlSelf->Top__DOT___memory_io_imem_inst),32);
    bufp->fullIData(oldp+3,(vlSelf->Top__DOT___core_io_dmem_addr),32);
    bufp->fullIData(oldp+4,(((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                              [(0x3fffU & ((IData)(3U) 
                                           + vlSelf->Top__DOT___core_io_dmem_addr))] 
                              << 0x18U) | ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                            [(0x3fffU 
                                              & ((IData)(2U) 
                                                 + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                            << 0x10U) 
                                           | ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                               [(0x3fffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->Top__DOT___core_io_dmem_addr))] 
                                               << 8U) 
                                              | vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                                              [(0x3fffU 
                                                & vlSelf->Top__DOT___core_io_dmem_addr)])))),32);
    bufp->fullCData(oldp+5,(((0x103U != (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                             & (0x123U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))),2);
    bufp->fullIData(oldp+6,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                              >> 0x14U)))
                              ? vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data
                              : 0U)),32);
    bufp->fullCData(oldp+7,(vlSelf->Top__DOT__core__DOT__csignals_0),5);
    bufp->fullCData(oldp+8,(vlSelf->Top__DOT__core__DOT__csignals_1),2);
    bufp->fullCData(oldp+9,(vlSelf->Top__DOT__core__DOT__csignals_5),2);
    bufp->fullIData(oldp+10,(vlSelf->Top__DOT__core__DOT__op1_data),32);
    bufp->fullIData(oldp+11,(vlSelf->Top__DOT__core__DOT__casez_tmp),32);
    bufp->fullBit(oldp+12,(vlSelf->Top__DOT__core__DOT__exitEbreakReg));
    bufp->fullBit(oldp+13,(vlSelf->Top__DOT__core__DOT___ebreakModule_exit_ebreak));
    bufp->fullCData(oldp+14,((0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                       >> 0x14U))),5);
    bufp->fullIData(oldp+15,(vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data),32);
    bufp->fullCData(oldp+16,((0x1fU & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                       >> 0xfU))),5);
    bufp->fullIData(oldp+17,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory
                             [(0x1fU & (vlSelf->__VdfgTmp_hf51a5acc__0 
                                        >> 0xfU))]),32);
    bufp->fullCData(oldp+18,((0x1fU & ((IData)(vlSelf->__VdfgTmp_h0d09a3a3__0) 
                                       >> 7U))),5);
    bufp->fullBit(oldp+19,(((1U == ((0x103U == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                     ? 1U : ((0x123U 
                                              == (IData)(vlSelf->Top__DOT__core__DOT___GEN))
                                              ? 0U : 
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
                                               : ((IData)(vlSelf->Top__DOT__core__DOT___GEN_2)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlSelf->Top__DOT__core__DOT____VdfgTmp_hbc800c22__0) 
                                                   | (IData)(vlSelf->Top__DOT__core__DOT___GEN_1))))))) 
                            & (0U != (0x1fU & ((IData)(vlSelf->__VdfgTmp_h0d09a3a3__0) 
                                               >> 7U))))));
    bufp->fullIData(oldp+20,(((1U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_5))
                               ? ((vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
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
                                                   [
                                                   (0x3fffU 
                                                    & vlSelf->Top__DOT___core_io_dmem_addr)])))
                               : ((2U == (IData)(vlSelf->Top__DOT__core__DOT__csignals_5))
                                   ? ((IData)(4U) + vlSelf->Top__DOT__core__DOT__pc_reg)
                                   : vlSelf->Top__DOT___core_io_dmem_addr))),32);
    bufp->fullIData(oldp+21,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[0]),32);
    bufp->fullIData(oldp+22,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[1]),32);
    bufp->fullIData(oldp+23,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[2]),32);
    bufp->fullIData(oldp+24,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[3]),32);
    bufp->fullIData(oldp+25,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[4]),32);
    bufp->fullIData(oldp+26,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[5]),32);
    bufp->fullIData(oldp+27,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[6]),32);
    bufp->fullIData(oldp+28,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[7]),32);
    bufp->fullIData(oldp+29,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[8]),32);
    bufp->fullIData(oldp+30,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[9]),32);
    bufp->fullIData(oldp+31,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[10]),32);
    bufp->fullIData(oldp+32,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[11]),32);
    bufp->fullIData(oldp+33,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[12]),32);
    bufp->fullIData(oldp+34,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[13]),32);
    bufp->fullIData(oldp+35,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[14]),32);
    bufp->fullIData(oldp+36,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[15]),32);
    bufp->fullIData(oldp+37,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[16]),32);
    bufp->fullIData(oldp+38,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[17]),32);
    bufp->fullIData(oldp+39,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[18]),32);
    bufp->fullIData(oldp+40,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[19]),32);
    bufp->fullIData(oldp+41,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[20]),32);
    bufp->fullIData(oldp+42,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[21]),32);
    bufp->fullIData(oldp+43,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[22]),32);
    bufp->fullIData(oldp+44,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[23]),32);
    bufp->fullIData(oldp+45,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[24]),32);
    bufp->fullIData(oldp+46,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[25]),32);
    bufp->fullIData(oldp+47,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[26]),32);
    bufp->fullIData(oldp+48,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[27]),32);
    bufp->fullIData(oldp+49,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[28]),32);
    bufp->fullIData(oldp+50,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[29]),32);
    bufp->fullIData(oldp+51,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[30]),32);
    bufp->fullIData(oldp+52,(vlSelf->Top__DOT__core__DOT__regfile_ext__DOT__Memory[31]),32);
    bufp->fullSData(oldp+53,((0x3fffU & vlSelf->Top__DOT__core__DOT__pc_reg)),14);
    bufp->fullCData(oldp+54,(vlSelf->Top__DOT__memory__DOT___mem_ext_R0_data),8);
    bufp->fullSData(oldp+55,((0x3fffU & ((IData)(1U) 
                                         + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
    bufp->fullCData(oldp+56,(vlSelf->Top__DOT__memory__DOT___mem_ext_R1_data),8);
    bufp->fullSData(oldp+57,((0x3fffU & ((IData)(2U) 
                                         + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
    bufp->fullCData(oldp+58,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                             [(0x3fffU & ((IData)(2U) 
                                          + vlSelf->Top__DOT__core__DOT__pc_reg))]),8);
    bufp->fullSData(oldp+59,((0x3fffU & ((IData)(3U) 
                                         + vlSelf->Top__DOT__core__DOT__pc_reg))),14);
    bufp->fullCData(oldp+60,(vlSelf->Top__DOT__memory__DOT___mem_ext_R3_data),8);
    bufp->fullSData(oldp+61,((0x3fffU & vlSelf->Top__DOT___core_io_dmem_addr)),14);
    bufp->fullCData(oldp+62,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                             [(0x3fffU & vlSelf->Top__DOT___core_io_dmem_addr)]),8);
    bufp->fullSData(oldp+63,((0x3fffU & ((IData)(1U) 
                                         + vlSelf->Top__DOT___core_io_dmem_addr))),14);
    bufp->fullCData(oldp+64,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                             [(0x3fffU & ((IData)(1U) 
                                          + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
    bufp->fullSData(oldp+65,((0x3fffU & ((IData)(2U) 
                                         + vlSelf->Top__DOT___core_io_dmem_addr))),14);
    bufp->fullCData(oldp+66,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                             [(0x3fffU & ((IData)(2U) 
                                          + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
    bufp->fullSData(oldp+67,((0x3fffU & ((IData)(3U) 
                                         + vlSelf->Top__DOT___core_io_dmem_addr))),14);
    bufp->fullCData(oldp+68,(vlSelf->Top__DOT__memory__DOT__mem_ext__DOT__Memory
                             [(0x3fffU & ((IData)(3U) 
                                          + vlSelf->Top__DOT___core_io_dmem_addr))]),8);
    bufp->fullBit(oldp+69,(((0x103U != (IData)(vlSelf->Top__DOT__core__DOT___GEN)) 
                            & (0x123U == (IData)(vlSelf->Top__DOT__core__DOT___GEN)))));
    bufp->fullCData(oldp+70,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                               >> 0x14U)))
                               ? (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                  >> 0x18U) : 0U)),8);
    bufp->fullCData(oldp+71,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                               >> 0x14U)))
                               ? (0xffU & (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                           >> 0x10U))
                               : 0U)),8);
    bufp->fullCData(oldp+72,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                               >> 0x14U)))
                               ? (0xffU & (vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data 
                                           >> 8U)) : 0U)),8);
    bufp->fullCData(oldp+73,(((0U != (0x1fU & (vlSelf->Top__DOT___memory_io_imem_inst 
                                               >> 0x14U)))
                               ? (0xffU & vlSelf->Top__DOT__core__DOT___regfile_ext_R0_data)
                               : 0U)),8);
    bufp->fullBit(oldp+74,(vlSelf->clock));
    bufp->fullBit(oldp+75,(vlSelf->reset));
    bufp->fullBit(oldp+76,(vlSelf->io_exit));
    bufp->fullBit(oldp+77,(vlSelf->io_coreRun));
    bufp->fullBit(oldp+78,((1U & (~ (IData)(vlSelf->io_coreRun)))));
    bufp->fullBit(oldp+79,(1U));
}
