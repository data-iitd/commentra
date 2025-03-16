#include <bits/stdc++.h>

using namespace std;

int main() {
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
    int l[n][n];
    int rem[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                l[k][j] = k;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int ca = 0;
            for (int k = 0; k < n; k++) {
                ca += c[k][i];
            }
            if (ca < x) {
                rem[j] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (rem[j] == 1) {
                for (int k = l[j][n - 1]; k >= 0; k--) {
                    l[k][n - 1] = l[k][n - 1] - 1;
                }
            }
        }
        if (l[0][n - 1] == -1) {
            cout << -1 << endl;
            break;
        }
        for (int j = 0; j < n; j++) {
            int ca = 0;
            for (int k = 0; k < n; k++) {
                ca += c[k][0];
            }
            if (ans == 0) {
                ans = ca;
            } else {
                ans = min(ans, ca);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

