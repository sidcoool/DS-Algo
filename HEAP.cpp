#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> Insert(vector<int>HeapArr, int num)
{
	int i;
    HeapArr.push_back(num);
    i = HeapArr.size() - 1;
    while(i)
    {
    	if(HeapArr[(i-1)/2] < HeapArr[i])
        swap(HeapArr[(i-1)/2],HeapArr[i]);
        i = (i-1)/2;
    } 
    return HeapArr;
}


vector <int> Delete(vector<int>HeapArr, int num)
{
    int i,pos,max1;
    i = HeapArr.size() - 1;
    for(pos=0;pos<=i;pos++)
    {
        if(HeapArr[pos]==num)
            {
                HeapArr[pos] = HeapArr[i];
                HeapArr.pop_back();
                break;
            }
    }
       i -= 1;
    while(pos<=(i-1)/2)
    {
       max1 = max(HeapArr[(pos*2)+1],HeapArr[(pos*2)+2]);
    if(max1==HeapArr[(pos*2)+1] && max1>HeapArr[pos])
        {
            swap(HeapArr[pos],HeapArr[(pos*2)+1]);
            pos = (pos*2)+1;
        }
    else if(max1==HeapArr[(pos*2)+2] && max1>HeapArr[pos])
         {
            swap(HeapArr[pos],HeapArr[(pos*2)+2]);
            pos = (pos*2)+2;
        }
    } 
    return HeapArr;
}


int main()
{
	int i;
	vector <int> HeapArr;
	HeapArr = Insert(HeapArr,12);
	HeapArr = Insert(HeapArr,6);
	HeapArr = Insert(HeapArr,9);
	HeapArr = Insert(HeapArr,17);
	HeapArr = Insert(HeapArr,11);
	HeapArr = Insert(HeapArr,13);

    HeapArr = Delete(HeapArr,17);

	for (i =0; i < HeapArr.size(); ++i) 
        cout <<HeapArr[i]<< " "; 
    cout<<endl;
    return 0;
}