#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void printLinkedList(Node* n){
    while (n!= nullptr)
    {
       cout<<n->data<<" ";
       n=n->next; 
    }
}


int main()
{
    Node* head=new Node;
    Node* first = new Node;
    Node* second = new Node;
    
head->data =1;
first->data=2;
second->data=3;

head->next =first;
first->next=second;
second->next=nullptr;

 printLinkedList(head);

    return 0;
}