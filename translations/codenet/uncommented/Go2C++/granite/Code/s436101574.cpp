
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 0; i <= s.size() - t.size(); i++) {
        bool ok = true;
        string cur = s;
        for (int j = 0; j < t.size(); j++) {
            if (s[i + j]!= t[j] && s[i + j]!= '?') {
                ok = false;
                break;
            } else {
                cur[i + j] = t[j];
            }
        }
        if (ok) {
            replace(cur.begin(), cur.end(), '?', 'a');
            ans.push_back(cur);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans[0] << endl;
    }

    return 0;
}

