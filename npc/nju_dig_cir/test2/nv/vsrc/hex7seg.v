module hex7seg(
input[2:0]           x,
output reg[7:0]          a_g//a_g[6:0]->(a,b,c,d,e,f,g)
);

always@(x)begin
	case(x)        //用case语句实现组合逻辑
		3'd0:begin a_g<=~8'b1111_1100;end
		3'd1:begin a_g<=~8'b0110_0000;end
		3'd2:begin a_g<=~8'b1101_1010;end
		3'd3:begin a_g<=~8'b1111_0010;end
		3'd4:begin a_g<=~8'b0110_0110;end
		3'd5:begin a_g<=~8'b1011_0110;end
		3'd6:begin a_g<=~8'b1011_1110;end
		3'd7:begin a_g<=~8'b1110_0000;end
		// 4'd8:begin a_g<=7'b111_1111;end
		// 4'd9:begin a_g<=7'b111_1011;end
		default:begin a_g<=8'b0000_0010;end//num超出（0-9）时，用default统一处理，显示为中杠；
	endcase

end
endmodule
