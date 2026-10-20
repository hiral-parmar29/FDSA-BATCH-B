#include <iostream>
using namespace std;
int main()
{
    int table[10];
    int n, id, h1, h2, slot;
    for (int i = 0; i < 10; i++)
        table[i] = -1;
    cout << "Enter number of student IDs: ";
    cin >> n;
    if (n < 0 || n > 10)
    {
        cout << "Enter IDs between 0 and 10.";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter student ID: ";
        cin >> id;
        h1 = id % 10;
        h2 = 7 - (id % 7);
        int j = 0;
        while (j < 10)
        {
            slot = (h1 + j * h2) % 10;
            if (table[slot] == -1)
            {
                table[slot] = id;
                break;
            }
            j++;
        }
        if (j == 10)
            cout << "Cannot insert ID " << id << endl;
    }
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << ": ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }
    return 0;
}
