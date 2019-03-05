#include <iostream>
#include <stdio.h>
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

truct Node *insert(struct Node *root, int ikey) 
{ 
    // Searching for a Node with given value 
    Node *ptr = root; 
    Node *par = NULL; // Parent of key to be inserted 
    while (ptr != NULL) 
    { 
        // If key already exists, return 
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
  
        par = ptr; // Update parent pointer 
  
        // Moving on left subtree. 
        if (ikey < ptr->info) 
        { 
            if (ptr -> lthread == false) 
                ptr = ptr -> left; 
            else
                break; 
        } 
  
        // Moving on right subtree. 
        else
        { 
            if (ptr->rthread == false) 
                ptr = ptr -> right; 
            else
                break; 
        } 
    } 
  
    // Create a new node 
    Node *tmp = new Node; 
    tmp -> info = ikey; 
    tmp -> lthread = true; 
    tmp -> rthread = true; 
  
    if (par == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (ikey < (par -> info)) 
    { 
        tmp -> left = par -> left; 
        tmp -> right = par; 
        par -> lthread = false; 
        par -> left = tmp; 
    } 
    else
    { 
        tmp -> left = par; 
        tmp -> right = par -> right; 
        par -> rthread = false; 
        par -> right = tmp; 
    } 
  
    return root; 
} 
  
// Returns inorder successor using tright 
Node *inorderSuccessor(Node *ptr) 
{ 
    // If tright is set, we can quickly find 
    if (ptr -> tright == true) 
        return ptr->right; 
  
    // Else return leftmost child of right subtree 
    ptr = ptr -> right; 
    while (ptr -> tleft == false) 
        ptr = ptr -> left; 
    return ptr; 
} 
  
// Printing the threaded tree 
void Traverse(Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
  
    // Reach leftmost node 
    Node *ptr = root; 
    while (ptr->left!=NULL) 
        ptr = ptr -> left; 
  
    // One by one print successors 
    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> data); 
        ptr = inorderSuccessor(ptr); 
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
