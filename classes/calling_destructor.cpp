#include<iostream>
using namespace std;

// We can a destructor explicitly
// But the destructor is called again when the object goes out of scope
class A {
public:
    A(){}
    ~A(){cout<<"Destructor called\n";}
};

int main()
{
    A x;
    x.~A();
    cout<<"destructor should have been called by now\n";
}
