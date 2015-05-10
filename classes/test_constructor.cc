/*
 * test_constructor.cc
 *
 *  Created on: Aug 5, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;

class Siva {
public:
	Siva() {cout<<"default constructor called\n";}
};
int main()
{
	Siva x;
	cout<<"x created\n";
	Siva y{};
	cout<<"y created\n";
	Siva *p = &x;
	void *v = p;
	// p = v; This statement gives a compile error

}
