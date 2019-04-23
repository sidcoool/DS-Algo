#include <iostream>
using namespace std;

void merge(int a[],int l[],int r[],int nL,int nR)
{
  
  int i=0,j=0,k=0;
  while(i<nL && j<nR)
  {
    if(l[i]<=r[j])
      a[k++] = l[i++];
    else
      a[k++] = r[j++];
  }

  while(i<nL) a[k++] = l[i++];
  while(j<nR) a[k++] = r[j++];
}


void mergeSort(int a[],int N)
{
  int i,mid;
  if(N<2)
    return;

  mid = N/2;
  

  int l[mid];
  int r[N-mid];

  for(i=0;i<mid;i++)
    l[i] = a[i];

  for(i=mid;i<N;i++)
    r[i-mid] = a[i];

  mergeSort(l,mid);
  mergeSort(r,N-mid);
  merge(a,l,r,mid,N-mid);
}

int main()
{
  int a[11] = {5,4,2,8,1,0,9,3,5,43,21};
  int N = sizeof(a);
  N = N/4;

mergeSort(a,N);

for(int i=0;i<N;i++)
   cout<<a[i]<<" ";

 cout<<endl;
  return 0;
}