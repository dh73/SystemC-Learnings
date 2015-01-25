/*
 * counter.h
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include "systemc.h"
#include <iostream>

#define BITS  32

SC_MODULE(counter){

	sc_in<bool> clk, reset;
	sc_out<sc_uint<BITS> > q;

	void prc_counter(){

		if(reset.read())
			q.write(0);
		else {
			int nv = q.read() + 1;
			cout<<"Counter pending set to " << nv << endl;
			q.write(nv);
		}
	}

	SC_CTOR(counter){
		SC_METHOD( prc_counter );
		sensitive << clk.pos() << reset.pos();
	}

};



#endif /* COUNTER_H_ */
