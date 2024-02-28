//Generate the verilog at 2024-02-29T02:16:26
module top (
clk,
load,
rst_n,
rand_num,
seed
);

input clk ;
input load ;
input rst_n ;
output [7:0] rand_num ;
input [7:0] seed ;

wire _00_ ;
wire _01_ ;
wire _02_ ;
wire _03_ ;
wire _04_ ;
wire _05_ ;
wire _06_ ;
wire _07_ ;
wire _08_ ;
wire _09_ ;
wire _10_ ;
wire _11_ ;
wire _12_ ;
wire _13_ ;
wire _14_ ;
wire _15_ ;
wire _16_ ;
wire _17_ ;
wire _18_ ;
wire _19_ ;
wire _20_ ;
wire _21_ ;
wire _22_ ;
wire _23_ ;
wire _24_ ;
wire _25_ ;
wire _26_ ;
wire _27_ ;
wire _28_ ;
wire _29_ ;
wire _30_ ;
wire _31_ ;
wire _32_ ;
wire _33_ ;
wire _34_ ;
wire _35_ ;
wire _36_ ;
wire _37_ ;
wire _38_ ;
wire _39_ ;
wire _40_ ;
wire _41_ ;
wire _42_ ;
wire _43_ ;
wire \rand_num[4] ;
wire \seed[7] ;
wire load ;
wire \rand_num[5] ;
wire \seed[4] ;
wire \seed[3] ;
wire \rand_num[2] ;
wire \seed[1] ;
wire \rand_num[1] ;
wire \seed[0] ;
wire \rand_num[6] ;
wire \seed[5] ;
wire \rand_num[7] ;
wire \seed[6] ;
wire \rand_num[3] ;
wire \seed[2] ;
wire \rand_num[0] ;
wire clk ;
wire rst_n ;

XOR2_X2 _44_ ( .A(_23_ ), .B(_20_ ), .Z(_17_ ) );
XNOR2_X2 _45_ ( .A(_24_ ), .B(_22_ ), .ZN(_18_ ) );
XNOR2_X1 _46_ ( .A(_17_ ), .B(_18_ ), .ZN(_19_ ) );
MUX2_X1 _47_ ( .A(_19_ ), .B(_35_ ), .S(_16_ ), .Z(_15_ ) );
MUX2_X1 _48_ ( .A(_25_ ), .B(_32_ ), .S(_16_ ), .Z(_12_ ) );
MUX2_X1 _49_ ( .A(_24_ ), .B(_31_ ), .S(_16_ ), .Z(_11_ ) );
MUX2_X1 _50_ ( .A(_22_ ), .B(_29_ ), .S(_16_ ), .Z(_09_ ) );
MUX2_X1 _51_ ( .A(_21_ ), .B(_28_ ), .S(_16_ ), .Z(_08_ ) );
MUX2_X1 _52_ ( .A(_26_ ), .B(_33_ ), .S(_16_ ), .Z(_13_ ) );
MUX2_X1 _53_ ( .A(_27_ ), .B(_34_ ), .S(_16_ ), .Z(_14_ ) );
MUX2_X1 _54_ ( .A(_23_ ), .B(_30_ ), .S(_16_ ), .Z(_10_ ) );
BUF_X1 _55_ ( .A(\rand_num[4] ), .Z(_24_ ) );
BUF_X1 _56_ ( .A(\seed[7] ), .Z(_35_ ) );
BUF_X1 _57_ ( .A(load ), .Z(_16_ ) );
BUF_X1 _58_ ( .A(_15_ ), .Z(_07_ ) );
BUF_X1 _59_ ( .A(\rand_num[5] ), .Z(_25_ ) );
BUF_X1 _60_ ( .A(\seed[4] ), .Z(_32_ ) );
BUF_X1 _61_ ( .A(_12_ ), .Z(_04_ ) );
BUF_X1 _62_ ( .A(\seed[3] ), .Z(_31_ ) );
BUF_X1 _63_ ( .A(_11_ ), .Z(_03_ ) );
BUF_X1 _64_ ( .A(\rand_num[2] ), .Z(_22_ ) );
BUF_X1 _65_ ( .A(\seed[1] ), .Z(_29_ ) );
BUF_X1 _66_ ( .A(_09_ ), .Z(_01_ ) );
BUF_X1 _67_ ( .A(\rand_num[1] ), .Z(_21_ ) );
BUF_X1 _68_ ( .A(\seed[0] ), .Z(_28_ ) );
BUF_X1 _69_ ( .A(_08_ ), .Z(_00_ ) );
BUF_X1 _70_ ( .A(\rand_num[6] ), .Z(_26_ ) );
BUF_X1 _71_ ( .A(\seed[5] ), .Z(_33_ ) );
BUF_X1 _72_ ( .A(_13_ ), .Z(_05_ ) );
BUF_X1 _73_ ( .A(\rand_num[7] ), .Z(_27_ ) );
BUF_X1 _74_ ( .A(\seed[6] ), .Z(_34_ ) );
BUF_X1 _75_ ( .A(_14_ ), .Z(_06_ ) );
BUF_X1 _76_ ( .A(\rand_num[3] ), .Z(_23_ ) );
BUF_X1 _77_ ( .A(\seed[2] ), .Z(_30_ ) );
BUF_X1 _78_ ( .A(_10_ ), .Z(_02_ ) );
BUF_X1 _79_ ( .A(\rand_num[0] ), .Z(_20_ ) );
DFFR_X1 _80_ ( .CK(clk ), .D(_00_ ), .Q(\rand_num[0] ), .QN(_36_ ), .RN(rst_n ) );
DFFR_X1 _81_ ( .CK(clk ), .D(_01_ ), .Q(\rand_num[1] ), .QN(_37_ ), .RN(rst_n ) );
DFFR_X1 _82_ ( .CK(clk ), .D(_02_ ), .Q(\rand_num[2] ), .QN(_38_ ), .RN(rst_n ) );
DFFR_X1 _83_ ( .CK(clk ), .D(_03_ ), .Q(\rand_num[3] ), .QN(_39_ ), .RN(rst_n ) );
DFFR_X1 _84_ ( .CK(clk ), .D(_04_ ), .Q(\rand_num[4] ), .QN(_40_ ), .RN(rst_n ) );
DFFR_X1 _85_ ( .CK(clk ), .D(_05_ ), .Q(\rand_num[5] ), .QN(_41_ ), .RN(rst_n ) );
DFFR_X1 _86_ ( .CK(clk ), .D(_06_ ), .Q(\rand_num[6] ), .QN(_42_ ), .RN(rst_n ) );
DFFR_X1 _87_ ( .CK(clk ), .D(_07_ ), .Q(\rand_num[7] ), .QN(_43_ ), .RN(rst_n ) );

endmodule
