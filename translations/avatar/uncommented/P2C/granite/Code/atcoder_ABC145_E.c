
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int time;
    int val;
} TimeValue;

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    TimeValue *time_value = (TimeValue *)malloc(sizeof(TimeValue) * (N + 1));
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i].time, &time_value[i].val);
    }
    time_value[0].time = 0;
    time_value[0].val = 0;
    qsort(time_value + 1, N, sizeof(TimeValue), [](const void *a, const void *b) {
        return ((TimeValue *)a)->val - ((TimeValue *)b)->val;
    });
    int **dp = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *)malloc(sizeof(int) * T);
        memset(dp[i], -1, sizeof(int) * T);
    }
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
        for (int t = 1; t < T; t++) {
            if (time_value[n].time > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = fmax(dp[n - 1][t], time_value[n].val + dp[n - 1][t - time_value[n].time]);
            }
        }
    }
    int val_acum = time_value[N].val;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];
    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n].val;
        t -= time_value[n + 1].time;
        if (t < 0) {
            break;
        } else {
            max_val = fmax(max_val, val_acum + dp[n - 1][t]);
        }
    }
    printf("%d\n", max_val);
    return 0;
}
