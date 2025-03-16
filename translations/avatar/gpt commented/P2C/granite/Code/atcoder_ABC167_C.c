
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int pre[n];
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }

    int l[n * (n + 1) / 2][n];
    int rem[n * (n + 1) / 2];
    int ans = 0;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (__builtin_popcount(j) == i) {
                for (int k = 0; k < n; k++) {
                    if (j & (1 << k)) {
                        l[count][k] = 1;
                    } else {
                        l[count][k] = 0;
                    }
                }
                count++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int temp = 0;
        for (int j = 0; j < count; j++) {
            int ca = 0;
            for (int k = 0; k < n; k++) {
                if (l[j][k] == 1) {
                    ca += c[k][i - 1];
                }
            }
            if (ca < x) {
                rem[temp] = j;
                temp++;
            }
        }
        if (temp > 0) {
            for (int j = 0; j < temp; j++) {
                for (int k = 0; k < n; k++) {
                    l[rem[j]][k] = 0;
                }
            }
        }
        if (temp == 0) {
            printf("-1\n");
            break;
        }
        if (i == m) {
            for (int j = 0; j < count; j++) {
                int ca = 0;
                for (int k = 0; k < n; k++) {
                    if (l[j][k] == 1) {
                        ca += c[k][0];
                    }
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = fmin(ans, ca);
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
