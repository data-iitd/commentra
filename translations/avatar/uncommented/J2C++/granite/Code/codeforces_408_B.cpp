
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    unordered_map<char, bool> map;
    for (char c : s1) {
        map[c] = true;
    }
    for (char c : s2) {
        if (!map[c]) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (isValid(s1, s2) == false) {
        cout << -1 << endl;
    } else {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (char c : s1.toCharArray()) {
            if (m1.find(c)!= m1.end()) {
                m1[c]++;
            } else {
                m1[c] = 1;
            }
        }
        for (char c : s2.toCharArray()) {
            if (m2.find(c)!= m2.end()) {
                m2[c]++;
            } else {
                m2[c] = 1;
            }
        }
        int ans = 0;
        unordered_set<char> hs;
        for (char c : s2.toCharArray()) {
            if (!hs.count(c)) {
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
//END-OF-CODE