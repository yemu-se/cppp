#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void printLinkedList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void addAtEnd(Node **head, int newValue)
{
    Node* newnode = new Node;
    newnode->data =newValue;
    newnode->next =*head;
    if(*head ==nullptr){
        *head = newnode;
    }
    while (newnode->next != nullptr)
    {
        newnode =newnode->next;
    }
    *head = newnode;
    
}

int main()
{
    Node *head = nullptr;
    addAtEnd(&head,6);
    addAtEnd(&head,3);
    addAtEnd(&head, 5);
    addAtEnd(&head,1);
    printLinkedList(head);
    return 0;
}