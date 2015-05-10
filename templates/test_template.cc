/*
 * test_template.cc
 *
 *  Created on: Jul 28, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include<map>
using namespace std;

void foo() { };

template<typename T, typename... Tail>
void foo(T x,Tail... y)
{
	cout<<x<<endl;
	foo(y...);
}

template<typename T, int N>
class Siva {
public:
	using value_type = T;
	constexpr  int value() {return N;};
};
template<typename T>
using ElementType = typename T::value_type;

template<typename Val>
using String_map = map<string, Val>;
int main()
{
	foo(1,2,3);
}
