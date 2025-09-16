#include <iostream>
using namespace std;

#define MAX 5

class SimpleQueue {
    int arr[MAX], front, rear;

public:
    SimpleQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
        } else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << "Enqueued: " << x << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Dequeued: " << arr[front++] << endl;
            if (front > rear) front = rear = -1;
        }
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    SimpleQueue q;
    int choice, x;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        }
    } while (choice != 5);

    return 0;
}

