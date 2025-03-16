#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Abs(int a) {
    return a < 0 ? -a : a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *h = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }
    
    int *dp = (int *)malloc(N * sizeof(int));
    dp[0] = 0; // dp[0] is not used, but we initialize it for clarity
    dp[1] = Abs(h[0] - h[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = Min(dp[i - 1] + Abs(h[i] - h[i - 1]),
                     dp[i - 2] + Abs(h[i] - h[i - 2]));
    }
    
    printf("%d\n", dp[N - 1]);
    
    free(h);
    free(dp);
    
    return 0;
}

/* <END-OF-CODE> */
