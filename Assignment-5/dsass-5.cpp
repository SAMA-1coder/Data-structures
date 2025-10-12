#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};


node* ib(node* head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    return newnode;
}


node* ie(node* head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;

    if (head == nullptr) {
        return newnode;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// (c) Insertion before a specific value
node* insertBefore(node* head, int target, int value) {
    node* newnode = new node;
    newnode->data = value;

    // If list is empty
    if (head == nullptr) {
        cout << "List is empty.\n";
        delete newnode;
        return head;
    }

    // If target is at head
    if (head->data == target) {
        newnode->next = head;
        return newnode; // newnode becomes head
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << target << " not found.\n";
        delete newnode;
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

// (c) Insertion after a specific value
node* insertAfter(node* head, int target, int value) {
    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << target << " not found.\n";
        delete newnode;
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

// (d) Deletion from beginning
node* deleteBeginning(node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// (e) Deletion from end
node* deleteEnd(node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// (f) Deletion of specific node (by value)
node* deleteNode(node* head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }

    // If the node to be deleted is head
    if (head->data == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << value << " not found.\n";
    } else {
        node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    return head;
}

// (g) Search a node and display position
void searchNode(node* head, int value) {
    int pos = 1;
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << " from head.\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << value << " not found in the list.\n";
}

// (h) Display all node values
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ">";
        temp = temp->next;
    }
    cout << "null\n";
}

// ?? MAIN FUNCTION
int main() {
    node* head = nullptr;

    // Insert at beginning
    head = ib(head, 1);
    head = ib(head, 2);
    head = ib(head, 3);
    head = ib(head, 4);
    head = ib(head, 5);

    cout << "List after insertion at beginning:\n";
    display(head);

    // Insert at end
    head = ie(head, 6);
    head = ie(head, 7);
    cout << "List after insertion at end:\n";
    display(head);

    // Insert before and after specific value
    head = insertBefore(head, 3, 35);
    cout << "List after inserting 35 before 3:\n";
    display(head);

    head = insertAfter(head, 4, 45);
    cout << "List after inserting 45 after 4:\n";
    display(head);

    // Delete from beginning
    head = deleteBeginning(head);
    cout << "List after deleting from beginning:\n";
    display(head);

    // Delete from end
    head = deleteEnd(head);
    cout << "List after deleting from end:\n";
    display(head);

    // Delete specific node
    head = deleteNode(head, 3);
    cout << "List after deleting node 3:\n";
    display(head);

    // Search for node
    searchNode(head, 45);
    searchNode(head, 100); // not found example

    return 0;
}
