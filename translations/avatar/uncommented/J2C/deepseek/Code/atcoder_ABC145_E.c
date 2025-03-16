#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int AB[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }

    qsort(AB, N, sizeof(int[2]), (int (*)(const void *, const void *))compare);

    int dp[N + 1][6001];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 6000; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    int maxValue = 0;
    for (int j = 0; j <= 6000; j++) {
        if (dp[N][j] > maxValue) {
            maxValue = dp[N][j];
        }
    }
    printf("%d\n", maxValue);

    return 0;
}

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}
