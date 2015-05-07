#include<iostream>
using namespace std;

class A {
public:
    static int i;
    A() {cout<<"A constructor called\n";}
    int a;
    int b;
    virtual void foo()
    {
        cout<<"A::foo\n";
    }
    virtual void bar()
    {
        cout<<"A::bar\n";
    }
    ~A(){}
};
int A::i = 0;
class B : public A {
public:
    B() {cout<<"B constructor called\n";}
    int c;
    virtual void foo()
    {
        cout<<"B::foo()\n";
    }
    virtual void bar()
    {
        cout<<"B::bar\n";
    }
    ~B(){}
};


int main()
{
    A x;
    B y;
    A *p = &x;
    cout<<p<<","<<&p->a<<","<<&p->b<<","<<&p->i<<endl;
    p->foo();
    p->bar();
    p = &y;
    cout<<p<<","<<&p->a<<","<<&p->b<<","<<&p->i<<","<<&((B*)p)->c<<endl;
    p->foo();
    p->bar();
}
