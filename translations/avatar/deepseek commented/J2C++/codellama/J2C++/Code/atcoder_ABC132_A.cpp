
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
        } else {
            m[s[i]]++;
        }
    }
    bool ok = true;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second != 2) {
            ok = false;
            break;
        }
    }
    if (ok && m.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

