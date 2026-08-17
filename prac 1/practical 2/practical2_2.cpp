#include <iostream>
using namespace std;

int binarySearchIterative(int a[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == target)
        {
            return mid;
        }
        else if (target < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
int binarySearchRecursive(int a[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (a[mid] == target)
    {
        return mid;
    }
    else if (target < a[mid])
    {
        return binarySearchRecursive(a, low, mid - 1, target);
    }
    else
    {
        return binarySearchRecursive(a, mid + 1, high, target);
    }
}

int main()
{
    int n, target;

    cout << "Enter number of book codes: ";
    cin >> n;

    int a[n];

    cout << "Enter sorted book codes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter target book code: ";
    cin >> target;

    int result1 = binarySearchIterative(a, n, target);

    if (result1 != -1)
    {
        cout << "Iterative Binary Search: Target found at position "<< result1 + 1 << endl;
    }
    else
    {
        cout << "Iterative Binary Search: Target not found" << endl;
    }

    int result2 = binarySearchRecursive(a, 0, n - 1, target);

    if (result2 != -1)
    {
        cout << "Recursive Binary Search: Target found at position "<< result2 + 1 << endl;
    }
    else
    {
        cout << "Recursive Binary Search: Target not found" << endl;
    }

    return 0;
}