#include "half_adder.hpp"

void half_adder::prc_half_adder(){
	sum = a ^ b;
	carry = a & b;
}