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
    output [ 7:0] seg0
);
  wire       rst_n;
  wire       load;
  wire       clk_lfsr;

  reg  [7:0] rand_num;
  reg  [7:0] seed;

  assign rst_n     = ~rst;
  assign clk_lfsr  = sw[8];
  assign ledr[7:0] = rand_num[7:0];
  assign seed[7:0] = sw[7:0];
  assign load      = sw[9];

  LFSR lfsr1 (
      rst_n,
      clk_lfsr,
      load,
      seed,
      rand_num
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

