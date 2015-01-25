// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.10-p100  (32 bit), build 50398 Tue, 27 May 2014
// 
// File created on Sat Oct 11 22:28:08 2014
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module dflipflop_current(din, clk, reset, dout);
  input din;
  input clk;
  input reset;
  output reg dout;
  reg din_check;

  always begin : dflipflop_behaviour
    reg state_dflipflop;
    reg joins_dflipflop;
    reg read_dflipflop_din_ln8;

    joins_dflipflop = 1'b0;
    if (reset) begin
      din_check = din;
      dout <= 1'bX;
      read_dflipflop_din_ln8 = din;
      dout <= 1'b0;
      joins_dflipflop = 1'b1;
    end
    else begin
      proc_ln4_checker;
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
  task proc_ln4_checker;
    begin : proc_ln4_checker
      if (din_check != din) begin
        $display(
        "Warning: Potential race condition detected in module %m @ time %0d:\n", $time);
        $stop(1);
      end
    end
  endtask

endmodule


