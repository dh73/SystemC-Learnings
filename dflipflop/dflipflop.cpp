#include "dflipflop.h"


void dflipflop::behaviour(){
  if( reset.read() == 1)
    dout=0;
  else
    dout=din;
};
  
