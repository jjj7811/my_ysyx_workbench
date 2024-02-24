module add_half(
   input                A   ,
   input                B   ,
 
   output	wire        S   ,
   output   wire        C   
);

assign S = A ^ B;
assign C = A & B;
endmodule

/***************************************************************/
