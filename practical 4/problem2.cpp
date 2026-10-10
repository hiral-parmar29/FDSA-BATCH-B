#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
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
void deleteValue(int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient deleted.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL &&
           temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Patient not found.\n";
        return;
    }
    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

    cout << "Patient deleted.\n";
}
void displayForward()
{
    if (head == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Queue (front to back): ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void displayReverse(Node* temp)
{
    if (temp == NULL)
    {
        return;
    }
    displayReverse(temp->next);
    cout << temp->data << " ";
}
void clearList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main()
{
    int n, value, choice;
    cout << "Enter number of patients: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter patient token: ";
        cin >> value;
        insertEnd(value);
    }
    do
    {
        cout << "\n--- Patient Queue Operations ---\n";
        cout << "1. Delete Patient by Token\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Reverse\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter token to delete: ";
                cin >> value;
                deleteValue(value);
                displayForward();
                break;
            case 2:
                displayForward();
                break;
            case 3:
                cout << "Queue (back to front): ";
                displayReverse(head);
                cout << endl;
                break;
            case 4:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    clearList();
    return 0;
}
