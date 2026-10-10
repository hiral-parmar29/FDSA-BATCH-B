#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
void insertFront(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertPosition(int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid position.\n";
        return;
    }
    if (position == 1)
    {
        insertFront(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Position out of range.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
void display()
{
    Node* temp = head;
    cout << "Patient queue: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int choice, value, position;
    do
    {
        cout << "\n--- Patient Queue Insertion ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter patient token: ";
                cin >> value;
                insertFront(value);
                display();
                break;
            case 2:
                cout << "Enter patient token: ";
                cin >> value;
                insertEnd(value);
                display();
                break;
            case 3:
                cout << "Enter patient token: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertPosition(value, position);
                display();
                break;
            case 4:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
