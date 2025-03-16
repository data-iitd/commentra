
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    char c = (s < f)? 'R' : 'L';
    int d = (s < f)? 1 : -1;
    string res = "";
    int i = 1, j = s, t, l, r, k = 1;
    cin >> t >> l >> r;
    while (j!= f) {
        if (i > t && k < m) {
            cin >> t >> l >> r;
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
            j += d;
        }
        i++;
    }
    cout << res << endl;
    return 0;
}

