#include <iostream>
using namespace std;
struct Node
{
    int code;
    Node* next;
};
int main()
{
    Node* table[10];
    int n, code, slot;
    for (int i = 0; i < 10; i++)
        table[i] = NULL;
    cout << "Enter number of books: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Invalid number of books.";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> code;
        slot = code % 10;
        Node* newNode = new Node;
        newNode->code = code;
        newNode->next = NULL;
        if (table[slot] == NULL)
        {
            table[slot] = newNode;
        }
        else
        {
            Node* temp = table[slot];

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";
        Node* temp = table[i];
        while (temp != NULL)
        {
            cout << temp->code << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    return 0;
}
