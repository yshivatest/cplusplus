/*
 * template.cc
 *
 *  Created on: Jul 12, 2014
 *      Author: syerramreddy
 */
#include <iostream>
#include <cstdlib>


template <typename T>
class SVector {
private:
	T *elmt;
	int sz;
public:
	explicit SVector(int x) : elmt(new T[x]), sz(x) {}
	~SVector() {delete[] elmt;}
	T& operator[](int i) {return elmt[i];}
	int size() {return sz;}
	T* begin() { std::cout<<"begin called\n"; return (sz==0?nullptr:&elmt[0]);}
	T* end() { std::cout<<"end called\n";return elmt + sz; }
	class x {
	public:
		int y;
	};
};

class Nivi {
private:
	int y;
};

template<typename C>
using s_size =  typename C::x;
int main(){
	SVector<int> x(3);
	for(int& a: x) {
		std::cout<<a<<std::endl;
	}
	s_size<SVector<int>> a;
	std::cout<<a.y<<std::endl;
}
