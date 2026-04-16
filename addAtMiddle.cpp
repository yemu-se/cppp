#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void printLinkedList(Node *head){
    while (head!=nullptr)
    {
        cout<<head->data<<" -> ";
        head =head->next;
    }
    cout<<"Null";
}

void addAtAfter(Node* previous,int newValue){

    if(previous == nullptr){
        cout<<"You cannot Add at the middle there is no element";
        return;
    }
Node* newNode = new Node;
newNode->data = newValue;

newNode->next = previous->next;
previous->next =newNode;

}

int main(){
   Node* head =new Node;
   head->data =10;
   head->next = nullptr;
   addAtAfter(head,1);
   addAtAfter(head,2);
   addAtAfter(head,3);
    printLinkedList(head);
    return 0;
}