#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrowing records: ";
    cin >> n;

    int a[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Books borrowed more than once: ";

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        // Count frequency of current book ID
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }

        // Print only once
        bool alreadyPrinted = false;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (count > 1 && !alreadyPrinted)
        {
            cout << a[i] << " ";
        }
    }

    return 0;
}

