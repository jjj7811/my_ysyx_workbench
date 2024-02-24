module ALU (
    input      [2:0] op,
    input      [3:0] a,
    input      [3:0] b,
    input            clk,
    output reg [3:0] result,
    output           out
);

  reg [3:0] a_reg;
  reg [3:0] b_reg;

  assign a_reg = a;
  assign b_reg = b;

  always @(posedge clk) begin
    case (op)
      3'b000: begin
        //这样写能够取出溢出的那一位，用以判断是否溢出，如果需要，可以输出
        {out, result} = a_reg + b_reg;
      end
      3'b001: begin
        b_reg = ~b_reg + 1;
        {out, result} = a_reg + b_reg;
      end
      3'b010: begin
        result = ~a_reg;
      end
      3'b011: begin
        result = a_reg & b_reg;
      end
      3'b100: begin
        result = a_reg | b_reg;
      end
      3'b101: begin
        result = a_reg ^ b_reg;
      end
      3'b110: begin
        if (a_reg[3] == b_reg[3]) begin  //判断符号位是否相等
          if (a_reg < b_reg) result = 1;  //符号位相等直接比大小
          else result = 0;
        end else begin  //符号位不相等直接比符号位
          if ((a_reg[3] == 0) && (b_reg[3] == 1)) result = 0;
          if ((a_reg[3] == 1) && (b_reg[3] == 0)) result = 1;
        end
      end
      3'b111: begin
        if (a_reg == b_reg) result = 1;
        else result = 0;
      end
    endcase
  end


endmodule
