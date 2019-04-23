#include <iostream>
using namespace std;

int main()
{
    int n = 5;  //number of matrices
    int p[n+1] = {2,3,4,5,6,7};
    int M[n+1][n+1] = {0};
    int i,temp,min;

    for(int d=1; d<=n-1; d++)
    {
        i = 1;
        for(int j = d+1; j<=n; j++)
        {
            min = 9999999;
            for(int k=i; k<j; k++)
            {
                temp = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp < min)
                {
                    min = temp;
                }
            }
            M[i][j] = min;
            i++;
        }
    }

    cout<<M[1][n];

    return 0;
}