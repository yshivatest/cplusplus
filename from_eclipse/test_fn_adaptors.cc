/*
 * test_fn_adaptors.cc
 *
 *  Created on: Jul 18, 2014
 *      Author: syerramreddy
 */
#include <iostream>
#include <functional>
using namespace std;

void foo(int a, int b)
{
	cout<<"called foo"<<a<<b<<endl;
}

int main()
{
	function<void(int)> x = std::bind(foo, 2, placeholders::_1);
	x(1);
	cout<<"siva\n";
	x(2);
}

