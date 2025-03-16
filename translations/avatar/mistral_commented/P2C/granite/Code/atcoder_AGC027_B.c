
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, A[100000], S[100000], ans = 2147483647;
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        S[i] = (i == 0)? A[i] : S[i - 1] + A[i];
    }
    for (int k = 1; k <= N; k++) {
        int E = k * X + 2 * (S[N - 1] - (k == N? 0 : S[N - 2 * k - 1]));
        ans = (ans < E)? ans : E;
    }
    printf("%d\n", ans + N * X + 5 * S[N - 1]);
    return 0;
}
