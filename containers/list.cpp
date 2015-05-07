#include<iostream>
#include<list>
using namespace std;

using int_list = list<int>;
int main()
{
    int_list x;
    cout<<"Enter 5 elements\n";
    for (int i = 0; i < 5; i++) {
        int j;
        cin>>j;
        x.push_front(j);
    }
    for(auto& i:x)
        cout<<i<<",";
    cout<<endl;
}
