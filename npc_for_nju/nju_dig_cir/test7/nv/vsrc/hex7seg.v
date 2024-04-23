module hex7seg(
input[3:0]           x,
output reg[7:0]          a_g//a_g[6:0]->(a,b,c,d,e,f,g)
);

always@(x)begin
	case(x)        //用case语句实现组合逻辑
		4'd0:begin a_g<=~8'b1111_1100;end
		4'd1:begin a_g<=~8'b0110_0000;end
		4'd2:begin a_g<=~8'b1101_1010;end
		4'd3:begin a_g<=~8'b1111_0010;end
		4'd4:begin a_g<=~8'b0110_0110;end
		4'd5:begin a_g<=~8'b1011_0110;end
		4'd6:begin a_g<=~8'b1011_1110;end
		4'd7:begin a_g<=~8'b1110_0000;end
		4'd8:begin a_g<=~8'b1111_1110;end
		4'd9:begin a_g<=~8'b1111_0110;end

		4'd10:begin a_g<=8'b0001_0000;end
		4'd11:begin a_g<=8'b1100_0000;end
		4'd12:begin a_g<=8'b0110_0010;end
		4'd13:begin a_g<=8'b1000_0100;end
		4'd14:begin a_g<=8'b0110_0000;end
		4'd15:begin a_g<=8'b0111_0000;end

		default:begin a_g<=8'b0000_0010;end//num超出（0-9）时，用default统一处理，显示为中杠；
	endcase

end
endmodule
