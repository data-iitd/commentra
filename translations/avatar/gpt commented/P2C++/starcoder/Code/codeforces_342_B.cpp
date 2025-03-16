#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, f;
    cin >> n >> m >> s >> f;

    int d = 1;
    if (s < f) {
        d = 1;
    } else {
        d = -1;
    }

    string res = "";
    int i = 1, j = s;
    int t, l, r;
    cin >> t >> l >> r;
    int k = 1;

    while (j!= f) {
        if (i > t && k < m) {
            cin >> t >> l >> r;
            k += 1;
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += (d == 1)? 'R' : 'L';
            j += d;
        }

        i += 1;
    }

    cout << res << "\n";

    return 0;
}

