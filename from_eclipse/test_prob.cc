/*
 * test_prob.cc
 *
 *  Created on: Aug 11, 2014
 *      Author: syerramreddy
 */

#include<iostream>
using namespace std;
#include<random>
#include <limits.h>

unsigned int siva_pow(int i)
{
	unsigned int val = 1;
	for (int j = 0; j < i; j++)
		val *= 257;
	return val;
}

int main()
{
	unsigned int coefficient[8];
	for (int i = 7, j = 0; i >= 0; i--, j++) {
		// math's pow takes double and returns double, so it has slight inaccuracy
		coefficient[j] = siva_pow(i);
	}
	for (int i = 0; i < 8; i++)
		cout<<hex<<"0x"<<coefficient[i]<<endl;
	random_device generator;
	uniform_int_distribution<unsigned long> distribution(0, ULONG_MAX);
	unsigned long dice_roll = distribution(generator);
	cout<<"0x"<<dice_roll<<endl;
}
