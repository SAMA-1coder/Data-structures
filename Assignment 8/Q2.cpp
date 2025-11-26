#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* createNode(int x, Node* p) {
    Node* t = new Node;
    t->data = x;
    t->left = t->right = nullptr;
    t->parent = p;
    return t;
}

Node* insertNode(Node* root, int x, Node* p = nullptr) {
    if (root == nullptr) return createNode(x, p);
    if (x < root->data) root->left = insertNode(root->left, x, root);
    else if (x > root->data) root->right = insertNode(root->right, x, root);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* curr = root;
    while (curr != nullptr && curr->data != key) {
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return curr;
}

Node* minValueNode(Node* root) {
    if (root == nullptr) return nullptr;
    Node* curr = root;
    while (curr->left != nullptr) curr = curr->left;
    return curr;
}

Node* maxValueNode(Node* root) {
    if (root == nullptr) return nullptr;
    Node* curr = root;
    while (curr->right != nullptr) curr = curr->right;
    return curr;
}

Node* inorderSuccessor(Node* x) {
    if (x == nullptr) return nullptr;
    if (x->right != nullptr) return minValueNode(x->right);
    Node* p = x->parent;
    while (p != nullptr && x == p->right) {
        x = p;
        p = p->parent;
    }
    return p;
}

Node* inorderPredecessor(Node* x) {
    if (x == nullptr) return nullptr;
    if (x->left != nullptr) return maxValueNode(x->left);
    Node* p = x->parent;
    while (p != nullptr && x == p->left) {
        x = p;
        p = p->parent;
    }
    return p;
}

int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    int key;
    cin >> key;
    Node* r1 = searchRecursive(root, key);
    Node* r2 = searchIterative(root, key);
    if (r1 != nullptr) cout << "Found (recursive)\n";
    else cout << "Not found (recursive)\n";
    if (r2 != nullptr) cout << "Found (iterative)\n";
    else cout << "Not found (iterative)\n";

    Node* mn = minValueNode(root);
    Node* mx = maxValueNode(root);
    if (mn != nullptr) cout << "Min: " << mn->data << "\n";
    if (mx != nullptr) cout << "Max: " << mx->data << "\n";

    int k2;
    cin >> k2;
    Node* node2 = searchIterative(root, k2);
    Node* suc = inorderSuccessor(node2);
    if (node2 != nullptr && suc != nullptr) cout << "Successor of " << k2 << " is " << suc->data << "\n";
    else cout << "No inorder successor for " << k2 << "\n";

    int k3;
    cin >> k3;
    Node* node3 = searchIterative(root, k3);
    Node* pre = inorderPredecessor(node3);
    if (node3 != nullptr && pre != nullptr) cout << "Predecessor of " << k3 << " is " << pre->data << "\n";
    else cout << "No inorder predecessor for " << k3 << "\n";

    return 0;
}

