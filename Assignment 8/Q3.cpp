#include <iostream>
#include <algorithm>
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

Node* minValueNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left != nullptr) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* t = root->right;
            delete root;
            return t;
        } else if (root->right == nullptr) {
            Node* t = root->left;
            delete root;
            return t;
        } else {
            Node* t = minValueNode(root->right);
            root->data = t->data;
            root->right = deleteNode(root->right, t->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + minDepth(root->right);
    if (root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    inorder(root);
    cout << endl;

    int delVal;
    cin >> delVal;
    root = deleteNode(root, delVal);

    inorder(root);
    cout << endl;

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    return 0;
}

