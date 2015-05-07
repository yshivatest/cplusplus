#include<iostream>
#include<map>
using namespace std;

using multimap_char_int = multimap<char,int>;
int main()
{
    multimap_char_int x;
    for(unsigned int i = 97; i < 123; i++) {
        auto y = x.insert(std::pair<char,int>(i,i));
        //cout<<(*y).first<<endl;
    }

    for(auto& i:x)
        cout<<"("<<i.first<<","<<i.second<<"),";
    cout<<endl;
}
