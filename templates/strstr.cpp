#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename P>
vector<int> siva_strstr(string T, const P& x)
{
    vector<int> ret;
    for (int i = 0; i < T.length(); i++) {
        if (x(T, i))
            ret.push_back(i);
    }
    return ret;
}

int main()
{
    string T, P;
    cout<<"Enter the string\n";
    cin >> T;
    cout<<"Enter the pattern\n";
    cin >> P;
    vector<int> matches = siva_strstr(T, [&P](string x, int i){if (x.substr(i, P.length()) == P) return true;});
    for (auto& x: matches)
        cout<<x<<",";
    cout<<endl;
}
