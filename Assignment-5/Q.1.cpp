#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// (a) Insert at beginning
node* ib(node* head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    return newnode;
}

// (b) Insert at end
node* ie(node* head, int value) {
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

// (c1) Insert before a specific value
node* insertBefore(node* head, int target, int value) {
    node* newnode = new node;
    newnode->data = value;

    if (head == nullptr) {
        cout << "List is empty.\n";
        delete newnode;
        return head;
    }

    if (head->data == target) {
        newnode->next = head;
        return newnode;
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->data != target)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Value " << target << " not found.\n";
        delete newnode;
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

// (c2) Insert after a specific value
node* insertAfter(node* head, int target, int value) {
    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value " << target << " not found.\n";
        delete newnode;
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

// (d) Delete from beginning
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

// (e) Delete from end
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
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// (f) Delete specific node
node* deleteNode(node* head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }

    if (head->data == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr)
        cout << "Value " << value << " not found.\n";
    else {
        node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    return head;
}

// (g) Search for node
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

// (h) Display list
void display(node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ">";
        temp = temp->next;
    }
    cout << "null\n";
}

// ?? MENU-DRIVEN MAIN FUNCTION
int main() {
    node* head = nullptr;
    int choice, value, target;

    do {
        cout << "\n========= LINKED LIST OPERATIONS =========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display Linked List\n";
        cout << "0. Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                head = ib(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                head = ie(head, value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value to insert before " << target << ": ";
                cin >> value;
                head = insertBefore(head, target, value);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value to insert after " << target << ": ";
                cin >> value;
                head = insertAfter(head, target, value);
                break;
            case 5:
                head = deleteBeginning(head);
                cout << "Node deleted from beginning.\n";
                break;
            case 6:
                head = deleteEnd(head);
                cout << "Node deleted from end.\n";
                break;
            case 7:
                cout << "Enter value of node to delete: ";
                cin >> value;
                head = deleteNode(head, value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(head, value);
                break;
            case 9:
                cout << "Current Linked List: ";
                display(head);
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

