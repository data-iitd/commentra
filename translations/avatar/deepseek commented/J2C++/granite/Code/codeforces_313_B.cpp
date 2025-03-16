
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cum[s.length() + 1];
    cum[0] = cum[s.length()] = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1])
            cum[i] = cum[i - 1] + 1;
        else
            cum[i] = cum[i - 1];
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cum[r - 1] - cum[l - 2] << endl;
    }

    return 0;
}

