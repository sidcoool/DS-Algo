#include<bits/stdc++.h>
using namespace std;
struct item
{
    int value,weight;
};
bool comparison(item a,item b)
{
    double x=(double)a.value/a.weight;
    double y=(double)b.value/b.weight;
    return x>y;
}
double fractional(item arr[],int w,int n)
{
    sort(arr,arr+n,comparison);
    int curweight=0;
    double value=0.0;
    for(int i=0;i<n;i++)
    {
        if(curweight + arr[i].weight <= w)
        {
            curweight +=arr[i].weight;
            value +=arr[i].value;
        }
        else
        {
            int remain=w-curweight;
            value +=arr[i].value*((double)remain/arr[i].weight);
            break;
        }
    }
    return value;
}
int main()
{
    int w = 50;
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<fractional(arr,w,n);

    return 0;
}
