#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top = NULL;

void visitPage(string name)
{
    Node* newNode = new Node;
    newNode->page = name;
    newNode->next = top;
    top = newNode;

    cout << "Visited page: " << name << endl;
    cout << "Current page: " << top->page << endl;
}

void goBack()
{
    if (top == NULL)
    {
        cout << "Error: No page history left!" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    if (top == NULL)
        cout << "No page open." << endl;
    else
        cout << "Current page: " << top->page << endl;
}

int main()
{
    int choice;
    string page;

    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter page name: ";
            cin >> page;
            visitPage(page);
        }
        else if (choice == 2)
        {
            goBack();
        }
        else if (choice != 3)
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    while (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    return 0;
}
