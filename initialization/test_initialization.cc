/*
 * test_initialization.cc
 *
 *  Created on: Jul 29, 2014
 *      Author: syerramreddy
 */
#include <iostream>
using namespace std;
constexpr int siva_ = 3;
class Siva {
	int x_;
public:
	Siva(int x) : x_{x} {}
	void print() {cout<<x_<<endl;}
};
int main()
{
	Siva x {2};
	x.print();
}
