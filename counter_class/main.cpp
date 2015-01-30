/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: diego
 */

#include "counter0.h"
#include "stim.h"

int sc_main( int argc, char *argv[] ){

	cout<<"Counter class/has_process example" << endl;

	//Start trace files
	sc_trace_file *mytrace=sc_create_vcd_trace_file("trace");
	mytrace->set_time_unit(1, SC_NS);

	//Create objects for connecting modules
	sc_signal<bool> clk, reset;
	sc_signal<sc_uint<8> > q;

	//Instantiate objects
	stim		stimgen("stimgen");
	counter0	C0("counter0"); //Name and output Width

	//Conect ports
	stimgen.clk(clk);
	C0.clk(clk); C0.reset(reset); C0.q(q);

	//Generate traces
	sc_trace(mytrace, clk, "clk");
	sc_trace(mytrace, reset, "reset");
	sc_trace(mytrace, q, "q");

	//Make bad stimulus
	reset.write(1);
	sc_start(10, SC_NS);
	reset.write(0);
	cout<<"Exiting from reset at " << sc_time_stamp() << endl;

	sc_start(1000, SC_NS);
	cout << "Set input high at " << sc_time_stamp() << "\n";
	sc_start(1000, SC_NS);
	cout << "Finished at " << sc_time_stamp() << "\n";

	return 0;
}
