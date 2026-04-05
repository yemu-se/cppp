#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insertAtFront(Node *&head, int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

int main()
{

    
    Node *head = nullptr;
    insertAtFront(head, 1);
    insertAtFront(head, 2);
    insertAtFront(head, 3);
    insertAtFront(head, 4);
    insertAtFront(head, 5);
    insertAtFront(head, 6);
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;
        temp= temp->next;
    }
   

    return 0;
}
