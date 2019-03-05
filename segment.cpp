#include <iostream>
#define INT_MAX 999999
using namespace std;

void Insert(int arr[],int T[],int in,int start,int end)
{
    if(start == end)
    {
        T[in] = arr[start];
        return;
    }

    int mid = (start+end)/2;
    Insert(arr,T,(in*2)+1,start,mid);
    Insert(arr,T,(in*2)+2,mid+1,end);
    T[in] = min(T[(in*2)+1],T[(in*2)+2]);
}

void Update(int arr[], int T[], int in, int start, int end, int id, int val)
{
    if(start == end)
    {
        arr[id] = val;
        T[in] = arr[id];
        return;
    }

    int mid = (start+end)/2;

    if(start<=id && mid>=id)
    Update(arr,T,(in*2)+1,start,mid,id,val);
    else
    Update(arr,T,(in*2)+2,mid+1,end,id,val);
    T[in] = min(T[(in*2)+1],T[(in*2)+2]);
}

int RangeMin(int arr[], int T[], int in, int start, int end, int l, int r)
{
    if(start>=l && end<=r)
    {
        // cout<<"Loop 1"<<endl;
        return T[in];
    }

    else if(start>r || end<l)
    {
        // cout<<"Loop 2"<<endl;
        return INT_MAX;
    }
    
    int mid = (start+end)/2;
    return min(RangeMin(arr,T,(in*2)+1,start,mid,l,r) , RangeMin(arr,T,(in*2)+2,mid+1,end,l,r));
}

int main()
{
    int arr[] = {1,4,6,2,8,3,9,7};
    int arrSize = sizeof(arr)/4;
    int TSize = (arrSize*2) - 1;
    cout<<"";
    int T[TSize] = { };

    Insert(arr,T,0,0,arrSize);
    cout<<"Previos"<<endl;
    for(int i=0; i<TSize; i++)
    {
        cout<<T[i]<<" ";
    }

    cout<<endl;

    /*Update(arr,T,0,0,3,2,4);
    cout<<endl<<"Updated"<<endl;
    for(int i=0; i<7; i++)
    {
        cout<<T[i]<<" ";
    }*/

    // cout<<endl;

    int min = RangeMin(arr,T,0,0,arrSize,2,7);
    cout<<endl<<"Min value: "<<min<<endl;

    return 0;
}
