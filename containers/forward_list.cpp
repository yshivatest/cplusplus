#include<iostream>
#include<forward_list>
using namespace std;

using int_forward_list = forward_list<int>;
int main()
{
    int_forward_list x;
    cout<<"Enter 5 elements\n";
    for (int i = 0; i < 5; i++) {
        int j;
        cin>>j;
        x.push_front(j);
    }
    for (auto& i: x)
        cout<<&i<<",";
    cout<<endl;
}   
