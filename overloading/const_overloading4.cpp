#include<iostream>
using namespace std;

class Foo {
    public:
        void bar() const { cout<<__func__<<" const "<<endl; }
        void bar() { cout<<__func__<<" non const "<<endl; }
};

int main() {
    Foo x;
    const Foo y;

    x.bar();
    y.bar();
}
