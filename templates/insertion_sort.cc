#include<iostream>
using namespace std;

void insertion_sort(int *x, int length)
{
    for (int i = 1; i < length; i++) {
        //keep swapping x[i] until you find the right spot
        for (int j = i - 1; j >=0; j--)
            if (x[j] > x[j+1]) {
                //swap x[j+1], x[j]
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
    }
}

void print_array(int *x, int length)
{
    for (int i = 0; i < length; i++)
        cout<<x[i]<<",";
    cout<<endl;
}
int main()
{
    int x[] = {9,8,7,6,5,4,3,2,1};
    insertion_sort(x, 9);
    print_array(x, 9);
}
