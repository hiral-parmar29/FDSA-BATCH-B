#include <iostream>
#include <string>
using namespace std;
struct SNode
{
    string name;
    SNode* next;
};
struct DNode
{
    string name;
    DNode* next;
    DNode* prev;
};
SNode* sHead = NULL;
DNode* dHead = NULL;
void insertSingly(string name, int pos)
{
    SNode* newNode = new SNode;
    newNode->name = name;
    if (sHead == NULL)
    {
        newNode->next = newNode;
        sHead = newNode;
        return;
    }
    if (pos <= 1)
    {
        SNode* last = sHead;
        while (last->next != sHead)
            last = last->next;
        newNode->next = sHead;
        last->next = newNode;
        sHead = newNode;
        return;
    }
    SNode* temp = sHead;
    int i = 1;
    while (i < pos - 1 && temp->next != sHead)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertDoubly(string name, int pos)
{
    DNode* newNode = new DNode;
    newNode->name = name;
    if (dHead == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        dHead = newNode;
        return;
    }
    if (pos <= 1)
    {
        DNode* last = dHead->prev;
        newNode->next = dHead;
        newNode->prev = last;
        last->next = newNode;
        dHead->prev = newNode;
        dHead = newNode;
        return;
    }
    DNode* temp = dHead;
    int i = 1;
    while (i < pos - 1 && temp->next != dHead)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteSingly(string name)
{
    if (sHead == NULL)
    {
        cout << "Singly list is empty!\n";
        return;
    }
    SNode* current = sHead;
    SNode* previous = NULL;
    do
    {
        if (current->name == name)
            break;
        previous = current;
        current = current->next;
    } while (current != sHead);
    if (current->name != name)
    {
        cout << "Student not found in singly list.\n";
        return;
    }
    if (current->next == current)
        sHead = NULL;
    else if (current == sHead)
    {
        SNode* last = sHead;
        while (last->next != sHead)
            last = last->next;
        sHead = sHead->next;
        last->next = sHead;
    }
    else
        previous->next = current->next;
    delete current;
}
void deleteDoubly(string name)
{
    if (dHead == NULL)
    {
        cout << "Doubly list is empty!\n";
        return;
    }
    DNode* temp = dHead;
    do
    {
        if (temp->name == name)
            break;

        temp = temp->next;
    } while (temp != dHead);
    if (temp->name != name)
    {
        cout << "Student not found in doubly list.\n";
        return;
    }
    if (temp->next == temp)
        dHead = NULL;
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == dHead)
            dHead = temp->next;
    }
    delete temp;
}
void displaySingly()
{
    cout << "Singly Circular: ";
    if (sHead == NULL)
    {
        cout << "Empty\n";
        return;
    }
    SNode* temp = sHead;
    do
    {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != sHead);

    cout << "(back to first)\n";
}
void displayDoubly()
{
    cout << "Doubly Circular: ";
    if (dHead == NULL)
    {
        cout << "Empty\n";
        return;
    }
    DNode* temp = dHead;
    do
    {
        cout << temp->name << " <-> ";
        temp = temp->next;
    } while (temp != dHead);
    cout << "(back to first)\n";
}
void displayBoth()
{
    displaySingly();
    displayDoubly();
}
int main()
{
    int choice, pos;
    string name;
    do
    {
        cout << "\n--- Passing Game ---\n";
        cout << "1. Join the circle\n";
        cout << "2. Leave the circle\n";
        cout << "3. Display both circles\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a number.\n";
            break;
        }
        switch (choice)
        {
            case 1:
                cout << "Enter student name (one word): ";
                cin >> name;
                cout << "Enter position: ";
                if (!(cin >> pos))
                {
                    cout << "Invalid position!\n";
                    return 0;
                }
                insertSingly(name, pos);
                insertDoubly(name, pos);
                displayBoth();
                break;
            case 2:
                cout << "Enter student name to leave: ";
                cin >> name;
                deleteSingly(name);
                deleteDoubly(name);
                displayBoth();
                break;
            case 3:
                displayBoth();
                break;
            case 0:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
