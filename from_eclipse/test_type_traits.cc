/*
 * test_type_traits.cc
 *
 *  Created on: Jul 28, 2014
 *      Author: syerramreddy
 */

#include <iostream>
#include <type_traits>
using namespace std;

int main()
{
	bool x = is_arithmetic<string>::value;
	cout<<x<<endl;
}
