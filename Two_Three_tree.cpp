#include <iostream>
using namespace std;

class Node {
public:
    int data[2];
    Node* child[3];
    int n;

    Node(int val) {
        data[0] = val;
        n = 1;
        child[0] = child[1] = child[2] = NULL;
    }
};

class TwoThreeTree {
public:
    Node* root = NULL;

    Node* insert(Node* root, int val) {
        if (!root)
            return new Node(val);

        // leaf node
        if (!root->child[0]) {
            root->data[root->n++] = val;

            // sort values
            if (root->n == 2 && root->data[0] > root->data[1])
                swap(root->data[0], root->data[1]);

            return root;
        }

        // insert into correct child
        if (val < root->data[0])
            root->child[0] = insert(root->child[0], val);
        else
            root->child[1] = insert(root->child[1], val);

        return root;
    }

    void display(Node* root) {
        if (!root) return;

        for (int i = 0; i < root->n; i++)
            cout << root->data[i] << " ";

        for (int i = 0; i <= root->n; i++)
            display(root->child[i]);
    }
};

int main() {
    TwoThreeTree t;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        t.root = t.insert(t.root, val);
    }

    cout << "Tree elements: ";
    t.display(t.root);

    return 0;
}