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
    static void siva()
    {
        cout<<"A::siva\n";
    }
    virtual ~A(){}
};
int A::i = 0;

class C {
public:
    C() { cout<<"C constructor called\n"; }
    int x;
    int y;
    virtual void cfoo()
    {
        cout<<"C::cfoo\n";
    }
    virtual void cbar()
    {
        cout<<"C::cbar\n";
    }
    virtual ~C() {}
};

class B : public A {
public:
    B() {cout<<"B constructor called\n";}
    int c;
    virtual void foo() override
    {
        cout<<"B::foo()\n";
    }
    virtual void bar()
    {
        cout<<"B::bar\n";
    }
    static void siva()
    {
        cout<<"B::siva\n";
    }
    virtual ~B(){}
    static int main()
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
        p->siva();
    }
};

/*
 * Class D has two vtables one for A and another for C
 * Class D layout is like this
 *  Class A layout (including vtable)
 *  Class C layout (including vtable)
 *  Class D members (including vtable)
 */
class D: public A, C {
public:
    virtual void foo() override
    {
        cout<<"D::foo()\n";
    }
    virtual void bar()
    {
        cout<<"D::bar\n";
    }
    virtual void cfoo()
    {
        cout<<"D::cfoo\n";
    }
    virtual void cbar()
    {
        cout<<"D::cbar\n";
    }
    virtual ~D() {}
    static int main()
    {
        D x;
        A *ap = &x;
        ap->foo();
        ap->bar();
        C *cp = &x;
        cp->cfoo();
        cp->cbar();
        cout<<"ap="<<ap<<",cp="<<cp<<",sizeof(A)=0x"<<hex<<sizeof(A)<<endl;
    }
};

int main()
{
    //B::main();
    D::main();
}
