#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int dp[N];
    dp[0] = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] <= dp[i - 1]) {
            int j = i - 1;
            while (j >= 0 && A[i] <= dp[j]) {
                j--;
            }
            for (int k = i; k > j; k--) {
                dp[k] = A[i];
            }
        } else {
            dp[i] = A[i];
        }
    }
    int K = 0;
    while (dp[K] == 0) {
        K++;
    }
    int ans = K;
    for (int i = K + 1; i < N; i++) {
        if (dp[i] == 0) {
            int j = i - 1;
            while (j >= 0 && dp[j] == 0) {
                j--;
            }
            for (int k = i; k > j; k--) {
                dp[k] = dp[i];
            }
        } else {
            dp[i] = dp[i];
        }
        if (dp[i] > dp[ans]) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}

