#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* Newnode(int value)
{
	    Node *new_node = new Node();
		new_node->left = new_node->right = NULL;
		new_node->data = value;
		return new_node;
}


Node* createTree(Node *root, int value)
{
	if(root == NULL)
	{
		root = Newnode(value);
	}
	else
	{
		queue <Node*> q;
	    q.push(root);

	while(!q.empty())
	{
		Node *root= new Node();
		root = q.front();
		q.pop();

		if(root->left == NULL)
		{
			root->left = Newnode(value);
			break;
		}
		else
			q.push(root->left);
        
        if(root->right == NULL)
		{
			root->right = Newnode(value);
			break;
		}
		else
			q.push(root->right);

	}
	
	}
	return root;
}


void Traverse(Node* root)
{
	if(root == NULL)
	 return;
    else
    {
    	Traverse(root->left);
    	cout<<root->data<<" ";
        Traverse(root->right);
    }
}

int main()
{      
    Node *root = new Node();
    root = NULL;

   int option,value;
    
    do{
    	cout<<endl;
    	cout<<"1) To Create a new Tree"<<endl;
	    cout<<"2) To Insert a new Node"<<endl;
	    cout<<"3) To Traverse the Tree"<<endl;
    cin>>option;
    switch(option)
    {
		case 1:
		cin>>value;
		do
		{
		    root = createTree(root,value);
		    cin>>value;
		}while(value != -1);
		break;

		case 2:
		    cin>>value;
		    root = createTree(root,value);
		    break;

		case 3:
		    Traverse(root);
		    break;    
    }
}while(option != -1);

return 0;
}