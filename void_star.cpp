#include<iostream>
using namespace std;

int main()
{
    int ar[10];
    int *p = ar;
    void *vp = p;
    void *ap = p;
    // This is valid only in C(Probably gcc extension)
    cout<<vp-ap<<endl;
}
