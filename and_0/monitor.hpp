#include "systemc.h"

SC_MODULE(monitor){
	sc_in<bool> m_a, m_b, m_y;

	void prc_monitor(){
		cout<<"At time "<<sc_time_stamp() << " :: ";
		cout<<"(A, B, Y): ";
		cout<<m_a<<m_b<<m_y <<endl;
	}

	SC_CTOR(monitor){
		SC_METHOD(prc_monitor);
		sensitive<<m_a<<m_b<<m_y;
	}
};