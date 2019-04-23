#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	bool tleft;
	bool tright;

	Node(int data, bool tleft, bool tright)
	{
		this->data = data;
		this->tleft = tleft;
		this->tright = tright;
		left = right = NULL;
	}
};

Node* Insert(Node* root, int data)
{
    Node *ptr = root;
  	Node *par = NULL;
	while(ptr!=NULL)
	{
		par = ptr;
		if(data < ptr->data)
		{
			if(ptr->tleft==false)
				ptr = ptr->left;
			else
				break;
		}

		if(data > ptr->data)
		{
			if(ptr->tright==false)
				ptr = ptr->right;
			else
				break;
		}
	}

	Node* newNode = new Node(data,true,true);

    if (par == NULL) 
        root = newNode; 
	else if(data < par->data)
	{
		newNode->left = par->left;
		newNode->right = par;
		par->tleft = false;
		par->left = newNode;
	}
	else
		if(data > par->data)
		{
			newNode->left = par;
		    newNode->right = par->right;
		    par->tright = false;
			par->right = newNode;		
		}

  
    return root;
}

Node* Successor(Node* root)
{
	if(root->tright==true)
		{
			return root->right;
		}
	root = root->right;
	while(root->tleft!=true)
	{
		root = root->left;
	}
	return root;
}

void Traverse(Node* root)
{
	while(root->left!=NULL)
		root = root->left;

	while(root != NULL)
	{
		cout<<root->data<<" ";
		root = Successor(root);
	}
}

int main()
{
	Node *root = NULL;
  root = Insert(root, 10); 
  root = Insert(root, 8); 
  root = Insert(root, 12); 
  root = Insert(root, 4); 
  root = Insert(root, 9); 
  root = Insert(root, 11);
  root = Insert(root, 14);
  
  Traverse(root);
  return 0;
}
