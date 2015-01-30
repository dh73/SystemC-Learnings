/*
 * counter0.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: diego
 */
#include "counter0.h"

SC_HAS_PROCESS( counter0 );

counter0::counter0( sc_module_name name_): sc_module(name_){
	SC_METHOD( prc_counter );
	sensitive << clk.pos() << reset;
}

void counter0::prc_counter(){

	if( reset.read()){
		count=0;
		cout<<"Reset port active at " << sc_time_stamp() << endl;
	} else {
		count ++;
		q.write(count);
	}
}
