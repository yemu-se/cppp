#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};

void deleteByPostion(Node *&head,  int pos)
{    if(head == nullptr){
        cout<<"Empty List";
        return;
    }   
    if ( pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;       
    for (int i = 0; current != nullptr && i < pos - 1; i++)
    {
        current = current->next;
    }
    if (current != nullptr && current->next !=nullptr)//
    {
        Node *toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }
    else
        cout << "Not found";
}

void addAtEnd(Node *&head, int value)
{
    Node *newnode = new Node;
    newnode->value = value;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next!= nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty List ";
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

int main()
{
    Node *head = nullptr;
    addAtEnd(head,5);
    addAtEnd(head,6);
    addAtEnd(head,7);
    addAtEnd(head,8);
    display(head);
    deleteByPostion(head,0);
    deleteByPostion(head,1);
    display(head);
}
