module top (
    input         clk,
    input         rst,
    input  [13:0] sw,
    input         ps2_clk,
    input         ps2_data,
    output [15:0] ledr,
    output        VGA_CLK,
    output        VGA_HSYNC,
    output        VGA_VSYNC,
    output        VGA_BLANK_N,
    output [ 7:0] VGA_R,
    output [ 7:0] VGA_G,
    output [ 7:0] VGA_B,
    output [ 7:0] seg0,
    output [ 7:0] seg1,
    output [ 7:0] seg2,
    output [ 7:0] seg3,
    output [ 7:0] seg4,
    output [ 7:0] seg5
);
  wire       clrn;
  reg  [7:0] data;
  reg        nextdata_n;

  wire       ready;
  wire       overflow;
  reg  [7:0] data_out;
  reg  [7:0] ascii_out;
  reg  [7:0] count_ready;

  assign clrn = sw[8];

  ps2_keyboard ps_contr1 (
      clk,
      clrn,
      ps2_clk,
      ps2_data,
      data,
      ready,
      nextdata_n,
      overflow
  );


  always @(negedge clk) begin
    if (ready != 1'b0) begin
      if (data != 8'hf0) begin
        data_out = data;
        $display("receive %x", data_out);
      end
      nextdata_n <= 0;
    end else begin
      nextdata_n <= 1;
    end
  end

  reg [7:0] hex_num_1;
  reg [7:0] hex_num_2;

  always @(negedge clk) begin
    if (ready != 1'b0) begin
      if (data == 8'hf0) begin
        count_ready = count_ready + 1;
        hex_num_2 <= (count_ready / 8'd10);
        hex_num_1 <= (count_ready % 8'd10);

        $display("count %d", count_ready);
      end
    end
  end


  ps2_to_ascii ps2ascii (
      data_out,
      ascii_out
  );

  hex7seg se1 (
      data_out[3:0],
      seg0  //a_g[6:0]->(a,b,c,d,e,f,g)
  );

  hex7seg se2 (
      data_out[7:4],
      seg1  //a_g[6:0]->(a,b,c,d,e,f,g)
  );

  hex7seg se3 (
      ascii_out[3:0],
      seg2  //a_g[6:0]->(a,b,c,d,e,f,g)
  );

  hex7seg se4 (
      ascii_out[7:4],
      seg3  //a_g[6:0]->(a,b,c,d,e,f,g)
  );
  hex7seg se5 (
      hex_num_1[3:0],
      seg4  //a_g[6:0]->(a,b,c,d,e,f,g)
  );

  hex7seg se6 (
      hex_num_2[3:0],
      seg5  //a_g[6:0]->(a,b,c,d,e,f,g)
  );



  assign VGA_CLK = clk;

  wire [ 9:0] h_addr;
  wire [ 9:0] v_addr;
  wire [23:0] vga_data;

  vga_ctrl my_vga_ctrl (
      .pclk    (clk),
      .reset   (rst),
      .vga_data(vga_data),
      .h_addr  (h_addr),
      .v_addr  (v_addr),
      .hsync   (VGA_HSYNC),
      .vsync   (VGA_VSYNC),
      .valid   (VGA_BLANK_N),
      .vga_r   (VGA_R),
      .vga_g   (VGA_G),
      .vga_b   (VGA_B)
  );


  vmem my_vmem (
      .h_addr  (h_addr),
      .v_addr  (v_addr[8:0]),
      .vga_data(vga_data)
  );

endmodule

module vmem (
    input  [ 9:0] h_addr,
    input  [ 8:0] v_addr,
    output [23:0] vga_data
);

  reg [23:0] vga_mem[524287:0];

  initial begin
    $readmemh("resource/picture.hex", vga_mem);
  end

  assign vga_data = vga_mem[{h_addr, v_addr}];

endmodule

