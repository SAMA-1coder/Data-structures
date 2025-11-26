#include <iostream>
using namespace std;

int heapArr[1000];
int heapSize = 0;

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void insertHeap(int x) {
    if (heapSize >= 999) return;
    heapSize++;
    int i = heapSize;
    heapArr[i] = x;
    while (i > 1 && heapArr[i / 2] < heapArr[i]) {
        swapInt(heapArr[i], heapArr[i / 2]);
        i /= 2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= heapSize && heapArr[l] > heapArr[largest]) largest = l;
    if (r <= heapSize && heapArr[r] > heapArr[largest]) largest = r;
    if (largest != i) {
        swapInt(heapArr[i], heapArr[largest]);
        heapifyDown(largest);
    }
}

int extractMax() {
    if (heapSize == 0) return -1;
    int maxVal = heapArr[1];
    heapArr[1] = heapArr[heapSize];
    heapSize--;
    heapifyDown(1);
    return maxVal;
}

int getMax() {
    if (heapSize == 0) return -1;
    return heapArr[1];
}

void displayHeap() {
    if (heapSize == 0) {
        cout << "Empty\n";
        return;
    }
    for (int i = 1; i <= heapSize; i++) cout << heapArr[i] << " ";
    cout << "\n";
}

int main() {
    int choice, x;
    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> x;
            insertHeap(x);
        } else if (choice == 2) {
            int v = extractMax();
            if (v == -1) cout << "Underflow\n";
            else cout << v << "\n";
        } else if (choice == 3) {
            int v = getMax();
            if (v == -1) cout << "Empty\n";
            else cout << v << "\n";
        } else if (choice == 4) {
            displayHeap();
        } else if (choice == 0) {
            break;
        }
    }
    return 0;
}

