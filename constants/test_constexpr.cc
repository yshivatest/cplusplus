/*
 * test_constexpr.cc
 *
 *  Created on: Aug 8, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	const int x = 7;
	constexpr int xx = x;
	const int y = argc;
	constexpr int yy = y;// This is an error
}
