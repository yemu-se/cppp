#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (array[j - 1] > array[j])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
            else
                break;
        }
    }
    cout << "sorted array";
    for (int i = 0; i < size; i++)
    {
        cout << array[i]<<" ";
    }
}
int main()
{ 
    int array[]={100,99,98,97,96,95,94,93,92,91,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,0};
    int n =sizeof(array)/sizeof(array[0]);
    insertionSort(array,n);
    return 0;
}