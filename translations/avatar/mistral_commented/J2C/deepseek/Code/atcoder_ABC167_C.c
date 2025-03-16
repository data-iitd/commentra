#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int min = INT_MAX;
    int x;
    scanf("%d", &x);

    for (int i = 0; i < (1 << n); i++) {
        int status[n];
        for (int j = 0; j < n; j++) {
            status[j] = (i & (1 << j)) ? 1 : 0;
        }

        int res[m + 1] = {0};
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) {
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }

        int flag = 1;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            if (res[0] < min) {
                min = res[0];
            }
        }
    }

    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
