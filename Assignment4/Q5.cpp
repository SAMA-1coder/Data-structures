#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop() {
        if (q.empty()) return -1;

        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;

    s.push(10);
    s.push(20);

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Is Empty: " << s.isEmpty() << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << "Is Empty: " << s.isEmpty() << endl;

    return 0;
}

