#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

bool isCircular() {
    if (head == nullptr)
        return false;
    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;
    return temp == head;
}

int main() {
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{2, nullptr};
    Node* n3 = new Node{3, nullptr};

    head = n1;
    n1->next = n2;
    n2->next = n3;

    cout << "1. Without making it circular: ";
    if (isCircular())
        cout << "Circular Linked List\n";
    else
        cout << "Not Circular Linked List\n";

    n3->next = head;

    cout << "2. After making it circular: ";
    if (isCircular())
        cout << "Circular Linked List\n";
    else
        cout << "Not Circular Linked List\n";

    return 0;
}

