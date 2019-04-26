#include<bits/stdc++.h>
using namespace std;
int bin(int weight[],int c,int n)
{
    int count=0,rem=c;
    for(int i=0;i<n;i++)
    {
       if (weight[i] > rem)
       {
          count++;
          rem = c - weight[i];
       }
       else
         rem -= weight[i];
    }
    return count;
}
int main()
{
    int weight[] = {2, 5, 4, 7, 1, 3, 8};
    int c=10;
    int n=sizeof(weight)/sizeof(weight[0]);
    cout<<bin(weight,c,n);
    return 0;
}
