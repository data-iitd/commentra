
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int cal(string s, char c) {
    int n = s.length();
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c && (m & i) == i) {
            ans ^= 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2) {
        cout << s[0] << endl;
        return;
    }
    string sb;
    for (int i = 1; i < n; i++) {
        sb += abs(s[i] - s[i - 1]);
    }
    s = sb;
    if (s.find("1") != string::npos) {
        cout << cal(s, '1') << endl;
    } else {
        cout << cal(s, '2') * 2 << endl;
    }
}

int main() {
    solve();
    return 0;
}

