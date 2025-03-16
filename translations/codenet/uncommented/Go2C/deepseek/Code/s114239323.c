#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int nextInt() {
    int v;
    scanf("%d", &v);
    return v;
}

int* nextInts(int n) {
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    return r;
}

int main() {
    int N = nextInt();
    int* h = nextInts(N);
    
    int* dp = (int*)malloc(N * sizeof(int));
    memset(dp, 0, N * sizeof(int));
    dp[1] = ABS(h[0] - h[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = MIN(dp[i - 1] + ABS(h[i] - h[i - 1]),
                    dp[i - 2] + ABS(h[i] - h[i - 2]));
    }
    
    printf("%d\n", dp[N - 1]);
    free(h);
    free(dp);
    return 0;
}
