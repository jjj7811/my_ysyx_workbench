module decode24(x,en,y);
  input  [2:0] x;
  input  en;
  output reg [7:0]y;

  always @(x or en)
    if (en)
    begin
      case (x)
            3'd0 : y = 8'b00000001;
            3'd1 : y = 8'b00000010;
            3'd2 : y = 8'b00000100;
            3'd3 : y = 8'b00001000;
            3'd4 : y = 8'b00010000;
            3'd5 : y = 8'b00100000;
            3'd6 : y = 8'b01000000;
            3'd7 : y = 8'b10000000;
      endcase
    end
    else  y = 8'b00000000;

endmodule
