#include <iostream>
#include <unordered_set>
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

bool checkDuplicate(Node* root, unordered_set<int> &s) {
    if(root == nullptr) return false;
    if(s.count(root->data)) return true;
    s.insert(root->data);
    return checkDuplicate(root->left, s) || checkDuplicate(root->right, s);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(5);

    unordered_set<int> s;
    if(checkDuplicate(root, s)) cout << "Duplicates Found";
    else cout << "No Duplicates";

    return 0;
}

