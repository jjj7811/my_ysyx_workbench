module ps2_to_ascii(
    input [7:0] ps2_code, //PS2扫描码
    output reg [7:0] ascii_code //ASCII码
);

//定义一个参数数组，存储PS2扫描码与ASCII码的对应关系
parameter [7:0] code_table [0:93] = {
    8'h1C, 8'h41, //A
    8'h32, 8'h42, //B
    8'h21, 8'h43, //C
    8'h23, 8'h44, //D
    8'h24, 8'h45, //E
    8'h2B, 8'h46, //F
    8'h34, 8'h47, //G
    8'h33, 8'h48, //H
    8'h43, 8'h49, //I
    8'h3B, 8'h4A, //J
    8'h42, 8'h4B, //K
    8'h4B, 8'h4C, //L
    8'h3A, 8'h4D, //M
    8'h31, 8'h4E, //N
    8'h44, 8'h4F, //O
    8'h4D, 8'h50, //P
    8'h15, 8'h51, //Q
    8'h2D, 8'h52, //R
    8'h1B, 8'h53, //S
    8'h2C, 8'h54, //T
    8'h3C, 8'h55, //U
    8'h2A, 8'h56, //V
    8'h1D, 8'h57, //W
    8'h22, 8'h58, //X
    8'h35, 8'h59, //Y
    8'h1A, 8'h5A, //Z
    8'h45, 8'h30, //0
    8'h16, 8'h31, //1
    8'h1E, 8'h32, //2
    8'h26, 8'h33, //3
    8'h25, 8'h34, //4
    8'h2E, 8'h35, //5
    8'h36, 8'h36, //6
    8'h3D, 8'h37, //7
    8'h3E, 8'h38, //8
    8'h46, 8'h39, //9
    8'h0E, 8'h60, //`
    8'h4E, 8'h2D, //-
    8'h55, 8'h3D, //=
    8'h5D, 8'h5C, //\
    8'h54, 8'h5B, //[
    8'h5B, 8'h5D, //]
    8'h4C, 8'h3B, //;
    8'h52, 8'h27, //'
    8'h41, 8'h2C, //,
    8'h49, 8'h2E, //.
    8'h4A, 8'h2F ///
};

//定义一个整数变量，用于存储PS2扫描码在参数数组中的索引
integer index;

//定义一个始终块，当PS2扫描码发生变化时，根据参数数组查找对应的ASCII码
always @(ps2_code) begin
    //初始化索引为-1，表示未找到
    index = -1;
    //遍历参数数组，寻找与PS2扫描码相同的元素
    for (integer i = 0; i < 47; i = i + 1) begin
        //如果找到了，记录索引，并跳出循环
        if (ps2_code == code_table[i]) begin
            // $display("ps2: %x, ascii:%x", ps2_code,code_table[i+1]);
            index = i;
            break;
        end
    end
    //如果索引不为-1，说明找到了对应的ASCII码，否则输出空字符
    if (index != -1) begin
        ascii_code = code_table[index + 1];
        // $display("receive %x", ascii_code);
    end else begin
        ascii_code = 8'h00;
    end
end

endmodule