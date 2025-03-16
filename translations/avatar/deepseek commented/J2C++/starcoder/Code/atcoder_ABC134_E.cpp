#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> map;
    while (n-- > 0) {
        int num;
        cin >> num;
        if (map.lower_bound(num) == map.end()) {
            int val = map[num];
            map[num] = val + 1;
        } else {
            int key = map.lower_bound(num)->first;
            int val = map[key];
            if (val == 1) {
                map.erase(key);
            } else {
                map[key] = val - 1;
            }
            int val = map[num];
            map[num] = val + 1;
        }
    }
    int ans = 0;
    for (auto it = map.begin(); it!= map.end(); it++) {
        ans += it->second;
    }
    cout << ans << endl;
    return 0;
}

