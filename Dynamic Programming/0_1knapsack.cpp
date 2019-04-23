#include <iostream>
using namespace std;
int main() {
    int p[5] = {0,1,2,5,6}; //profits
    int w[5] = {0,2,3,4,5}; //weights

    int capacity = 8; 

    int mat[5][9] = {0};

    for(int i=1; i<=4; i++) //increasing weights indexes
    {
        for(int j=1; j<=8; j++) //capacities of knapsacks in increasing order  
        {
            if(w[i] > j)
            mat[i][j] = mat[i-1][j];
            else
            mat[i][j] = max(mat[i-1][j],mat[i-1][j-w[i]] + p[i]);
        }
    }
    cout<<mat[4][8];
    return 0;
}
