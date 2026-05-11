#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    // Node *prev;
};

void deleteNode(Node *&head, int target)
{
    if (head == nullptr)
    {
        cout << "Empty List";
    }

    if (head->value == target)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    while (current->next != nullptr && current->next->value != target)
    {
        current = current->next;
    }
    if (current->next != nullptr)
    {
        Node *nodeTodelte = current->next;
        current->next = current->next->next;
        delete nodeTodelte;
    }
    else
        cout << "Not found";
}

void addToList(Node *&head, int value)
{
    Node *newnode = new Node;
    newnode->value = value;
    newnode->next = head;
    head = newnode;
}

void display(Node* head){
    if(head == nullptr) cout<<"Empty list";
    Node* temp= head;
    while (temp != nullptr)
    {
        cout<<temp->value<<"->";
      temp = temp->next;
    }
    cout<<" null"<<endl;
}

int main(){
    Node *head = nullptr;
    addToList(head,5);
    addToList(head,6);
    addToList(head,7);
    display(head);
 deleteNode(head,6);
 display(head);
    return 0;
}