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

    for(auto &p : mp) {
        cout << p.first << " -> " << p.second << " times" << endl;
    }

    return 0;
}

