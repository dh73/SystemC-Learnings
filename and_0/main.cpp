#include "driver.hpp"
#include "monitor.hpp"
#include "and_0.hpp"

int sc_main(int argc, char* argv[]){

	sc_signal<bool> t_a, t_b, t_y;

	and_0 A0("AndSystemC");
	A0.a(t_a);
	A0.b(t_b);
	A0.y(t_y);

	driver d1("GenerateWaveforms");
	d1.d_a(t_a);
	d1.d_b(t_b);

	monitor M1("MonitorWaveforms");
	M1.m_a(t_a);
	M1.m_b(t_b);
	M1.m_y(t_y);

	sc_start(100, SC_NS);

	cout<<endl;

	return 0;
}