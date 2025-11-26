#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;
    return t;
}

bool hasCycle(Node* head) {
    unordered_set<Node*> s;
    Node* curr = head;
    while(curr != nullptr) {
        if(s.count(curr)) return true;
        s.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    if(hasCycle(n1)) cout << "true";
    else cout << "false";

    return 0;
}

