#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;

    for (size_t i = 0; i <= s.size() - t.size(); ++i) {
        bool f = true;
        string ss = s;

        for (size_t j = 0; j < t.size(); ++j) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = false;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }

        if (f) {
            for (auto &c : ss) {
                if (c == '?') {
                    c = 'a';
                }
            }
            ans.push_back(ss);
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
