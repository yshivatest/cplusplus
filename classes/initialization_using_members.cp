#include<iostream>
#include<string>
using namespace std;

class Foo {
public:
    int a;
    string s;
};

class Bar {
public:
    int a;
    string s;
    Bar(int x) : a{x} {}
};

int main()
{
    Foo x {1, "siva"};
    Bar y {1, "siva"};// compile error as Bar has a constructor (implying that having a constructor disallows member-wise initialization
}
