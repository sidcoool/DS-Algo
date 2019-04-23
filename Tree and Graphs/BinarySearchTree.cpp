#include <iostream>
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
		return Newnode(value);
	}

    else if(value <= root->data)
    	root->left = createTree(root->left,value);
    else
        root->right = createTree(root->right,value);
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