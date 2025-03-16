#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string scanString() {
    string s;
    cin >> s;
    return s;
}

vector<int> scanInts(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

void debug(const auto& a) {
    cerr << a << endl;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    string s = scanString();
    string t = scanString();

    vector<string> ans;
    for (size_t i = 0; i <= s.length() - t.length(); i++) {
        bool f = true;
        string ss = s;

        for (size_t j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
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
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans[0] << endl;
    }

    return 0;
}

// <END-OF-CODE>
