#include<iostream>
#include<memory>
using namespace std;

class Test {
public:
    Test() { cout<<"constructor called\n"; }
    ~Test() { cout<<"destructor called\n"; }
};

void foo()
{
    unique_ptr<Test> ptr {new Test};
    cout<<"foo running\n";
}

int main()
{
    foo();
    cout<<"Done with foo\n";
}
