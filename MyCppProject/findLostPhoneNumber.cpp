#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct SIMCARD
{
    long long phoneNumber;
    string ownerName;
    double balance;
};

int main()
{
    SIMCARD stored[] = {
        {251, "Abebe", 106},
        {252, "Kebede"}};
    int size = sizeof(stored) / sizeof(stored[0]);
    int index = -1;
    int left = 0;
    int right = size - 1;
    int mid;
    long long searchKey;
    cout << "Find by Phone number";
    cin >> searchKey;
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
        {
            left = mid + 1;
        }

    } while (left <= right);
    if (index != -1)
    {
        cout << "key found" << stored[index].ownerName << stored[index].phoneNumber << stored[index].balance;
    }
    else
    {
        cout << "not found";
    }

    return 0;
}