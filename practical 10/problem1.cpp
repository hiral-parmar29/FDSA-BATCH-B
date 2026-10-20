#include <iostream>
using namespace std;
int main()
{
    int table[10];
    int n, id, slot;
    for (int i = 0; i < 10; i++)
        table[i] = -1;
    cout << "Enter number of vehicles: ";
    cin >> n;
    if (n < 0 || n > 10)
    {
        cout << "Enter vehicles between 0 and 10.";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter vehicle registration number: ";
        cin >> id;
        slot = id % 10;
        int count = 0;
        while (table[slot] != -1 && count < 10)
        {
            slot = (slot + 1) % 10;
            count++;
        }
        if (count == 10)
            cout << "Parking lot is full. Vehicle cannot be parked.\n";
        else
            table[slot] = id;
    }
    cout << "\nFinal Parking Slots:\n";
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
