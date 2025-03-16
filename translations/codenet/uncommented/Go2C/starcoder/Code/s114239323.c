#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    int h[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }
    
    int dp[MAX_N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    dp[1] = abs(h[0] - h[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    printf("%d\n", dp[N - 1]);
}

