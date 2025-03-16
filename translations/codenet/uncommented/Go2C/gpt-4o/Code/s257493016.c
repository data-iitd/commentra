#include <stdio.h>
#include <limits.h>

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int r = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value < r) {
            r = value;
        }
    }
    va_end(args);
    return r;
}

int main() {
    int H, N, A, B;
    scanf("%d %d", &H, &N);
    
    int dp[H + 10001];
    for (int l = 1; l < H + 10001; l++) {
        dp[l] = INT_MAX;
    }
    
    int amax = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        if (A >= amax) {
            amax = A;
        }
        dp[A] = min(2, dp[A], B);
        for (int j = A + 1; j <= H + amax + 1; j++) {
            dp[j] = min(3, dp[j], dp[j - A] + B);
        }
    }
    
    int result = INT_MAX;
    for (int i = H; i < H + amax + 1; i++) {
        result = min(2, result, dp[i]);
    }
    
    printf("%d\n", result);
    return 0;
}
