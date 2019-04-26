#include<bits/stdc++.h>
using namespace std;
int knapsack(int profit[],int wt[],int w,int n)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]>w)
        return knapsack(profit,wt,w,n-1);
    else
        return max(knapsack(profit,wt,w,n-1),profit[n-1]+knapsack(profit,wt,w-wt[n-1],n-1));
}
int main()
{
    int profit[] = {3,6,10,5,18,15,7};
    int wt[] = {1,1,2,3,4,5,7};
    int  w = 50;
    int n = sizeof(wt)/sizeof(wt[0]);
    int x;
    x=knapsack(profit,wt,w,n);
    cout<<x;
    return 0;
}
