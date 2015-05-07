#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> x {1,2,1,45};
    int number = count_if(x.begin(), x.end(), [&](int i) { return i == x[0];}); 
    cout<<number<<endl;
}
