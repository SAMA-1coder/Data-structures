#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->left = t->right = nullptr;
    return t;
}

Node* insertNode(Node* root, int x) {
    if (root == nullptr) return createNode(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    if (isBST(root)) cout << "Tree is a BST";
    else cout << "Tree is not a BST";

    return 0;
}

