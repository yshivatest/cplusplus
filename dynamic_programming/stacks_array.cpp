#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int>> vvint;

// state 1 - normal state
// state 2 - only two possible paths
// state 3 - same as state 1 (this state is not needed)
int find_combinations(vvint& vec1, vvint& vec2, int a_size, int b_size, int state)
{
    cout<<"caulculating combinations for "<<a_size<<","<<b_size<<","<<state<<endl;
    if (a_size < 0 || b_size < 0)
        return 0;
    if (1 == state && vec1[a_size][b_size] != -1)
        return vec1[a_size][b_size];
    else if (1 == state && vec2[a_size][b_size] != -1)
        return vec2[a_size][b_size];
    if (1==state) {
        vec1[a_size][b_size] = find_combinations(vec1, vec2, a_size, b_size-1, 1) +
                                find_combinations(vec1, vec2, a_size-1, b_size, 1) +
                                find_combinations(vec1, vec2, a_size-1, b_size + 1, 2);
        return vec1[a_size][b_size];
    } else {
        vec2[a_size][b_size] = find_combinations(vec1, vec2, a_size-1 , b_size+1, 2) +
                                find_combinations(vec1, vec2, a_size-1, b_size, 1);
        return vec2[a_size][b_size];
    }
}

int main()
{
    int n;
    cout<<"Enter the initial number of elements in stack A\n";
    cin>>n;
    vector<vector<int>> vec1(n+1, vector<int>(n+1));
    vector<vector<int>> vec2(n+1, vector<int>(n+1));
    cout<<vec1.size()<<","<<vec2.size();
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec1[i].size(); j++) {
            vec1[i][j] = -1;
            vec2[i][j] = -1;
        }
    }
    vec1[1][0] = 1;
    vec1[0][1] = 1;
    vec2[1][0] = 1;
    vec2[0][1] = 0;
    cout<<"Total number of combinations = "<<find_combinations(vec1, vec2, n, 0, 1)<<endl;
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec1[i].size(); j++) {
            cout<<"("<<vec1[i][j]<<","<<vec2[i][j]<<"),";
        }
        cout<<endl;
    }
    cout<<endl;
}
