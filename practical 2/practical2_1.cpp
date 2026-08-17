#include <iostream>
using namespace std;

int linearSearchIterative(int a[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int linearSearchRecursive(int a[], int n, int target, int index)
{
    if (index == n)
    {
        return -1;
    }

    if (a[index] == target)
    {
        return index;
    }

    return linearSearchRecursive(a, n, target, index + 1);
}

int main()
{
    int n, target;

    cout << "Enter number of vehicles: ";
    cin >> n;

    int a[n];

    cout << "Enter license plate numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter target license plate: ";
    cin >> target;

    int result1 = linearSearchIterative(a, n, target);

    if (result1 != -1)
    {
        cout << "Iterative Search: Target found at position "<< result1 + 1 << endl;
    }
    else
    {
        cout << "Iterative Search: Target not found" << endl;
    }

    int result2 = linearSearchRecursive(a, n, target, 0);

    if (result2 != -1)
    {
        cout << "Recursive Search: Target found at position " << result2 + 1 << endl;
    }
    else
    {
        cout << "Recursive Search: Target not found" << endl;
    }

    return 0;
}