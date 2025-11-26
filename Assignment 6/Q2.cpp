#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}
void display() {
    if (head == nullptr) {
        cout << "List is empty.";
        return;
    }

    Node* temp = head;
    cout << "Output: ";
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << head->data << endl;
}

int main() {
    
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);
    display();
    return 0;
}

