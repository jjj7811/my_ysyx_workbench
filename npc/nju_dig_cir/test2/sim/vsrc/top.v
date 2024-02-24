module top(x,en,y,z);
  input  [2:0] x;
  input  en;
  output reg [7:0]y;
  output reg [2:0]z;

  decode24 de1(
    .x(x),
    .en(en),
    .y(y)
  );

  encode42 en1(
    y,
    en,
    z
  );



endmodule
