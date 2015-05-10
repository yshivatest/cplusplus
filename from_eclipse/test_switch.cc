/*
 * test_switch.cc
 *
 *  Created on: Aug 8, 2014
 *      Author: syerramreddy
 */
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	switch(argc) {
	case 0:
		int x;
		int y = 0; // This is an error at compile time
		break;
	case 1:
		x++;
		y++;
	}
}
