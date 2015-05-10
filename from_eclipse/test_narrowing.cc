/*
 * test_narrowing.cc
 *
 *  Created on: Aug 4, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;
using Char = char;
using UChar = unsigned char;
using USChar = unsigned Char;// This is supposed to be a compile error but doesn't give an error
int main()
{
	long x {10};
	int y = x;
	int z {x};
	char v1 {123456};
}

