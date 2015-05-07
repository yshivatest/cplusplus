#include<iostream>
using namespace std;

namespace Test {
    int i = 1;
}

int i = 2;

int main()
{
    cout<<"namespace i = "<<Test::i<<endl;
    cout<<"global i = "<<i<<endl;
}
