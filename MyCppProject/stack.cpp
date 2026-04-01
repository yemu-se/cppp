#include <iostream>
using namespace std;
#define MAX_SIZE 100
int myStack[MAX_SIZE];

int top = -1;

bool isEmpty()
{
    return top = -1;
}

bool isFull()
{
    return top -= MAX_SIZE;
}

void push()
{
    int n;
    cout << "Enter the value ";
    cin >> n;
    if (isFull())
    {
        cout << "\nStack is full.\n";
    }
    else
    {
        top++;
        myStack[top] = n;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "\nEmpty Stack.\n";
    }
    else
    {
        cout << myStack[top] << "  is Popped.\n";
        top--;
    }
}

void peak()
{
    if (isEmpty())
    {
        cout << "\nEmpty stack.\n";
    }
    else
    {
        cout << myStack[top] << " is Element.\n";
    }
}

void stackSize()
{
    if (isEmpty())
    {
        cout << "\nEmpty Stack.\n";
    }
    else
    {
        cout << "\nSize =" << top + 1;
    }
}
void display()
{
    if (isEmpty())
    {
        cout << "Empty Stack";
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << myStack[i] << ", ";
            cout << endl;
        }
    }
}

int main()
{
    int n;
    do
    {
        int c;
        cout << "\nOptions";
        cout << "\n Press 1 to Push:";
        cout << "\n Press 2 to Pop:";
        cout << "\n Press 3 to Peak:";
        cout << "\n Press 4 to Display:" << endl;
        cout << "\n Press 5 to Size:" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            push();
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            peak();
            display();
            break;

        case 4:
            display();
            break;

        case 5:
            stackSize();
            break;
        default:
            cout << "Invalid input";
            break;

        }
        cout<<"\nDo you want to contnue?Press 1 to yes /Press 0 to no.";
        cin>>n;
    } while (n != 0);
    return 0;
}