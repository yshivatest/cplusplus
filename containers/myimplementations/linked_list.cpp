#include<iostream>
using namespace std;

template<typename data>
class LinkedList {
    template<typename Ndata>
    struct Node {
        public:
        Ndata x;
        Node<Ndata> *next;
    };
    Node<data> *head;
public:
    LinkedList()
    {
        cout<<"LinkedList constructor called\n";
        head = nullptr;
    }
    ~LinkedList()
    {
        cout<<"LinkedList destructor called\n";
        //delete all the elements in the list and point head to NULL
        while(head) {
            auto x = head;
            head = x->next;
            delete x;
        }
    }
    void insert(data x)
    {
        Node<data> *temp = new Node<data>{};
        temp->x = x;
        temp->next = nullptr;
        if (!head) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    template<typename xdata> friend ostream& operator<<(std::ostream& out, const LinkedList<xdata>& ll);
};
template<typename data>
ostream& operator<<(std::ostream& out, const LinkedList<data>& ll)
{
    auto temp = ll.head;
    while(temp) {
        out<<temp->x<<",";
        temp = temp->next;
    }
    return out;
}

int main()
{
    LinkedList<int> x;
    x.insert(1);
    x.insert(2);
    cout<<x<<endl;
}
