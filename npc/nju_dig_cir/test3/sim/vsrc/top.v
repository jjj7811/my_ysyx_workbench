module top(
   input                A   ,
   input                B   ,
   input                Ci  , 

   output	wire        S   ,
   output   wire        Co   
);

wire S0;
wire C0,C1;

add_half adder1(
    .A(A),
    .B(B),
    .S(S0),
    .C(C0)
);


add_half adder2(
    .A(S0),
    .B(Ci),
    .S(S),
    .C(C1)
);

assign Co=C1 | C0;

endmodule
