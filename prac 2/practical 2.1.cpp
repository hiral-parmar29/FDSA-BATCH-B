#include <iostream>
using namespace std;

// Iterative Linear Search
int linearSearchIterative(string arr[], int n, string target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

// Recursive Linear Search
int linearSearchRecursive(string arr[], int n, string target, int index)
{
    if(index == n)
        return -1;

    if(arr[index] == target)
        return index;

    return linearSearchRecursive(arr, n, target, index + 1);
}

int main()
{
    int n;

    cout << "Enter number of license plates: ";
    cin >> n;

    string arr[n];

    cout << "Enter license plates:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string target;
    cout << "Enter target plate: ";
    cin >> target;

    int choice;

    cout << "\nChoose Search Method\n";
    cout << "1. Iterative Linear Search\n";
    cout << "2. Recursive Linear Search\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result;

    if(choice == 1)
    {
        result = linearSearchIterative(arr, n, target);
    }
    else if(choice == 2)
    {
        result = linearSearchRecursive(arr, n, target, 0);
    }
    else
    {
        cout << "Invalid Choice!";
        return 0;
    }

    if(result != -1)
    {
        cout << "Plate found at position " << result << endl;
    }
    else
    {
        cout << "Plate not found." << endl;
    }

    return 0;
}