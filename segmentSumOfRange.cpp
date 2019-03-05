#include <iostream>
using namespace std;

int arr[6] = {1,2,3,4,5,6};
int T[13] = {};

void Insert(int start, int end, int id){
	if(start == end){
		T[id] = arr[start];
		return;
	}

	int mid = (start + end)/2;

	Insert(start, mid, (id*2)+1);
	Insert(mid+1, end, (id*2)+2);

	T[id] = T[(id*2)+1] + T[(id*2)+2];
}

void Update(int start, int end, int in, int id, int val){
	if(start == end){
		arr[id] = val;
		T[in] = arr[start];
		return;
	}

	int mid = (start + end)/2;
	if(start<=id && mid>=id)
		Update(start, mid, (in*2)+1, id, val);
	else
		Update(mid+1, end, (in*2)+2, id, val);

	T[in] = T[(in*2)+1] + T[(in*2)+2];
}

int SumofRange(int start, int end, int l, int r, int in){
	if(start >= l && end <= r){
		return T[in];
	}

	if(start>r || end<l)
		return 0;

	int mid = (start+end)/2;
	return (SumofRange(start, mid, l, r, (in*2)+1) + SumofRange(mid+1, end, l, r, (in*2)+2));

}

int main(){
	Insert(0,5,0);
	for (int i = 0; i < 13; ++i)
	{
		cout<<T[i]<<" ";
	}

    cout<<endl;

	Update(0,5,0,3,8);
	for (int i = 0; i < 13; ++i)
	{
		cout<<T[i]<<" ";
	}

		// int sum = SumofRange(0,5,2,4,0);
		// cout<<sum;

	return 0;
}