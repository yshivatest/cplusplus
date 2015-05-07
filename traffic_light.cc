#include<iostream>
using namespace std;

enum class TrafficLight {
    red, green, yellow
};

// Prefix operator
TrafficLight& operator++(TrafficLight& t)
{
    switch(t) {
        case TrafficLight::red:
            t = TrafficLight::green;
            break;
        case TrafficLight::green:
            t = TrafficLight::yellow;
            break;
        case TrafficLight::yellow:
            t = TrafficLight::red;
            break;
    }
    return t;
}

int main()
{
    TrafficLight x = TrafficLight::red;
    ++x;
    if (x == TrafficLight::green)
        cout<<"Worked well\n";
}
