#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++) cin >> nums[i];

    unordered_set<int> s;
    bool dup = false;

    for(int i=0;i<n;i++) {
        if(s.count(nums[i])) {
            dup = true;
            break;
        }
        s.insert(nums[i]);
    }

    if(dup) cout << "true";
    else cout << "false";

    return 0;
}

