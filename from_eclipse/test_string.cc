/*
 * test_string.cc
 *
 *  Created on: Jul 13, 2014
 *      Author: syerramreddy
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>

using namespace std;
template<typename T>
class Vec : public vector<T> {
public:
	using vector<T>::vector;
	T& operator[](int i) { return vector<T>::at(i);}
	const T& operator[](int i) const {return vector<T>::at(i);}
};
int main() {
	std::string temp = "siva";
	std::cout<<"temp length is "<<temp.length()<<",cstr len ="<<strlen(temp.c_str());
	std::cout<<strlen("siva")<<endl;
	std::basic_string<char> x;
	//std::cin>>x;
	//std::cout<<x;
	//int y;
	//while(std::cin>>y)
		//std::cout<<y<<" ";
	Vec<int> v(10);
	cout<<v[1]<<v.size()<<v.capacity();
}


