#include<iostream>
#include<stdexcept>
using namespace std;

template<typename Sdata>
class Stack {
    template<typename Ndata>
    struct Node {
        Ndata x;
        Node<Ndata> *next;
    };
    Node<Sdata> *top;
public:
    Stack()
    {
        top = nullptr;
    }
    ~Stack()
    {
        while(top) {
            auto x = top;
            top = top->next;
            delete x;
        }
    }
    void push(Sdata x)
    {
        auto temp = new Node<Sdata>();
        temp->x = x;
        temp->next = top;
        top = temp;
    }
    Sdata pop()
    {
        if (top) {
            auto temp = top->x;
            top = top->next;
            return temp;
        } else {
            throw out_of_range("Stack::pop");
        }
    }
    template<typename Odata> friend ostream& operator<<(ostream& out, const Stack<Odata>& st);
};
template<typename Sdata>
ostream& operator<<(ostream& out, const Stack<Sdata>& st)
{
    auto temp = st.top;
    while(temp) {
        out<<temp->x<<",";
        temp = temp->next;
    }
    out<<endl;
    return out;
}

int main()
{
    Stack<int> x;
    x.push(1);
    x.push(2);
    cout<<x;
    x.pop();
    x.pop();
    cout<<x;
}
