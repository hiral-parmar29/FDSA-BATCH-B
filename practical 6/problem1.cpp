#include <iostream>
using namespace std;

int main()
{
    int stack[100], n, top = -1;
    int choice, tray;

    cout << "Enter stack capacity: ";
    cin >> n;

    do
    {
        cout << "\n1. Place Tray (Push)";
        cout << "\n2. Take Tray (Pop)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (top == n - 1)
            {
                cout << "Error: Stack is full!" << endl;
            }
            else
            {
                cout << "Enter tray number: ";
                cin >> tray;

                top++;
                stack[top] = tray;

                cout << "Tray placed successfully." << endl;
                cout << "Current top tray: " << stack[top] << endl;
            }
        }
        else if (choice == 2)
        {
            if (top == -1)
            {
                cout << "Error: Stack is empty!" << endl;
            }
            else
            {
                cout << "Tray taken: " << stack[top] << endl;
                top--;

                if (top == -1)
                    cout << "Stack is now empty." << endl;
                else
                    cout << "Current top tray: " << stack[top] << endl;
            }
        }
        else if (choice != 3)
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}