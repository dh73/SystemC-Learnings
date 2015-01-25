/*
 * main.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#include "counter.h"
#include "stim.h"


int sc_main( int argc, char* argv[]){

	cout<<"Simple counter example" << endl;

	sc_trace_file *tf=sc_create_vcd_trace_file("counter");
	tf->set_time_unit(1, SC_NS);

	sc_signal<bool> clk, reset;
	sc_signal<sc_uint<BITS> > q;

	stim U0("U0");
	U0.clk(clk);

	counter U1("U1");
	U1.clk(clk); U1.reset(reset); U1.q(q);

	sc_trace(tf, clk, "clock_signal");
	sc_trace(tf, reset, "reset");
	sc_trace(tf, q, "counter");

	reset.write(1);
	sc_start(100, SC_NS);
	reset.write(0);
	cout<<"Exiting from reset at " << sc_time_stamp() << endl;

	sc_start(500, SC_MS);

	cout << "Finished at " << sc_time_stamp() << "\n";

	return 0;
}
