/*
 * test_exception.cc
 *
 *  Created on: Jul 22, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include<stdexcept>

namespace XYZ {
	void foo()
	{
		throw new std::out_of_range("siva");
	}
	void bar()
	{
		try {
		foo();
		static_assert(3>=sizeof(int), "integers are too big");
		} catch(std::out_of_range ex) {
			std::cout<<"caught exception\n";
			throw;
		}
	}
}

int main()
{
	static_assert(3>=sizeof(int), "integers are too small");
	XYZ::bar();
}

