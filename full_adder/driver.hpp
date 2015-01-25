#include "systemc.h"

SC_MODULE( driver ){
	sc_out<bool> d_a, d_b, d_cin;

	void prc_driver();

	SC_CTOR( driver ){
		SC_THREAD( prc_driver );
	}
};


void driver::prc_driver(){
	sc_uint<3> pattern;
	pattern=0;

	while(1){
		d_a=pattern[0];
		d_b=pattern[1];
		d_cin=pattern[2];
		wait(5, SC_NS);
		pattern++;
	}
}