/*
 * shiftreg.h
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#ifndef SHIFTREG_H_
#define SHIFTREG_H_

#include "systemc.h"
#include "dff.h"
#include <iostream>

SC_MODULE( shiftreg ){
	sc_in<bool>   clk, reset, din;
	sc_out<bool>  dout;

	sc_signal<bool> s1;

	dff dff1, dff2; //Instantiation of D flip flop models

	SC_CTOR( shiftreg): dff1("dff1"), dff2("dff2"){

		dff1.clk(clk); dff1.reset(reset); dff1.d(din); dff1.q(s1);
		dff2.clk(clk); dff2.reset(reset); dff2.d(s1);  dff2.q(dout);

	}
};



#endif /* SHIFTREG_H_ */
