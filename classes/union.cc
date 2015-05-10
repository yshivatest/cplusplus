#include<iostream>
using namespace std;

enum class Type {str, num};

union Value {
    public:
    char *s;
    int i;
    ostream& operator<<(ostream& out) { out<<i<<endl;}
};

struct Entry {
    Value v;
    Type t;
};

void print_entry(const Entry& x)
{
    if (x.t == Type::str)
        cout<<x.v.s<<endl;
    else
        cout<<x.v.i<<endl;
}
int main()
{
    Value str; str.s = "siva";
    Value num; num.i = 1;
    Entry x = {num, Type::num};
    Entry y = {str, Type::str};
    print_entry(x);
    print_entry(y);
}
