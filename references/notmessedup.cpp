#include<iostream>
using namespace std;

class Widget {
};

class NotMessedUp {
    public:
        void doWork(const Widget& x) { cout<<__func__<<" const lvalue ref"<<endl;}
        void doWork(Widget&& x) { cout<<__func__<<" rvalue ref"<<endl; }
};

int main() {
    Widget w;
    NotMessedUp nmu;
    nmu.doWork(w);
    nmu.doWork(std::move(w));
}
