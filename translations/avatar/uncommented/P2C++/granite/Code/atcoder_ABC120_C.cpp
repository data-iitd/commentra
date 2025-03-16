
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    map<char, int> m;
    for (int i = 0; i < n; i++) {
        m[s[i]]++;
    }
    int ans = INT_MAX;
    for (auto it = m.begin(); it!= m.end(); it++) {
        ans = min(ans, it->second);
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}

/* END-OF-CODE */