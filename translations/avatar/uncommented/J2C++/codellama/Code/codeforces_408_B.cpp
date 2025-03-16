
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

bool isValid(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    map<char, bool> map;
    for (char c : s1) {
        map[c] = true;
    }
    for (char c : s2) {
        if (!map.count(c)) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (!isValid(s1, s2)) {
        cout << -1 << endl;
    } else {
        map<char, int> m1, m2;
        for (char c : s1) {
            if (m1.count(c)) {
                m1[c]++;
            } else {
                m1[c] = 1;
            }
        }
        for (char c : s2) {
            if (m2.count(c)) {
                m2[c]++;
            } else {
                m2[c] = 1;
            }
        }
        int ans = 0;
        set<char> hs;
        for (char c : s2) {
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

