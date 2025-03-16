

#include <stdio.h>
#include <limits.h>

int main() {
    int N, K, S[100000], temp, ans = INT_MAX;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = ans < temp? ans : temp;
        }
    } else if (N - K!= 0) {
        int min, max;
        for (int i = 0; i <= N - K; i++) {
            min = S[i];
            max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = ans < temp? ans : temp;
        }
    } else {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0) {
            ans = min(2 * (abs(min)) + max, abs(min) + 2 * max);
        } else {
            ans = max(abs(min), abs(max));
        }
    }
    printf("%d\n", ans);
    return 0;
}
