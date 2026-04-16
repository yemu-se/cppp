#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printLinkedList(Node *head){
    while (head!=nullptr)
    {
        cout<<head->data<<" -> ";
        head =head->next;
    }
}

void addAtAfter(Node** head,int newValue){
Node* newNode = new Node;
newNode->data = newValue;
newNode->next =nullptr;
if(*head ==nullptr){
*head =newNode;
return;
}
Node* last = new Node;
while (newNode->next !=nullptr)
{
    newNode =newNode->next;

}
last =*head;

}

int main(){
   Node* head =nullptr;
   addAtAfter(&head,1);
   addAtAfter(&head,2);
   addAtAfter(&head,3);
    printLinkedList(head);
    return 0;
}