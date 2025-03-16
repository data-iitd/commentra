#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

bool isValid(const string& s1, const string& s2) {
    unordered_map<char, bool> map;
    for (char c : s1) {
        map[c] = true;
    }
    for (char c : s2) {
        if (map.find(c) == map.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (!isValid(s1, s2)) {
        cout << -1 << endl;
    } else {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (char c : s1) {
            m1[c]++;
        }

        for (char c : s2) {
            m2[c]++;
        }

        int ans = 0;
        set<char> hs;

        for (char c : s2) {
            if (hs.find(c) == hs.end()) {
                hs.insert(c);
                int x1 = m1[c];
                int x2 = m2[c];
                x1 = min(x1, x2);
                ans += x1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

