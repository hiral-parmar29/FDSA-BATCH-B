
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of marks: ";
    cin >> n;

    int a[n];

    cout << "Enter marks: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\n1. Bubble Sort";
    cout << "\n2. Selection Sort";
    cout << "\n3. Insertion Sort";

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    if(choice == 1) //bubblesort
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    else if(choice == 2) //selectionsort
    {
        for(int i = 0; i < n - 1; i++)
        {
            int small = i;

            for(int j = i + 1; j < n; j++)
            {
                if(a[j] < a[small])
                {
                    small = j;
                }
            }

            int temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }
    else if(choice == 3) //insertionsort
    {
        for(int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;

            while(j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = key;
        }
    }
else
    {
        cout << "Invalid choice";
        return 0;
    }
cout << "\nSorted marks: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
return 0;
}
