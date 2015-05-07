#include<iostream>
#include<array>
using namespace std;

using sarray = array<int, 5>;
int main()
{
    array<int, 5> x;
    sarray y;
    cout<<x.size()<<","<<y.size()<<endl;
    for (auto& i:x)
        cout<<&i<<",";
    cout<<endl;
}
