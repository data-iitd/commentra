
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 0; i <= s.length() - t.length(); i++) {
        bool f = true;
        string ss = s;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j]!= t[j] && s[i + j]!= '?') {
                f = false;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            replace(ss.begin(), ss.end(), '?', 'a');
            ans.push_back(ss);
        }
    }
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    }

    return 0;
}

