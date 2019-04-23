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


bool printAncestors(Node *root, int target)
{
  /* base cases */
  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
 
  /* If target is present in either left or right subtree of this node,  then print this node */
  
if ( printAncestors(root->left, target) || printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 
  /* Else return false */
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

   if(printAncestors(root,3))
   	cout<<"Done !"<<endl;
   else
   	cout<<"Not Present"<<endl;

   return 0;
}