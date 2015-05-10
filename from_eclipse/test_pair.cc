/*
 * test_pair.cc
 *
 *  Created on: Jul 28, 2014
 *      Author: syerramreddy
 */
#include <iostream>
#include <utility>

std::pair<int, int> foo()
{
	return std::make_pair(2,3);
}

int main()
{
	auto x = foo();
	std::cout<<"first ="<<x.first<<",second="<<x.second<<std::endl;
}
