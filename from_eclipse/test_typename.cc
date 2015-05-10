/*
 * test_typename.cc
 *
 *  Created on: Jul 18, 2014
 *      Author: syerramreddy
 */
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> x;
	using y = typename list<int>::iterator;

}
