#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x;
    cin >> n >> m >> x;
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    int pre[n];
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    int l[n][m];
    int rem[n];
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            int ca = 0;
            for (int ii = 0; ii < i; ii++) {
                ca += c[j][ii];
            }
            if (ca < x) {
                rem[count] = j;
                count++;
            }
        }
        for (int j = 0; j < count; j++) {
            for (int k = 0; k < n; k++) {
                if (k == rem[j]) {
                    continue;
                }
                l[k][i - 1] = l[k][i - 1] + l[rem[j]][i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (l[i][j] == 0) {
                l[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << l[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        int ca = 0;
        for (int j = 0; j < m; j++) {
            if (l[i][j] == -1) {
                continue;
            }
            ca += c[i][j];
        }
        if (ans == 0) {
            ans = ca;
        } else {
            ans = min(ans, ca);
        }
    }
    cout << ans << "\n";
    return 0;
}

