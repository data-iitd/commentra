#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m, x, i, j, k, min = 2147483647;
    scanf("%d %d %d", &n, &m, &x);
    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc((m + 1) * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < pow(2, n); i++) {
        int *status = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) {
                status[j] = 1;
            }
        }
        int *res = (int *)malloc((m + 1) * sizeof(int));
        for (j = 0; j < n; j++) {
            if (status[j] == 1) {
                for (k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        int flag = 1;
        for (j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            min = min < res[0] ? min : res[0];
        }
    }
    if (min == 2147483647) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }
    return 0;
}
