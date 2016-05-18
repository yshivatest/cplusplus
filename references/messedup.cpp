#include<iostream>
using namespace std;

class Widget {
};

class MessedUp {
    public:
        template<typename T>
        void doWork(const T& x) { cout<<__func__<<" const lvalue ref"<<endl;}
        template<typename T>
        void doWork(T&& x) { cout<<__func__<<" rvalue ref"<<endl; }
};

int main() {
    Widget w;
    const Widget cw;
    MessedUp nmu;
    nmu.doWork(w);
    nmu.doWork(std::move(w));

    nmu.doWork(cw);
    nmu.doWork(std::move(cw));
}
