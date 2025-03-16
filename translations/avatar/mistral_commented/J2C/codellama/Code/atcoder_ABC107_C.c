
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, K, i, temp, ans;
    scanf("%d %d", &N, &K);
    int S[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    if (K == 1) {
        for (i = 0; i < N; i++) {
            temp = S[i];
            ans = min(abs(temp), ans);
        }
        printf("%d\n", ans);
    } else if (N - K != 0) {
        int min, max;
        for (i = 0; i <= N - K; i++) {
            min = S[i];
            max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    } else {
        min = S[0];
        max = S[N - 1];
        if (min < 0 && max > 0) {
            printf("%d\n", min(2 * (abs(min)) + max, (abs(min)) + 2 * max));
        } else {
            printf("%d\n", max(abs(min), abs(max)));
        }
    }
    return 0;
}

