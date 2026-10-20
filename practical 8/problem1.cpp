#include <iostream>
#include <queue>
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
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node* root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}
int main() {
    Node* root = NULL;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n <= 0) {
        cout << "Tree is empty.";
        return 0;
    }
    cout << "Enter root value: ";
    cin >> value;
    root = createNode(value);
    queue<Node*> q;
    q.push(root);
    for (int i = 1; i < n; i++) {
        Node* current = q.front();
        q.pop();
        cout << "Enter left child of " << current->data
             << " (enter -1 if none): ";
        cin >> value;
        if (value != -1) {
            current->left = createNode(value);
            q.push(current->left);
        }
        if (i < n) {
            cout << "Enter right child of " << current->data
                 << " (enter -1 if none): ";
            cin >> value;
            if (value != -1) {
                current->right = createNode(value);
                q.push(current->right);
            }
        }
    }
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevel order: ";
    levelOrder(root);
    return 0;
}
