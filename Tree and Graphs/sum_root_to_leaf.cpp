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

bool checkSum(Node *root, int sum, int passed)
{
	if(!root)
		return false;

	int key = root->data;
	if(!root->right && !root->left)
	{
		if(key == passed)
			return true;
		else 
			return false;
	}

	return (checkSum(root->left,sum,passed-key) || checkSum(root->right,sum,passed-key));

	return false;
}

int main()
{
   Node *root = new Node(10);
   root->left = new Node(8);
   root->right = new Node(14);
   root->left->left = new Node(3);
   root->right->left = new Node(11);
   root->right->right = new Node(15);

   if(checkSum(root,38,38))
   	cout<<"Exists ! "<<endl;
   else
   	cout<<"Does not Exists !"<<endl;

   return 0;
}