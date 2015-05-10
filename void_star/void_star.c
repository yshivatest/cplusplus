#include<stdio.h>

int main()
{
    int ar[10];
    int *p = ar;
    void *vp = p;
    void *ap = p;
    printf("%d\n",vp-ap);
}
