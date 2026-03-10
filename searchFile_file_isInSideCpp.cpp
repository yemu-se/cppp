#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct searchFile_file_isInSideCpp
{
    long long phoneNumber;
    string ownerName;
    double balance;
};

int main()
{
    const int size = 1000;
    searchFile_file_isInSideCpp stored[size];
    int actualSize = 0;
    string filename = ("registry.txt");
    ofstream outfile(filename);
    if (outfile.is_open())
    {
        outfile << "2510 Abebe 106.50" << endl;
        outfile << "2511 Kebede 45.00" << endl;
        outfile << "2512 Chala 200.00" << endl;
        outfile << "2513 Sara 500.25" << endl;
        outfile.close();
        cout << "system: File 'registery.txt created successfully." << endl;
    }
    ifstream myFile(filename);
    if (!myFile)
    {
        cout << "error";
        return 1;
    }
    while (actualSize < size && myFile >> stored[actualSize].phoneNumber >> stored[actualSize].ownerName >> stored[actualSize].balance)
    {
        actualSize++;
    }
    myFile.close();
    cout << "Enter key you want to find ";
    long long searchKey;
    cin >> searchKey;
    int left = 0;
    int right = actualSize - 1;
    int mid;
    int index = -1;

    do
    {
        mid = left + (right - left) / 2;
        if (searchKey == stored[mid].phoneNumber)
        {
            index = mid;
            break;
        }
        else if (searchKey < stored[mid].phoneNumber)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;

    } while (left <= right);

    if (index != -1)
    {
        cout << "\n--- RECORD FOUND ---" << endl;
        cout << "Name: " << stored[index].ownerName << endl;
        cout << "Phone: " << stored[index].phoneNumber << endl;
        cout << "Balance: " << stored[index].balance << " ETB" << endl;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}
