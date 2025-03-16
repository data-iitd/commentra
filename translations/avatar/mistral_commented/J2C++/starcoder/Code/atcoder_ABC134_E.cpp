#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map <int, int> m;
    while (n--) {
        int num;
        cin >> num;
        if (m.find(num) == m.end()) {
            int val = m.find(num) == m.end()? 0 : m[num];
            m[num] = val + 1;
        } else {
            int key = m.lower_bound(num)->first;
            int val = m[key];
            if (val == 1) {
                m.erase(key);
            } else {
                m[key] = val - 1;
            }
            int val = m.find(num) == m.end()? 0 : m[num];
            m[num] = val + 1;
        }
    }
    int ans = 0;
    for (auto it = m.begin(); it!= m.end(); it++) {
        ans += it->second;
    }
    cout << ans << endl;
}

