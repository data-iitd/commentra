
#include <stdio.h>
#include <limits.h>

int main() {
    int N, X, A[100000], S[100001] = {0}, ans = INT_MAX;
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        S[i + 1] = S[i] + A[i];
    }
    for (int k = 1; k <= N; k++) {
        int E = k * X + 2 * (S[N] - S[N - 2 * k - 1]);
        ans = ans < E? ans : E;
    }
    printf("%d\n", ans + N * X + 5 * S[N]);
    return 0;
}
// 