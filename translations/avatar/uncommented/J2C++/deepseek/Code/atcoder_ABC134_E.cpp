#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int num;
        cin >> num;
        if (mp.empty() || mp.lower_bound(num) == mp.begin()) {
            mp[num]++;
        } else {
            auto it = prev(mp.lower_bound(num));
            int key = it->first;
            int val = it->second;
            if (val == 1) {
                mp.erase(key);
            } else {
                mp[key] = val - 1;
            }
            mp[num]++;
        }
    }
    int ans = 0;
    for (auto& p : mp) {
        ans += p.second;
    }
    cout << ans << endl;
    return 0;
}

