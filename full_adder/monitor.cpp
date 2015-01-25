#include "monitor.hpp"

void monitor::prc_monitor(){
	cout<<"At time "<< sc_time_stamp() << " :: ";
	cout<< "(a, b, carry_in): ";
	cout<< m_a << m_b << m_cin;
	cout<<" (sum, carry_out): "<<m_sum << m_cout << endl;
}