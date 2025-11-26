#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertEnd(char ch) {
    Node* newNode = new Node;
    newNode->data = ch;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool isPalindrome() {
    if (head == nullptr || head == tail)
        return true;

    Node* left = head;
    Node* right = tail;

    while (left != nullptr && right != nullptr && left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter characters (no spaces): ";
    cin >> s;

    for (char c : s)
        insertEnd(c);

    if (isPalindrome())
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}

