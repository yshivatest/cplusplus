/*
 * test_initialize.cc
 *
 *  Created on: Jul 22, 2014
 *      Author: syerramreddy
 */

#include<iostream>

int main() {
	int x {2.0}; /* This line yields a warning by the compiler */
	int y =  2.0; /* This doesn't yield any warning */
	std::cout<<"temp";
	int &z = y;
	std::cout<<&z<<","<<&y;
	int *a = nullptr;
}
