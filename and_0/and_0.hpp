#include "systemc.h"

SC_MODULE( and_0 ){

	sc_in<bool> a, b;
	sc_out<bool> y;

	void prc_and_0(){
		y=a&&b;
	}

	SC_CTOR( and_0 ){
		SC_METHOD(prc_and_0);
		sensitive<<a<<b;
	}
};