#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int N, X, A[100000];
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int S[100000];
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }
    int ans = INT_MAX;
    for (int k = 1; k <= N; k++) {
        int E = k * X + 2 * (S[N - 2 * k - 1] - (k == 1? 0 : S[N - 2 * k]));
        ans = min(ans, E);
    }
    printf("%d\n", ans + N * X + 5 * S[N - 1]);
    return 0;
}

