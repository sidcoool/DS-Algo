#include <bits/stdc++.h>
using namespace std;
int firstFit(int weight[], int n, int c)
{
    int res = 0;
    int bin_rem[n];
    for (int i=0; i<n; i++)
    {
        int j;
        for (j=0; j<res; j++)
        {
            if (bin_rem[j] >= weight[i])
            {
                bin_rem[j] = bin_rem[j] - weight[i];
                break;
            }
        }

        if (j==res)
        {
            bin_rem[res] = c - weight[i];
            res++;
        }
    }
    return res;
}
bool comparison(int x,int y)
{
    return x>=y;
}
int firstFitDec(int weight[], int n, int c)
{
	sort(weight, weight+n,comparison);
	return firstFit(weight, n, c);
}
int main()
{
	int weight[] = {2, 5, 4, 7, 1, 3, 8};
	int c = 10;
	int n = sizeof(weight) / sizeof(weight[0]);
	cout << "Number of bins required in First Fit "
		<< "Decreasing : " << firstFitDec(weight, n, c);
	return 0;
}
