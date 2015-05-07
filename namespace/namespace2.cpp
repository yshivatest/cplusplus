#include<iostream>
using namespace std;

namespace Foo {
    namespace Bar {
        int x = 4;
    }
    using namespace Bar;
}

int main()
{
    using namespace Foo;
    cout<<x<<endl;
}
