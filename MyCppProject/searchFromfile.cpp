#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct searchFromFile
{
    long long phoneNumber;
    string ownerName;
    double balance;
};

int main()
{
    const int MAX_SIZE = 1000;
    searchFromFile stored[MAX_SIZE];
    int actualSize = 0;
   
ifstream myFile("C:\\Users\\yemanc6505\\Desktop\\cppp\\MyCppProject\\registry.txt");
    if (!myFile)
    {
        cout << "Error:File not Found";
        return 1;
    }
    while (actualSize < MAX_SIZE && myFile >> stored[actualSize].phoneNumber >> stored[actualSize].ownerName >> stored[actualSize].balance)
    {
        actualSize++;
    }
    myFile.close();

    long long searchKey;
    cout<<"Enter phone to search";
    cin>>searchKey;
    int right = actualSize -1;
    int left =0;
   int index =-1;
      do
      {
        int mid =left +(right -left)/2;
        if(searchKey == stored[mid].phoneNumber){
            index =mid;
            break;
        }
        else if(searchKey<stored[mid].phoneNumber){
            right =mid-1;
        }
        else{
            left =mid +1;
        }
      } while (left <=right);
      
  if (index != -1) {
        cout << "\n--- RECORD FOUND ---" << endl;
        cout << "Name: " << stored[index].ownerName << endl;
        cout << "Phone: " << stored[index].phoneNumber << endl;
        cout << "Balance: " << stored[index].balance << " ETB" << endl;
    } else {
        cout << "Number not found in registry." << endl;
    }
    return 0;
}
