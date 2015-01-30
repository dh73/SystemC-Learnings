/*
 * counter0.h
 *
 *  Created on: Jan 29, 2015
 *      Author: diego
 */

#ifndef COUNTER0_H_
#define COUNTER0_H_

#include "systemc.h"
#include <iostream>

class counter0: public sc_module{

	public:
		sc_in<bool> clk, reset;
		sc_out<sc_uint<8> > q;
		sc_uint<8> count;
		void prc_counter();
		counter0( sc_module_name name_);

};



#endif /* COUNTER0_H_ */
