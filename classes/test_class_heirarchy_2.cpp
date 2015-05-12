#include<iostream>
using namespace std;

class A {
public:
    uint64_t i;
};

class B: virtual public A {
public:
    uint64_t j;
};

class C: virtual public A {
public:
    uint64_t k;
};

/*
 * Object layout in C++ is such that memory is allocated for each object of
 * the base classes and then the members of derived class.
 * But when deriving using virtual keyword, each object has an entry in the
 * vtable to point to the parent class's object
 * Here class D object layout is :
 * 
 * Class D:
 *  vtable (contains virtual function addrs & offset of class A,B,C instances)
 *  Class B
 *      vtable (contains virtual function addrs & offset of class A instance)
 *      members of class B
 *  Class C
 *      vtable (contains virtual function addrs & offset of class A instance)
 *      members of class C
 *  Class A
 *      members of class A
 *  members of Class D
 *
 * So class D has only one instance of class A
 */
class D:virtual public B, C {
public:
    uint64_t l;
};

int main()
{
    cout<<sizeof(A)<<","<<sizeof(B)<<","<<sizeof(C)<<","<<sizeof(D)<<endl;
}
