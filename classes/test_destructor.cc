/*
 * test_destructor.cc
 *
 *  Created on: Jul 23, 2014
 *      Author: syerramreddy
 */
#include<iostream>

namespace XYZ {
class Siva1 {
	int x_;
public:
	Siva1() :x_{0} {std::cout<<"Siva1 constructor called\n";}
	~Siva1() {std::cout<<"Siva1 destructor called\n";}
};
class Siva2 : public Siva1 {
	int y_;
public:
	Siva2(): y_{0} {std::cout<<"Siva2 constructor called\n";}
	~Siva2() {std::cout<<"Siva2 destructor called\n";}
};
}

int main()
{
	using namespace XYZ;
	Siva1 *x = new Siva2();
	delete x; // If the destructor of Siva1 is not virtual, only Siva1 destructor gets called here
	std::cout<<"nothing to print\n";
}

