/*
 * test_star.cc
 *
 *  Created on: Jul 30, 2014
 *      Author: syerramreddy
 */

#include<iostream>
using namespace std;

class SivaIterator {
public:
	int *x_;
	int sz_;
	int i_;
	SivaIterator(int *x, int i, int sz) :x_{x}, sz_{sz}, i_{i} {}
	//int operator *() {cout<<"operator * called\n";return x_[i_];}
	int& operator *() {cout<<"* operator * called\n";return x_[i_];}
	SivaIterator& operator++() {cout<<"operator ++ called\n"; i_++; return *this;}
	SivaIterator operator++(int) {cout<<"++ operator called\n";i_++; return *this;}
	bool operator==(SivaIterator &x) {cout<<"== called\n"; return i_ == x.i_;}
	bool operator!=(SivaIterator &x) {cout<<"!= called\n"; return !(*this == x);}
	//ostream& operator<<(ostream& x) {x<<x_[i_]; return x;}
};

/*ostream& operator<<(SivaIterator *x, ostream& y)
{
	y<<x->x_<<endl;
	return y;
}*/

class Siva {
public:
	int *x_ = nullptr;
	int sz_ = 3;
	SivaIterator *it1_;
	Siva(int sz) :sz_{sz} {x_ = new int[sz_]; x_[0] = 5; it1_ = new SivaIterator(x_, 0, sz_);}
	SivaIterator begin() {cout<<it1_<<"begin called\n"; return *it1_;}
	SivaIterator end() {cout<<it1_+9<<"end called\n"; return *(new SivaIterator(x_, sz_, sz_));}
};

int main()
{
	Siva x(8);
	cout<<x.sz_<<endl;
	for(auto y:x) {
		cout<<y<<endl;
	}
	SivaIterator a(x.x_, 0, 8), b(x.x_, 0, 7);
	a++;++b;
	cout<<a;
	if (a != b)
		cout<<"true\n";
	else
		cout<<"false\n";
}
