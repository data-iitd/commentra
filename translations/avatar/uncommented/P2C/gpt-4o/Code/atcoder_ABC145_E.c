#include <stdio.h>
#include <stdlib.h>

#define TIME 0
#define VAL 1

typedef struct {
    int time;
    int value;
} TimeValue;

int compare(const void *a, const void *b) {
    return ((TimeValue *)a)->value - ((TimeValue *)b)->value;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    
    TimeValue *time_value = malloc((N + 1) * sizeof(TimeValue));
    time_value[0].time = -1;
    time_value[0].value = -1;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i].time, &time_value[i].value);
    }

    qsort(time_value + 1, N, sizeof(TimeValue), compare);

    int **dp = malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = malloc(T * sizeof(int));
        for (int t = 0; t < T; t++) {
            dp[i][t] = -1;
        }
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
                dp[n][t] = (dp[n - 1][t] > time_value[n].value + dp[n - 1][t - time_value[n].time]) ?
                            dp[n - 1][t] : (time_value[n].value + dp[n - 1][t - time_value[n].time]);
            }
        }
    }

    int val_acum = time_value[N].value;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n].value;
        t -= time_value[n + 1].time;
        if (t < 0) {
            break;
        } else {
            max_val = (max_val > val_acum + dp[n - 1][t]) ? max_val : (val_acum + dp[n - 1][t]);
        }
    }

    printf("%d\n", max_val);

    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(time_value);

    return 0;
}

// <END-OF-CODE>
