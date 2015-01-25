/*
 * dff.h
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#ifndef DFF_H_
#define DFF_H_

#include "systemc.h"
#include <iostream>

SC_MODULE( dff ){

	sc_in<bool>   clk, reset, d;
	sc_out<bool>  q;

	void prc_dff(){
		if(reset.read())
			q.write(0);
		else{
			q.write(d.read());
			cout<<"DFF pending set to " << d.read() << endl;
		}
	}

	SC_CTOR( dff ){
		SC_METHOD( prc_dff );
		sensitive << clk.pos() << reset;
	}
};



#endif /* DFF_H_ */
