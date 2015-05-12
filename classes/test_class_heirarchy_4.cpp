#include<iostream>
using namespace std;

class A {
    int x;
    public:
    A() {cout<<this<<endl;}
    void setX(int i) {x = i;}
    void print() { cout<<x<<endl;}
};

class B: public A {
    public:
    B() { setX(10);}
};

class C: public A {
    public:
    C() { setX(20);}
};

class D: public B, public C {
};

int main()
{
    D d;
    B *bp = &d;
    bp->print();
    C *cp = &d;
    cp->print();
    //d.print() gives compile error as it's an ambiguous call
    //d.print();
    return 0;
}

