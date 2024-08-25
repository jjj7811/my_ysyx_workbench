package lw

import chisel3._
import chisel3.util._
import chisel3.util.HasBlackBoxInline
import chisel3.util.HasBlackBoxResource
import chisel3.util.HasBlackBoxPath


class EBREAK extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val inst_i = Input(UInt(32.W))
    val exit_ebreak = Output(Bool())
  })
  addPath("/home/hehe/ysyx-workbench/npc/src/main/resources/ebreak.sv")
  
  // 直接插入 Verilog 代码
//   setInline("Top.sv",
//     """ 
//         import "DPI-C" function void ebreak();
//         module EBREAK(
//             input wire [31:0] inst_i
//         );
//         // Verilog 中的 ebreak 函数代码
//         // 这里直接插入 ebreak 函数的 Verilog 代码
//         // 注意确保插入的代码格式正确
//         // 如有必要，你可能需要将其放在 `begin` 和 `end` 块中
//         // 以及添加适当的端口声明
//         // 比如：
//         always @(*) begin
//             if(inst_i == 32'b0000_0000_0001_0000_0000_0000_0111_0011) begin
//                 // ;
//                 ebreak();       
//             end
//        end
//      endmodule""")
}

