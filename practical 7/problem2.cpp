
#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node* next;
};

int main()
{
    Node *front = NULL, *rear = NULL;
    int choice, patient;

    while (true)
    {
        cout << "\n1. Patient Arrives";
        cout << "\n2. Attend Patient";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient ID: ";
            cin >> patient;

            Node* newNode = new Node;
            newNode->patient = patient;
            newNode->next = NULL;

            if (front == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Patient added successfully.\n";
        }
        else if (choice == 2)
        {
            if (front == NULL)
            {
                cout << "Error: No patients waiting!\n";
            }
            else
            {
                Node* temp = front;
                cout << "Attended patient: "
                     << front->patient << endl;

                front = front->next;
                delete temp;

                if (front == NULL)
                    rear = NULL;
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

        if (front == NULL)
            cout << "Current front patient: None\n";
        else
            cout << "Current front patient: "
                 << front->patient << endl;
    }

    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}
