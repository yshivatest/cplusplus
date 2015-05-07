#include<iostream>
#include<map>
using namespace std;

using map_char_int = map<char, int>;
using map_value = map<char,int>::value_type;
int main()
{
    map_char_int x;
    for(unsigned int i = 97; i < 123; i++) {
        auto j = x.insert(std::pair<char,int>((char)i, i));
        if(!j.second)
            cout<<"failed to insert "<<(char)i;
    }
    for(auto& i:x)
        cout<<"("<<i.first<<","<<i.second<<"),";
    cout<<endl;
}
