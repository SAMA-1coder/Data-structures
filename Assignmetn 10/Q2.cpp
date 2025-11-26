#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++) cin >> A[i];

    cin >> m;
    int B[m];
    for(int i=0;i<m;i++) cin >> B[i];

    unordered_set<int> s;
    for(int i=0;i<n;i++) s.insert(A[i]);

    for(int i=0;i<m;i++)
        if(s.count(B[i])) cout << B[i] << " ";

    return 0;
}

