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
	Siva(Siva&& s) {cout<<"move constructor called"<<x_<<endl;x_ = s.x_; cout<<"this="<<this<<",s="<<&s<<endl;}
	Siva& operator=(Siva&& s) {cout<<"move assignment= called"<<x_<<","<<s.x_<<endl;return *this;}
	Siva& operator=(Siva& s) {cout<<"Assignment operator called\n"; x_ = s.x_; return *this;}
	friend ostream& operator<<(ostream&, const Siva&);
};

class Krishna {
    public:
        Krishna() {}
        Krishna(Krishna& k){}
        Krishna(Krishna&& k){}
};
void temp(int &x, Siva &y) {
    cout<<"reference temp called\n";
}

void temp(int&& x, Siva&& y) {
    cout<<"move temp called\n";
}

void temp2(Krishna& x, Siva &y) {
    cout<<"reference temp2 called\n";
}

void temp2(Krishna &&x, Siva &&y) {
    cout<<"move temp2 called\n";
}

#if 0
template<typename T1, typename T2>
void template_temp(T1 &x, T2 &&y)
{
}
#endif
template<typename T1, typename T2>
void template_temp(T1 &&x, T2 &&y)
{
}

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
int g_x = 9;
int main()
{
	Siva x(3);
	Siva y = x;
	Siva z(4);
	z = y;
	foo(z);
	bar(x);
	z = voodoo(x);
	//cout<<z;
	Siva a = voodoo(x);
    //temp(1, a);
    temp(std::move(g_x), std::move(a));
    Krishna k;
    temp2(k, std::move(a));
    template_temp(k, std::move(a));
}
