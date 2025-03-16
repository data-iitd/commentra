#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    vector<string> ans;

    for (size_t i = 0; i < s.size() - t.size() + 1; ++i) {
        string ss = s;
        bool f = true;
        for (size_t j = 0; j < t.size(); ++j) {
            if (ss[i + j] != t[j] && ss[i + j] != '?') {
                f = false;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            for (size_t k = 0; k < ss.size(); ++k) {
                if (ss[k] == '?') {
                    ss[k] = 'a';
                }
            }
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
