#include "systemc.h"

SC_MODULE(driver){
	sc_out<bool> d_a, d_b;

	void prc_driver(){
		sc_uint<2> pattern; //Integer of 2 bits?
		pattern=0;

		while(1){
			d_a=pattern[0];
			d_b=pattern[1];
			wait(5, SC_NS);
			pattern++;
		}
	}

	SC_CTOR(driver){
		SC_THREAD(prc_driver);
	}
};