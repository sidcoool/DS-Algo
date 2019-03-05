#include <iostream>
#include <queue>
#include <stack>
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

void Inorder(Node *root)
{
	stack <Node*> s;

	while(root!=NULL || !s.empty())
	{
		while(root!=NULL)
		{
			s.push(root);
			root = root->left;
		}

		root = s.top();
		s.pop();

		cout<<root->data<<" ";

		root = root->right;
	}
}

void Preorder(Node *root)
{
	stack <Node*> s;
	s.push(root);

	while(!s.empty())
	{
    root = s.top();
    cout<<root->data<<" ";
    s.pop();

		if(root->right!=NULL)
			s.push(root->right);

		if(root->left!=NULL)
			s.push(root->left);
        
	}
}

void Postorder(Node *root)
{
	stack <Node*> s1;
	stack <int> s2;
    s1.push(root);

    while(!s1.empty())
    {
    	root = s1.top();
    	s2.push(root->data);
    	s1.pop();
    	
    	if(root->left!=NULL)
			s1.push(root->left);

		if(root->right!=NULL)
			s1.push(root->right);
    }

    while(!s2.empty())
    {
    	cout<<s2.top()<<" ";
    	s2.pop();
    }
}

void Levelorder(Node *root)
{
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
    	root = q.front();
    	cout<<root->data<<" ";
    	q.pop();

    	if(root->left!=NULL)
    		q.push(root->left);
    	
    	if(root->right!=NULL)
    		q.push(root->right); 
    }
}


int main()
{
   Node *root = new Node(10);
   root->left = new Node(20);
   root->right = new Node(30);
   root->left->left = new Node(40);
   root->right->left = new Node(50);
   root->right->right = new Node(60);

   Inorder(root);
   cout<<endl<<endl;
   
    Preorder(root);
   cout<<endl<<endl;

    Postorder(root);
   cout<<endl<<endl;

   Levelorder(root);
   cout<<endl<<endl;
   return 0;
}