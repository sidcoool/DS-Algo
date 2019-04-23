#include <iostream>
#include <list>
using namespace std;
#define M 4

struct Node
{
	list <int> L;
	Node *pointers[4];

	Node()
	{
		for(int i=0;i<4;i++)
			pointers[i] = NULL;
	}

};

Node *Split(int num, Node *root)
{
	
}

Node *BtreeInsert(int num, Node *root)
{
    int i;

	if(root->L.empty())
		root->L.push_back(num);
    else if(root->L.size()<3)   
	{
		list<int>::iterator it = root->L.begin();
		for(it=root->L.begin(); it!=root->L.end(); ++it)
		{
			if(num < *it)
            {root->L.insert(it,num);
            break;}
		}
		if(it==root->L.end())
			root->L.push_back(num);
	}

	else
	{
		Split(num,root);
	}

	return root;
}
 
 int main()
 {
     Node *root = new Node();
     //cout<<"end!";
     int arr[9] = {1,2,4,3,9,10,7,6,5};
     
     for(int i=0;i<9;i++)
        root = BtreeInsert(arr[i],root);
        	
       	list<int>::iterator it = root->L.begin();;
		while(it != root->L.end())
			{
				cout<<*it<<" ";
				it++;
			}
			

        return 0;
 }