/*
 * test_new.cc
 *
 *  Created on: Jul 22, 2014
 *      Author: syerramreddy
 */

#include<iostream>

class Siva {
public:
	Siva(int x) :x_(x) {std::cout<<"non-initializer list constructor called\n";}
	Siva(int x, int y) : x_{x}, y_{y} {std::cout<<"non-initializer list constructor called\n";}
	Siva(std::initializer_list<int> x){std::cout<<"initializer list constructor called\n";}
	int x_;
	int y_;
};
int main()
{
	Siva *x = new Siva(1);
	std::cout<<"first done\n";
	Siva *y = new Siva{1};
	std::cout<<"second done\n";
	Siva *z = new Siva{1,2};
	std::cout<<"third done\n";
	Siva *a = new Siva(1,2);
	std::cout<<"fourth done\n";
	// Siva *b = new Siva(1,2,3); This gives compiler error as it doesn't get converted to initializer-list automatically without flower brace
}

