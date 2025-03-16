#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    string r = "";
    for (char i : s) {
        if (i != '-' && i != ';' && i != '_') {
            r += tolower(i);
        }
    }
    return r;
}

void solve() {
    vector<string> l;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        l.push_back(f(s));
    }
    vector<string> l_copy = l;
    sort(l_copy.begin(), l_copy.end());
    l_copy.erase(unique(l_copy.begin(), l_copy.end()), l_copy.end());
    for (int i = 0; i < l_copy.size(); i++) {
        for (int j = 0; j < l_copy.size(); j++) {
            for (int k = 0; k < l_copy.size(); k++) {
                if (i != j || j != k || k != i) {
                    l.push_back(l_copy[i] + l_copy[j] + l_copy[k]);
                }
            }
        }
    }
    sort(l.begin(), l.end());
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string s_low = f(s);
        if (binary_search(l.begin(), l.end(), s_low)) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
