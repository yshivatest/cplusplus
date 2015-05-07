#include<iostream>
#include<deque>
using namespace std;

using int_deque = deque<int>;
int main()
{
    int_deque x;
    cout<<"Enter 5 elements for queue\n";
    for(int i = 0; i < 5; i++) {
        int j;
        cin>>j;
        x.push_back(j);
    }

    for (auto& i:x)
        cout<<i<<",";
    cout<<endl;
    while(!x.empty()) {
        cout<<x.front()<<",";
        x.pop_front();
    }
    cout<<endl;
    cout<<"max size for dequeu "<<x.max_size()<<endl;
}
