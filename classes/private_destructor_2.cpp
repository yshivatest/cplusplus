#include<iostream>
using namespace std;

class Foo {
public:
    Foo(){}
    void destroy() 
    {
        //~Foo() - this gives compile error
        this->~Foo();
        // delete this; - this also works
    }
private:
    ~Foo(){}
};
int main()
{
    Foo *x = new Foo;
    //x->~Foo(); compile error as ~Foo() is private
    x->destroy();
}
