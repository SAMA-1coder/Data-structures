#include <iostream>
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
    if(root == nullptr) return createNode(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

void preorder(Node* root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}

