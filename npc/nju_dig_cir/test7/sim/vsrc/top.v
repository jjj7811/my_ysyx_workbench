module top (
    input            rst_n,
    input            clk,
    input            load,
    input      [7:0] seed,
    output reg [7:0] rand_num
);


  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) rand_num <= 8'b0;
    else if (load) rand_num <= seed;
    else begin
      rand_num[0] <= rand_num[1];
      rand_num[1] <= rand_num[2];
      rand_num[2] <= rand_num[3];
      rand_num[3] <= rand_num[4];
      rand_num[4] <= rand_num[5];
      rand_num[5] <= rand_num[6];
      rand_num[6] <= rand_num[7];
      rand_num[7] <= rand_num[0] ^ rand_num[2] ^ rand_num[3] ^ rand_num[4];
    end

  end
endmodule
