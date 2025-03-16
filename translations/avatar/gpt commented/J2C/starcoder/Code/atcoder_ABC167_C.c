_
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, x, min = INT_MAX;
    scanf("%d %d %d", &n, &m, &x);
    int a[n][m + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < (1 << n); i++) {
        int res[m + 1];
        for (int j = 0; j <= m; j++)
            res[j] = 0;
        for (int j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) {
                for (int k = 0; k <= m; k++)
                    res[k] += a[j][k];
            }
        }
        int flag = 1;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = 0;
                break;
            }
        }
        if (flag)
            min = min < res[0]? min : res[0];
    }
    if (min == INT_MAX)
        printf("-1");
    else
        printf("%d", min);
    return 0;
}
