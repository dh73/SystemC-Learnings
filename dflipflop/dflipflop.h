#include "systemc.h"

SC_MODULE ( dflipflop ){
  sc_in  < bool > din;
  sc_in  < bool > clk;
  sc_in  < bool > reset;
  sc_out < bool > dout;

  void behaviour ();
  
  SC_CTOR ( dflipflop ){
    SC_METHOD( behaviour );
    sensitive << clk.pos();
  }

};

SC_MODULE_EXPORT (dflipflop);

