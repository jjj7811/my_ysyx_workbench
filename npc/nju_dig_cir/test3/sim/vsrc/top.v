module top (
    input [3:0] A,
    input [3:0] B,
    input       Ci,

    output wire [3:0] S,
    output wire       Cos
);

  wire [3:0] C;

  add_full u1 (
      .A (A[0]),
      .B (B[0]),
      .Ci(Ci),

      .S (S[0]),
      .Co(C[0])
  );
  add_full u2 (
      .A (A[1]),
      .B (B[1]),
      .Ci(C[0]),

      .S (S[1]),
      .Co(C[1])
  );
  add_full u3 (
      .A (A[2]),
      .B (B[2]),
      .Ci(C[1]),

      .S (S[2]),
      .Co(C[2])
  );
  add_full u4 (
      .A (A[3]),
      .B (B[3]),
      .Ci(C[2]),

      .S (S[3]),
      .Co(C[3])
  );
  assign Co = C[3];


endmodule
