
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int num;
        cin >> num;
        if (mp.lower_bound(num) == mp.begin()) {
            int val = mp[num];
            mp[num] = ++val;
        } else {
            auto it = mp.lower_bound(num);
            it--;
            int val = it->second;
            if (val == 1) {
                mp.erase(it);
            } else {
                mp[it->first] = --val;
            }
            val = mp[num];
            mp[num] = ++val;
        }
    }
    int ans = 0;
    for (auto it : mp) {
        ans += it.second;
    }
    cout << ans << endl;
    return 0;
}
//END-OF-CODE