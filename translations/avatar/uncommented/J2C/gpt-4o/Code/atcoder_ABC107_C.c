#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *S = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }

    int temp = 0;
    int ans = INT_MAX;

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = (abs(temp) < ans) ? abs(temp) : ans;
        }
        printf("%d\n", ans);
    } else if (N - K != 0) {
        for (int i = 0; i <= N - K; i++) {
            int min = S[i];
            int max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = (2 * (-min) + max < (-min) + 2 * max) ? (2 * (-min) + max) : ((-min) + 2 * max);
            } else {
                temp = (abs(min) > abs(max)) ? abs(min) : abs(max);
            }
            ans = (temp < ans) ? temp : ans;
        }
        printf("%d\n", ans);
    } else {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0) {
            printf("%d\n", (2 * (-min) + max < (-min) + 2 * max) ? (2 * (-min) + max) : ((-min) + 2 * max));
        } else {
            printf("%d\n", (abs(min) > abs(max)) ? abs(min) : abs(max));
        }
    }

    free(S);
    return 0;
}

// <END-OF-CODE>
