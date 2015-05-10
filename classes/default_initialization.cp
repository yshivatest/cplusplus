#include<iostream>
#include<string>
using namespace std;

class Foo {
public:
    int a;
    string s;
};
int main()
{
    Foo x {};
    cout<<x.a<<","<<x.s<<endl;
}
