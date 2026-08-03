#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    int rotation = h % n;

    cout << "Final display order: ";

    
    for (int i = rotation; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    
    for (int i = 0; i < rotation; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}



