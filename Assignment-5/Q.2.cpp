#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// Function to insert node at the end
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

// Function to display linked list
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Function to count and delete all occurrences of a key
node* deleteAllOccurrences(node* head, int key, int &count) {
    count = 0;

    // Remove all occurrences at the beginning
    while (head != nullptr && head->data == key) {
        node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Now handle rest of the list
    node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == key) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return head;
}

// Main function
int main() {
    node* head = nullptr;

    // Creating the linked list: 1->2->1->2->1->3->1
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);
    head = insertEnd(head, 3);
    head = insertEnd(head, 1);

    cout << "Original Linked List: ";
    display(head);

    int key = 1;
    int count = 0;

    // Delete all occurrences of key and count them
    head = deleteAllOccurrences(head, key, count);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
