#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++) cin >> nums[i];

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[nums[i]]++;

    for(int i=0;i<n;i++) {
        if(mp[nums[i]] == 1) {
            cout << nums[i];
            return 0;
        }
    }

    cout << -1;
    return 0;
}

