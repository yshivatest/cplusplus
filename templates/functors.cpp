#include<iostream>
#include<list>
using namespace std;

template<typename T, typename P>
int foo(const T& x, const P& pred)
{
    int num = 0;
    for(auto& i:x)
        if (pred(i))
            num++;
    return num;
}

int main()
{
    list<int> x {1,2,3,4,5,6};
    for (auto& i:x)
        cout<<i<<",";
    cout<<endl;
    int val;
    cin>>val;
    cout<<foo(x, [&val](int a) { return a < val;})<<endl;
}
