#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node *next;
};

Node *head = new Node();

void Insert(int value) {
    Node *temp = new Node();
    temp->val = value;
    temp->next = NULL;
    if(head != NULL) {
        temp->next = head;
        head = temp;
    }
    else {
        head = temp;
    }

}

void Print() {
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void Reverse() {
    if(head != NULL) {
    Node *current = new Node();
    Node *p = new Node();
    Node *n = new Node();
    current = head;
    p = current;
    n = current->next;
    current->next = NULL;

   while(n != NULL) {
    current = n;
    n = current->next;
    if(n == NULL)
    head = current;

    current->next = p;
    p = current;  
   }

 }

}

int main() {
    head = NULL;

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        Insert(a[i]);
    }
    

    Print();

    Reverse();
    Print();

    return 0;
}
