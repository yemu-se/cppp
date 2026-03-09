#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int left = 0;
    int right = n - 1;
    int mid;
    int index = -1;
    int key;
    cout<<"enter key";
    cin>>key;
    do
    {
        mid = (left + right) / 2;
        if (key== array[mid])
        {
            index=mid;
            break;
        }
        else if (key<array[mid])
        {
            right=mid-1;
            
        }
        else{
            left =mid+1;
            
        }
        
    } while (left <= right);
    if (index!=-1)
    {
        cout<<"The key is found at index"<<index;
    }
    else{
        cout<<"the key is not found ";
    }
    

    return 0;
}