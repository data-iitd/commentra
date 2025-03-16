#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int c[n][m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int ans = -1;
    for (int mask = 1; mask < (1 << n); mask++) {
        int cost = 0;
        int understanding[m];
        memset(understanding, 0, sizeof(understanding));

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cost += c[i][0];
                for (int j = 1; j <= m; j++) {
                    understanding[j - 1] += c[i][j];
                }
            }
        }

        int possible = 1;
        for (int j = 0; j < m; j++) {
            if (understanding[j] < x) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            if (ans == -1 || cost < ans) {
                ans = cost;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
