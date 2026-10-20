
#include <iostream>
using namespace std;

#define SIZE 5

int main()
{
    int q[SIZE];
    int front = -1, rear = -1;
    int n, choice, token;

    cout << "Enter maximum queue capacity (up to 5): ";
    cin >> n;

    while (true)
    {
        cout << "\n1. Join Queue";
        cout << "\n2. Serve Token";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (rear == n - 1)
            {
                cout << "Error: Queue is full!\n";
            }
            else
            {
                cout << "Enter token number: ";
                cin >> token;

                if (front == -1)
                    front = 0;

                q[++rear] = token;
                cout << "Token added successfully.\n";
            }
        }
        else if (choice == 2)
        {
            if (front == -1 || front > rear)
            {
                cout << "Error: Queue is empty!\n";
            }
            else
            {
                cout << "Served token: " << q[front] << endl;
                front++;

                if (front > rear)
                    front = rear = -1;
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        if (front == -1)
            cout << "Current front token: None\n";
        else
            cout << "Current front token: " << q[front] << endl;
    }

    return 0;
}
