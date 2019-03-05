#include <iostream>
#include <limits.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool BSTcheck(Node *root, int min, int max)
{
	if(root==NULL)
		return true;
	int key = root->data;
	 if(key<min || key>max)
	 	return false;
	 return (BSTcheck(root->left,min,key) && BSTcheck(root->right,key,max));
}

int main()
{
   Node *root = new Node(10);
   root->left = new Node(8);
   root->right = new Node(14);
   root->left->left = new Node(3);
   root->right->left = new Node(11);
   root->right->right = new Node(15);

   if(BSTcheck(root,INT_MIN,INT_MAX))
   	cout<<"Is a BST"<<endl;
   else
   	cout<<"Not a BST"<<endl;

   return 0;
}