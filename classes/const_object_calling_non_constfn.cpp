#include<iostream>
using namespace std;

class Foo {
public:
    int a, b;
    explicit Foo(int x, int y) : a{x}, b{y} {}
    void bar() { cout<<"Foo:bar\n";}
};

int main()
{
    Foo x(2,3);
    x.bar();
    // const objects can call only const member functions
    const Foo y(2,3);
    y.bar();
}
