#include<iostream>
using namespace std;

void foo(const int x) {
    cout<<__func__<<" const"<<endl;
}

void foo(int x) {
    cout<<__func__<<" no const"<<endl;
}

int main() {
    int x = 1;
    const int y = 2;
    foo(x);
    foo(y);
}
