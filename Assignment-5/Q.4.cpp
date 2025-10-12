#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// Function to insert a new node at the end
node* insertEnd(node* head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;

    if (head == nullptr)
        return newnode;

    node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

// Function to display the linked list
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to reverse the linked list
node* reverseList(node* head) {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse link
        prev = current;         // Move prev one step ahead
        current = next;         // Move current one step ahead
    }

    return prev; // New head of reversed list
}

int main() {
    node* head = nullptr;

    // Creating linked list: 1->2->3->4->NULL
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    cout << "Original Linked List: ";
    display(head);

    // Reversing the linked list
    head = reverseList(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}

