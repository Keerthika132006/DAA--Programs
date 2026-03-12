#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        root = new Node;
        root->data = x;
        root->left = root->right = NULL;
        return root;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);

    cout << "Before deletion: ";
    inorder(root);

    root = deleteNode(root, 30);

    cout << "\nAfter deletion: ";
    inorder(root);
}