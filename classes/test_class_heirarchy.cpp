#include<iostream>
using namespace std;

class A {
public:
    uint64_t i;
};

class B: public A {
public:
    uint64_t j;
};

class C: public A {
public:
    uint64_t k;
};

/*
 * Object layout in C++ is such that memory is allocated for each object of
 * the base classes and then the members of derived class.
 * Here class D object layout is :
 * 
 * Class D:
 *  Class B
 *      Class A
 *      members of class B
 *  Class C
 *      Class A
 *      members of class C
 *  members of Class D
 *
 * So class D has two instances of class A
 */
class D:public B, C {
public:
    uint64_t l;
};

int main()
{
    cout<<sizeof(A)<<","<<sizeof(B)<<","<<sizeof(C)<<","<<sizeof(D)<<endl;
}
