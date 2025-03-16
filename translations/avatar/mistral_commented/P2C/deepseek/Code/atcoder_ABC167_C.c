#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int l[n];
    int rem[n];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        l[i] = 0;
        rem[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int ca = 0;
                for (int k = 0; k < m; k++) {
                    ca += c[j][k];
                }
                if (ca < x) {
                    rem[i] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (rem[i] == 1) {
            l[i] = 1;
        }
    }

    int valid_combinations = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] == 1) {
            valid_combinations++;
        }
    }

    if (valid_combinations == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (l[i] == 1) {
                int ca = 0;
                for (int j = 0; j < m; j++) {
                    ca += c[i][j];
                }
                if (ans == 0 || ca < ans) {
                    ans = ca;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
