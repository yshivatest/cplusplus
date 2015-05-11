#include<iostream>
#include<stdexcept>
using namespace std;

template<typename QData>
class Queue {
    struct Node {
        QData val;
        Node *next;
        Node(QData d, Node *n=nullptr): val{d}, next{n} {}
    };
    Node *front;
    Node *tail;
public:
    Queue()
    {
        front = tail = nullptr;
    }
    ~Queue()
    {
        while(tail) {
            auto x = tail;
            tail = tail->next;
            delete x;
        }
    }
    void enqueue(QData d)
    {
        auto temp = new Node(d);
        if (!tail) {
            front = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    QData dequeue()
    {
        if (!front)
            throw out_of_range("Queue::dequeue no elements");
        auto temp = front->val;
        front = front->next;
        if (!front)
            tail = front;
        return temp;
    }
    template<typename Tdata> friend ostream& operator <<(ostream& out, const Queue<Tdata>& q);
};
template<typename Tdata> ostream& operator <<(ostream& out, const Queue<Tdata>& q)
{
    auto x = q.front;
    while(x) {
        out<<x->val<<",";
        x = x->next;
    }
    out<<endl;
    return out;
}
int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(3);
    cout<<q;
    q.dequeue();
    q.dequeue();
    cout<<q;
    q.dequeue();
}
