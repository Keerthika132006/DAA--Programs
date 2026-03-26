#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        color = RED;
        left = right = parent = NULL;
    }
};

class RBTree {
    Node* root = NULL;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->right = x;
        x->parent = y;
    }

    void fix(Node* pt) {
        while (pt != root && pt->parent->color == RED) {
            Node *p = pt->parent, *g = p->parent;

            if (p == g->left) {
                Node* u = g->right;
                if (u && u->color == RED) {
                    p->color = u->color = BLACK;
                    g->color = RED;
                    pt = g;
                } else {
                    if (pt == p->right) { pt = p; rotateLeft(pt); }
                    p->color = BLACK; g->color = RED;
                    rotateRight(g);
                }
            } else {
                Node* u = g->left;
                if (u && u->color == RED) {
                    p->color = u->color = BLACK;
                    g->color = RED;
                    pt = g;
                } else {
                    if (pt == p->left) { pt = p; rotateRight(pt); }
                    p->color = BLACK; g->color = RED;
                    rotateLeft(g);
                }
            }
        }
        root->color = BLACK;
    }

public:
    void insert(int val) {
        Node *pt = new Node(val), *y = NULL, *x = root;

        while (x) {
            y = x;
            x = (val < x->data) ? x->left : x->right;
        }

        pt->parent = y;
        if (!y) root = pt;
        else if (val < y->data) y->left = pt;
        else y->right = pt;

        fix(pt);
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data << "(" << (r->color==RED?"R":"B") << ") ";
        inorder(r->right);
    }

    void display() { inorder(root); }
};

int main() {
    RBTree t;
    int n, x;

    cout << "Enter n: ";
    cin >> n;

    while (n--) {
        cin >> x;
        t.insert(x);
    }

    t.display();
}