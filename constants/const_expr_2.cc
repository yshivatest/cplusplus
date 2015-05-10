#include<iostream>
using namespace std;

constexpr float square(float x)
{
    return x * x;
}
int main()
{
    constexpr float x = square(2.3);
}
