#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int move = i - 1;
        while (move >= 0 && array[move] > temp)
        {
            array[move+1]=array[move];
            move--;
        }
      
        array[move+1]=temp;
    }
    cout<<"the sorted array is"<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main()
{
int array[]={7,6,5,4,32,1,0};
int n =sizeof(array)/sizeof(array[0]);
insertionSort(array,n);
    return 0;
}