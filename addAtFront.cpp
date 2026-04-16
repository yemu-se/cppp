#include <iostream>
using namespace std;

struct NOde
{
    int data;
    NOde* next;
};
void printLinkedList(NOde* n){
    while (n!=nullptr)
    {
        cout<<n->data<<" -> ";
        n=n->next;
    }
    cout<<"Null";
    
}

void addFront(NOde** head,int newValue){
        NOde* newNode = new NOde;
        newNode->data =newValue;
        newNode->next = *head;
       *head = newNode;
}

int main(){
 // NOde* head=new NOde;  // Start with an empty list instead of an uninitialized node  This print gabge value
  NOde* head =nullptr;

  addFront(&head,2);
  addFront(&head,0);
  printLinkedList(head);
    return 0;
}
