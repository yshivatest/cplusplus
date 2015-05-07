#include<iostream>
using namespace std;

class Foo {
public:
    void bar() { cout<<"Foo:bar\n";}
};

int main()
{
    Foo x;
    x.bar();
    // const objects can call only const member functions
    const Foo y;
    y.bar();
}
