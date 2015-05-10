#include<iostream>
#include<string>
using namespace std;

// Copy s1 into s2 and then modify s1.
// s2 is not modified. Which means s1 and s2 have different copies.
int main()
{
    string s1 = "siva";
    string s2 = s1;
    s1[1] = 'o';
    cout<<"s1="<<s1<<",s2="<<s2<<endl;
}
