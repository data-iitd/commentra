
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    int c[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
    }
    int pre[n];
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    int l[n][n];
    int rem[n];
    int ans = 0;
    int count = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            l[j][0] = 0;
            for (int k = 1; k <= j; k++) {
                l[j][k] = l[j - 1][k - 1] + c[pre[j - 1]][i];
            }
        }
        for (int j = 0; j < n; j++) {
            if (l[n - 1][j] < x) {
                rem[count] = j;
                count++;
            }
        }
        if (count > 0) {
            for (int j = 0; j < count; j++) {
                for (int k = 0; k < n - rem[j]; k++) {
                    pre[k] = pre[k + rem[j]];
                }
                n -= rem[j];
            }
            count = 0;
        }
        if (n == 0) {
            printf("-1\n");
            break;
        }
        int min = c[pre[0]][0];
        for (int j = 1; j < n; j++) {
            if (c[pre[j]][0] < min) {
                min = c[pre[j]][0];
            }
        }
        ans += min;
    }
    printf("%d\n", ans);
    return 0;
}
