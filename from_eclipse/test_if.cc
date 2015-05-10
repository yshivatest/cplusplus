/*
 * test_if.cc
 *
 *  Created on: Aug 8, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1)
		int x = argc; // This is supposed to be an error
	if(int x = argc) // Scope of x is just inside this if statement
		cout<<argc<<endl;
	else if (int x = argc + 1)
		cout<<argc<<endl;
}
