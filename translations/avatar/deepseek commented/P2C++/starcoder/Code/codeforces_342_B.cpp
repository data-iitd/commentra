
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, f;
    cin >> n >> m >> s >> f;

    int d, c;
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    string res = "";
    int i = 1, j = s, t, l, r, k = 1;
    while (j!= f) {
        if (i > t && k < m) {
            cin >> t >> l >> r;
            k += 1;
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
        }
        j += d;
        i += 1;
    }

    cout << res << "\n";

    return 0;
}

