/*
 * test_unique_ptr.cc
 *
 *  Created on: Jul 23, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include<memory>
using namespace std;

class Siva {
public:
	Siva() {cout<<"Siva constructor called\n";}
	~Siva() {cout<<"Siva destructor called\n";}
};
unique_ptr<int> foo()
{
	return unique_ptr<int>{new int[10]};
}
unique_ptr<Siva> bar()
{
	return unique_ptr<Siva> {new Siva()};
}
int main()
{
	cout<<"Testing unique ptr semantics\n";
	{
		auto x = bar();
	}
	cout<<"Siva destructor should have been called now \n";
}
