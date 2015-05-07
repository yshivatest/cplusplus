#include<iostream>
using namespace std;

template<typename Array>
void siva_swap(Array& x, Array& y)
{
    Array temp = x;
    x = y;
    y = temp;
}

template<typename Array, typename Len, typename P>
void insertion_sort(Array& x, const Len& l, const P& pred)
{
    for(Len i = 0; i < l; i++) {
        for (Len j = i - 1; j >= 0; j--) {
            if (pred(x[j], x[j+1])) {
                siva_swap(x[j], x[j+1]);
            }
        }
    }
}

template<typename Array, typename Len>
void print_array(const Array& x, const Len& l)
{
    for (Len i = 0; i < l; i++)
        cout<<x[i]<<",";
    cout<<endl;
}

template<typename inttype>
bool pred_for_sort(const inttype& a, const inttype& b)
{
    if (a > b)
        return true;
    return false;
}

int main()
{
    int x[]={9,8,7,6,5,4,3,2,1};
    insertion_sort(x, 9, pred_for_sort<int>);
    print_array(x, 9);
}
