#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) { return a->freq > b->freq; }
};

// Print codes
void printCodes(Node* root, string code = "") {
    if (!root) return;
    if (!root->left && !root->right) cout << root->ch << ": " << code << "\n";
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Number of characters: ";
    cin >> n;
    char c[n];
    int f[n];
    cout << "Enter characters: ";
    for(int i=0;i<n;i++) cin >> c[i];
    cout << "Enter frequencies: ";
    for(int i=0;i<n;i++) cin >> f[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i=0;i<n;i++) pq.push(new Node(c[i], f[i]));

    while(pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *parent = new Node('$', l->freq + r->freq);
        parent->left = l; parent->right = r;
        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top());
    return 0;
}