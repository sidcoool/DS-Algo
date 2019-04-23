#include <iostream>
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

int LCA(Node *root, int a, int b)
{
	while(1)
	{
		if(root->data < a && root->data < b)
		root = root->right;
	else if(root->data > a && root->data > b)
		root = root->left;
	else
		return root->data;
	}
}

int main()
{
   Node *root = new Node(10);
   root->left = new Node(8);
   root->right = new Node(14);
   root->left->left = new Node(3);
   root->right->left = new Node(11);
   root->right->right = new Node(15);

   int ancestor = LCA(root,11,15);
   cout<<ancestor<<endl;
   return 0;
 }  