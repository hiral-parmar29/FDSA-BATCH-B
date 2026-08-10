
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter 0, 1 and 2: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;

            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;

            high--;
        }
    }
cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
return 0;
}
