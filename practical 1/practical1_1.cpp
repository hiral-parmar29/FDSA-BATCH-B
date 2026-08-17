#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter number of rotations: ";
    cin >> h;

    // If h is greater than n, reduce it
    h = h % n;

    // Left rotation
    for (int r = 0; r < h; r++)
    {
        int first = a[0];

        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[n - 1] = first;
    }

    cout << "Final array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}