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
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find and print the middle element of the list
void findMiddle(node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    node* slow = head;
    node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "The middle element is: " << slow->data << endl;
}

int main() {
    node* head = nullptr;

    // Creating the linked list: 1->2->3->4->5
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    cout << "Linked List: ";
    display(head);

    // Find the middle element
    findMiddle(head);

    return 0;
}

