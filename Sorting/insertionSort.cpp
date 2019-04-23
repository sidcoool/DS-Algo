#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void insertionSort()
{
	int i,key,j;
	for(i=1;i<v.size();i++)
	{
		key = v[i];
		j=i-1;

		while(j>=0 && key<=v[j])
		{
			v[j+1]=v[j];
			j--;
		}

		v[j+1] = key;
	}
}

int main()
{
	int k;
for(k=7; k>0; k--)
{
	v.push_back(k);
}

v.push_back(13);
v.push_back(0);
v.push_back(5);

vector <int>:: iterator it = v.begin();
cout<<"Initial Array"<<endl;
while(it!=v.end())
	{
		cout<<*it<<" ";
		it++;
	} 
	cout<<endl<<endl;
	
    it = v.begin();
	insertionSort();

	cout<<"Sorted Array"<<endl;
	while(it!=v.end())
	{
		cout<<*it<<" ";
		it++;
	} 
	cout<<endl;

	return 0;
}