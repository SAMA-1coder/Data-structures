#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertBeginning(int x);
void insertEnd(int x);
void insertAfter(int key, int x);
void insertBefore(int key, int x);
void deleteNode(int key);
void searchNode(int key);
void display();

int main() {
    int choice, x, key;

    do {
        cout << "\n=== CIRCULAR LINKED LIST MENU ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert AFTER a given node\n";
        cout << "4. Insert BEFORE a given node\n";
        cout << "5. Delete a node (by value)\n";
        cout << "6. Search for a node (by value)\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                insertBeginning(x);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> x;
                insertEnd(x);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> x;
                insertAfter(key, x);
                break;
            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> x;
                insertBefore(key, x);
                break;
            case 5:
                cout << "Enter value of node to delete: ";
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 7:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void insertBeginning(int x) {
    Node* newNode = new Node;
    newNode->data = x;

    if (head == nullptr) {
        newNode->next = newNode; // point to itself
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;

    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertAfter(int key, int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key " << key << " not found.\n";
}

void insertBefore(int key, int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // key at head
    if (head->data == key) {
        insertBeginning(x);
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
    } while (temp != head);

    cout << "Key " << key << " not found.\n";
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // only one node
    if (head->next == head && head->data == key) {
        delete head;
        head = nullptr;
        cout << "Node " << key << " deleted.\n";
        return;
    }

    // delete head
    if (head->data == key) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        temp = head;
        head = head->next;
        delete temp;
        cout << "Node " << key << " deleted.\n";
        return;
    }

    // delete non-head
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            cout << "Node " << key << " deleted.\n";
            return;
        }
    } while (temp != head);

    cout << "Key " << key << " not found.\n";
}

void searchNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            cout << "Key " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Key " << key << " not found in the list.\n";
}

void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}


#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* head = nullptr;

void insertBeginning(int x);
void insertEnd(int x);
void insertAfter(int key, int x);
void insertBefore(int key, int x);
void deleteNode(int key);
void searchNode(int key);
void display();

int main() {
    int choice, x, key;

    do {
        cout << "\n=== DOUBLY LINKED LIST MENU ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert AFTER a given node\n";
        cout << "4. Insert BEFORE a given node\n";
        cout << "5. Delete a node (by value)\n";
        cout << "6. Search for a node (by value)\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                insertBeginning(x);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> x;
                insertEnd(x);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> x;
                insertAfter(key, x);
                break;
            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> x;
                insertBefore(key, x);
                break;
            case 5:
                cout << "Enter value of node to delete: ";
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 7:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void insertBeginning(int x) {
    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int x) {
    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    DNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    DNode* temp = head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void insertBefore(int key, int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // key at head
    if (head->data == key) {
        insertBeginning(x);
        return;
    }

    DNode* temp = head->next;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    DNode* temp = head;

    // find node
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key " << key << " not found.\n";
        return;
    }

    // if head
    if (temp == head) {
        head = temp->next;
        if (head != nullptr)
            head->prev = nullptr;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node " << key << " deleted.\n";
}

void searchNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    DNode* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Key " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Key " << key << " not found in the list.\n";
}

void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List (forward): ";
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

