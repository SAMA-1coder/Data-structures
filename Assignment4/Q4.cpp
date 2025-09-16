#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define CHAR_RANGE 256

void firstNonRepeating(const string& s) {
    int count[CHAR_RANGE] = {0};
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        q.push(ch);
        count[ch]++;

        while (!q.empty() && count[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
}

int main() {
    string s;
    cout << "Enter string (no spaces): ";
    cin >> s;

    firstNonRepeating(s);

    return 0;
}

