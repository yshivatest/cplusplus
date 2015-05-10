#ifdef __cplusplus
#include<iostream>
using namespace std;
#else
#include<stdio.h>
#endif

const int x = 5;
const int y = x;
int main()
{
#ifdef __cplusplus
    cout<<x<<","<<y<<endl;
#else
    printf("%d,%d\n",x,y);
#endif
}
