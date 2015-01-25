/*
 * main.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: diego
 */

#include "dff.h"
#include "shiftreg.h"
#include "stim.h"

int sc_main( int argc, char *argv[]){

	cout<<"Shift Register Example" << endl;

	sc_trace_file *tf=sc_create_vcd_trace_file("trace");
	tf->set_time_unit(1, SC_NS);

	sc_signal<bool> clk, serialin, serialout, reset;

	stim 		U0("U0");
	U0.clk(clk);

	shiftreg	U1("U1");
	U1.clk(clk); U1.reset(reset); U1.din(serialin); U1.dout(serialout);

	sc_trace(tf, serialin, "serialin");
	sc_trace(tf, serialout, "serialout");
	sc_trace(tf, clk, "clk");
	sc_trace(tf, reset, "reset");

	reset.write(1);
	serialin.write(0);
	sc_start(1000, SC_NS);
	reset.write(0);

	cout<<"Exiting from reset at " << sc_time_stamp() << endl;

	sc_start(2000, SC_NS);
	serialin = 1;
	cout << "Set input high at " << sc_time_stamp() << "\n";
	sc_start(2000, SC_NS);

	cout << "Finished at " << sc_time_stamp() << "\n";

return 0;

}
