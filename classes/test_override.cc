/*
 * test_override.cc
 *
 *  Created on: Jul 23, 2014
 *      Author: syerramreddy
 */
#include <iostream>
using namespace std;
namespace XYZ {
	class Siva1 {
	public:
		void foo() { cout<<"Siva1 foo called\n"; }
		virtual void bar() { cout<<"Siva1 bar called\n"; }
	};
	class Siva2 : public Siva1{
	public:
	 void foo() //override <--- this causes compile error as foo is not declared virtual in the base class
	 {cout<<"Siva2 foo called\n";}
	 void bar() override
	 {cout<<"Siva2 bar called\n"; }
	};
}
int main()
{
	using namespace XYZ;
	cout<<"Testing override on virtual and non-virtual functions\n";
	Siva1 *x = new Siva2();
	x->foo();// Calls Siva1's foo
	Siva2 *y = dynamic_cast<Siva2*>(x);
	y->foo();// Calls Siva2's foo
}
