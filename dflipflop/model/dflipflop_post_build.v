// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.10-p100  (32 bit), build 50398 Tue, 27 May 2014
// 
// File created on Sat Oct 11 22:26:53 2014
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module dflipflop_post_build(din, clk, reset, dout);
  input din;
  input clk;
  input reset;
  output reg dout;

  always begin : dflipflop_behaviour
    reg state_dflipflop;
    reg joins_dflipflop;
    reg read_dflipflop_din_ln8;

    joins_dflipflop = 1'b0;
    if (reset) begin
      dout <= 1'b0;
      joins_dflipflop = 1'b1;
    end
    else begin
      read_dflipflop_din_ln8 = din;
      dout <= read_dflipflop_din_ln8;
      joins_dflipflop = 1'b1;
    end
    // proc_ln4
    if (joins_dflipflop == 1'b1) begin
      joins_dflipflop = 1'b0;
      state_dflipflop <= 1'b0;
    end
    @(posedge clk);
  end
endmodule


