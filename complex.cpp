#include<iostream>
#include "complex.h"
using namespace std;

void Complex::add(const Complex& c2)
{
    real += c2.real;
    imag += c2.imag;
}

int main()
{
    Complex c1(1,2), c2(3,4);
    //cout<<c1<<endl;
    //cout<<c2<<endl;
    c1.add(c2);
    //cout<<c1<<endl;
}
