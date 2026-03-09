#include <iostream>
using namespace std;

int main()
{
    int index = -1;
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int key;
    cout << "Enter key";
    cin >> key;
    for (int i = 0; i < n - 1; i++)
    {

        if (array[i] == key)
        {
            index = i;
        }
    }
    if(index!=-1){
        cout<<"the key is found at"<<index;
    }
    else{
        cout<<"not found";
    }

    return 0;
}