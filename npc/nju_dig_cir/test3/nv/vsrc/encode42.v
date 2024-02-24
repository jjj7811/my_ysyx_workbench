module encode42(x,en,y);
  input  [7:0] x;
  input  en;
  output reg [2:0]y;

  always @(x or en) begin
    if (en) begin
      case (x)
        8'b00000001 : y =3'd0;
        8'b00000010 : y =3'd1;
        8'b00000100 : y =3'd2;
        8'b00001000 : y =3'd3;
        8'b00010000 : y =3'd4;
        8'b00100000 : y =3'd5;
        8'b01000000 : y =3'd6;
        8'b10000000 : y =3'd7;
        default: y = 3'd0;
      endcase
    end
    else  y = 3'b000;
  end
endmodule
