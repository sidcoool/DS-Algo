#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};

int Height(Node *root)
{
    if(root == NULL)
    return 0;
    return root->height;
}

Node* LeftRotate(Node *root)
{
    Node *x = root->right;
    Node *y = x->left;

    x->left = root;
    root->right = y;

    x->height = max(Height(x->left),Height(x->right)) + 1;
    root->height = max(Height(root->left),Height(root->right)) + 1;

    return x;
}


Node* RightRotate(Node *root)
{
    Node *x = root->left;
    Node *y = x->right;

    x->right = root;
    root->left = y;

    x->height = max(Height(x->left),Height(x->right)) + 1;
    root->height = max(Height(root->left),Height(root->right)) + 1;

    return x;
}

int Balance(Node *root)
{
    if(root==NULL)
        return 0;
    else    
    return (Height(root->left)-Height(root->right));
}

Node* Insert(Node *root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);


    root->height = max(Height(root->left),Height(root->right)) + 1;
    int bal = Balance(root);

    if(bal<-1 && data > root->right->data)
        return LeftRotate(root);

    else if(bal>1 && data < root->left->data)
        return RightRotate(root);

    else if(bal<-1 && data < root->right->data)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

       else if(bal>1 && data > root->left->data)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }


    return root;
}




Node *Predecessor(Node *root)
{
    if(root==NULL)
        return root;
    else
    {
        while(root->right!=NULL)
        {
            root = root->right;
        }
        return root;
    }
}

Node *Delete(Node *root, int data)
{
    if(root==NULL)
        return root;

    else if(data < root->data)
        root->left = Delete(root->left,data);
    else if(data > root->data)
        root->right = Delete(root->right,data);
    else
    {
        if(!root->right || !root->left)
        {
            Node *temp = root->left ? root->left : root->right;
            if(temp==NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                swap(root,temp);
            free(temp);
        }
        else
        {
            Node *temp = Predecessor(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,temp->data);
        }
    }

    if(root==NULL)
        return root;

    root->height = max(Height(root->left),Height(root->right)) + 1;
    int bal = Balance(root);

    if(bal<-1 && data > root->right->data)
        return LeftRotate(root);

    else if(bal>1 && data < root->left->data)
        return RightRotate(root);

    else if(bal<-1 && data < root->right->data)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

       else if(bal>1 && data > root->left->data)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    return root;
}


void Inorder(Node *root)
{
    stack <Node*> s;

    while(root != NULL || !s.empty())
    {
        while(root != NULL)
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


int main()
{
    Node *root = NULL;
  root = Insert(root, 3); 
  root = Insert(root, 1); 
  root = Insert(root, 9); 
  root = Insert(root, 5); 
  root = Insert(root, 6); 
  root = Insert(root, 7);
  root = Insert(root, 15);
  root = Insert(root, 11);
  root = Insert(root, 21);
  root = Insert(root, 25);


  cout<<"Inorder traversal of the constructed AVL tree is \n"; 
  Inorder(root); 
  cout<<endl;

  root = Delete(root, 15);
  root = Delete(root, 6);
  root = Delete(root, 11);
  Inorder(root); 
  cout<<endl;
  
  return 0;
}
