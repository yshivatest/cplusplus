#include <iostream>
using namespace std;

int main()
{
    int x[] = {1,2,3,4};
    for (auto a: x)
        cout<<a<<" ";
    cout<<endl;
    for (auto& a: x)
        cout<<a<<" ";
    cout<<endl;
}

