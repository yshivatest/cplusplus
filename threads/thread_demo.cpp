#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void foo(int& x)
{
    cout<<"Executing foo()\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
}

void bar(int y)
{
    cout<<"Executing bar()\n";
}

int main()
{
    int x = 1;
    thread t1 {foo, ref(x)}, t2{bar, 2};
    t1.join();
    t2.join();
}
