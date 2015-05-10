/*
 * test_return.cc
 *
 *  Created on: Aug 4, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;

auto foo(int a) -> int
{
	return a+3;
}

int main()
{
	cout<<foo(2)<<endl;
}
