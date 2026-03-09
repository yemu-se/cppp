#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 4, 3, 2};
    int n = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
    cout << "sorted array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }
}