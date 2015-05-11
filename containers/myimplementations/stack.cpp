#include<iostream>
#include<stdexcept>
using namespace std;

template<typename Data>
class Stack {
public:
    struct Node {
        Data x;
        Node *next;
        Node(Data d, Node *n=nullptr) : x{d}, next{n}
        {      
        }
    };
    Node *top;
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
    void push(Data x)
    {
        auto temp = new Node(x,top);
        top = temp;
    }

    Data pop()
    {
        if (!top)
            throw out_of_range("Stack::pop");
        auto x = top->x;
        top = top->next;
        return x;
    }
    template<typename Tdata> friend ostream& operator<<(ostream& out, const Stack<Tdata>& x);
};

template<typename Tdata>
ostream& operator<<(ostream& out, const Stack<Tdata>& x)
{
    auto temp = x.top;
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
    x.push(1); x.push(2);
    cout<<x;
    x.pop();x.pop();
    cout<<x;
}
