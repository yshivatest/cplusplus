#include<iostream>
using namespace std;

class A {
    public:
    int x;
    A(int i) { x = i; cout<<"A::A() "<<this<<endl;}
    void print() { cout<<"print() "<<x<<endl;}
};

/* 
 * Declaring a B type object calls A's constructor but declaring a D type object
 * doesn't call A's constructor from B's constructor. A's constructor is called
 * directly by D's constructor
 */
class B: virtual public A {
    public:

    B():A(10) {cout<<"B::B() this="<<this<<endl;}
    void bprint(){cout<<"B::print() "<<x<<endl;}
};

class C: virtual public A {
    public:
    C():A(10) {cout<<"C::C() this="<<this<<endl;}
};

class D: public B, public C {
    public:
    D():A(10),B(),C() {}
};

int main()
{
    D d;
    d.print();
    A *ap = &d;
    B *bp = &d;
    C *cp = &d;
    D *dp = &d;
    cout<<"A address = "<<ap<<",B address = "<<bp<<",C address = "<<cp<<",D address = "<<dp<<endl;
    B x;
    C y;
    return 0;
}

