
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

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
    int l[n][n];
    int rem[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < itertools.combinations(pre, i); j++) {
            l[i][j] = list(j);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int ca = 0;
            for (int k = 0; k < l[i][j].length; k++) {
                ca += c[l[i][j][k]][i];
            }
            if (ca < x) {
                rem[j] = 1;
            } else {
                rem[j] = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            if (rem[j] == 1) {
                l[i][j].pop();
            }
        }
        for (int j = 0; j < n; j++) {
            if (rem[j] == 1) {
                l[i][j].pop();
            }
        }
        if (l[i][j].length == 0) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int ca = 0;
        for (int j = 0; j < l[0][i].length; j++) {
            ca += c[l[0][i][j]][0];
        }
        if (ans == 0) {
            ans = ca;
        } else {
            ans = min(ans, ca);
        }
    }
    printf("%d\n", ans);
    return 0;
}
