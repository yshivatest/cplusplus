#include<iostream>
#include<string>
using namespace std;

string nameFromId(int id)
{
	return "siva";
}

class Person {
    string name;
    public:
        Person(const string& n) : name(n) {}
        Person(int id) :name(nameFromId(id)) {}
};
int main() {
    string jkr("J. K. Rowling");

    Person p1(jkr); //jkr is copied into name in Person constructor
    Person p2("John grisham"); //"John grisham" is copied into a temporary string
                                // object & that is copied into name
    Person p3(44245); // returned temporary string object from nameFromId() is
                        // moved into name
    Person p4(nameFromId(44245)); // returned temporary string object from nameFromId()
                                    // is copied into name
}
