#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    int n, value;
    cout << "Enter number of book codes: ";
    cin >> n;
    if (n <= 0) {
        cout << "No book codes entered.";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> value;
        root = insert(root, value);
    }
    cout << "\nBook codes in ascending order: ";
    inorder(root);
    return 0;
}
