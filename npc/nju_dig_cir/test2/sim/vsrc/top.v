module top(x,en,y);
  input  [1:0] x;
  input  en;
  output reg [3:0]y;

  decode24 de1(
    .x(x),
    .en(en),
    .y(y)
  );


endmodule
