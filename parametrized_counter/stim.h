/*
 * stim.h
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#ifndef STIM_H_
#define STIM_H_

#include "systemc.h"
#include <iostream>

SC_MODULE(stim){
	sc_out<bool> clk;

	void prc_stim(){
		cout<<"Start clk on 0" << endl;
		clk.write(0);
		while(1){
			cout<<"Toggle at " << sc_time_stamp() << endl;
			wait(50, SC_NS);
			clk.write(!clk.read());
		}
	}

	SC_CTOR(stim){
		SC_THREAD(prc_stim);
	}

};


#endif /* STIM_H_ */
