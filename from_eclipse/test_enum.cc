/*
 * test_enum.cc
 *
 *  Created on: Jul 22, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include<stdexcept>
class Temp {
	static int x;
};
enum  class Siva {
	RED, BLUE

};
Siva& operator++(Siva& x) {
	switch(x) {
	case Siva::RED: return x = Siva::BLUE;
	case Siva::BLUE: return x = Siva::RED;
	}
}
namespace XYZ {
void foo() {
	std::cout<<"foo\n";
	throw new std::out_of_range();
}
}
int main() {
	/*Siva x = Siva::RED;
	std::cout<<x;*/
	//Siva y = 0;/* Compile error as we can't assign integer to enum class */
	try {
		XYZ::foo();
	} catch(...) {

	}
}


