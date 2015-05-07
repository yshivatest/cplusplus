#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n*2];
    int c[n*3];
    a[n-1] = 1;
    cout<<a[n-1]<<endl;
    b[n*2-1] = 1;
    cout<<b[n-1]<<endl;
}
