/*
 * test_copy_constructor.cc
 *
 *  Created on: Jul 30, 2014
 *      Author: syerramreddy
 */

#include<iostream>
using namespace std;

class Siva {
public:
	int x_;
	Siva(int x) : x_{x} {}
	Siva(Siva& s) {cout<<"Copy constructor called\n"; x_ = s.x_;}
	Siva(Siva&& s) {cout<<"move constructor called"<<x_<<endl;x_ = s.x_; cout<<"this="<<this<<",s="<<&s;}
	Siva& operator=(Siva&& s) {cout<<"move assignment= called"<<x_<<","<<s.x_<<endl;return *this;}
	Siva& operator=(Siva& s) {cout<<"Assignment operator called\n"; x_ = s.x_; return *this;}
	friend ostream& operator<<(ostream&, const Siva&);
};
ostream& operator<<(ostream& o, const Siva& s)
{
	cout<<"output operator called\n";
	o<<s.x_<<endl;
	return cout;
}
void foo(Siva x)
{
	cout<<"foo called- "<<x.x_<<endl;
}

void bar(Siva& x)
{
	cout<<"bar called - "<<x.x_<<endl;
}

Siva voodoo(Siva x)
{
	cout<<"voodoo called"<<&x<<endl;
	return x;
}
int main()
{
	Siva x(3);
	Siva y = x;
	Siva z(4);
	z = y;
	foo(z);
	bar(x);
	z = voodoo(x);
	cout<<z;
	Siva a = voodoo(x);
}
