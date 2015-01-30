/*
 * stim.h
 *
 *  Created on: Jan 29, 2015
 *      Author: diego
 */

#ifndef STIM_H_
#define STIM_H_
#include "systemc.h"

class stim: public sc_module{

	public:
		sc_out<bool> clk;
		void prc_stim();
		SC_CTOR( stim ){
			SC_THREAD( prc_stim );
		}
};

void stim::prc_stim(){
	clk.write(0);
	while(true){
		cout<<"Toggle at " << sc_time_stamp() << endl;
		wait(50, SC_NS);
		clk.write(!clk.read());
	}
}


#endif /* STIM_H_ */
