
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertBeginning(string name)
{
    Node* newNode = new Node;
    newNode->song = name;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL)
        head = tail = newNode;
    else
    {
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd(string name)
{
    Node* newNode = new Node;
    newNode->song = name;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(string target, string name)
{
    Node* temp = head;

    while (temp != NULL && temp->song != target)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->song = name;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;

    delete temp;
}

void display()
{
    Node* temp = head;
    int count = 0;

    cout << "Playlist: ";

    if (head == NULL)
        cout << "Empty";

    while (temp != NULL)
    {
        cout << temp->song << " ";
        temp = temp->next;
        count++;
    }

    cout << "\nTotal songs: " << count << "\n";
}

int main()
{
    int choice;
    string name, target;

    do
    {
        cout << "\n--- Music Playlist ---\n";
        cout << "1. Add at beginning\n";
        cout << "2. Add at end\n";
        cout << "3. Insert after a song\n";
        cout << "4. Remove first song\n";
        cout << "5. Display playlist\n";
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
                cout << "Enter song name (one word): ";
                cin >> name;
                insertBeginning(name);
                display();
                break;

            case 2:
                cout << "Enter song name (one word): ";
                cin >> name;
                insertEnd(name);
                display();
                break;

            case 3:
                cout << "Enter existing song: ";
                cin >> target;
                cout << "Enter new song (one word): ";
                cin >> name;
                insertAfter(target, name);
                display();
                break;

            case 4:
                deleteFirst();
                display();
                break;

            case 5:
                display();
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
