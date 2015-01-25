#include "systemc.h"

SC_MODULE( monitor ){
	sc_in<bool> m_a, m_b, m_cin, m_sum, m_cout;

	void prc_monitor();

	SC_CTOR( monitor ){
		SC_METHOD( prc_monitor );
		sensitive<<m_a<<m_b<<m_cin<<m_sum<<m_cout;
	}
};

void monitor::prc_monitor(){
	cout<<"At time "<< sc_time_stamp() << " :: ";
	cout<< "(a, b, carry_in): ";
	cout<< m_a << m_b << m_cin;
	cout<<" (sum, carry_out): "<<m_sum << m_cout << endl;
}