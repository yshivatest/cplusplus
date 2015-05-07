#include<iostream>
using namespace std;

class Vector {
public:
    Vector(int sz) : sz(sz), elemt{new double[sz]} {}
    int size() {return sz;}
    double& operator[](int i) {return elemt[i];}
private:
    int sz;
    double *elemt;
};

void read_and_sum()
{
    Vector v(6);
    for(int i = 0; i < v.size(); i++)
        cin>>v[i];
    double sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum += v[i];
    cout<<"Sum = "<<sum<<endl;
}

int main()
{
    read_and_sum();
}
