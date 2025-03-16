
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, X, A[100000], S[100000];
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        S[i] = (i == 0)? A[i] : S[i - 1] + A[i];
    }
    int ans = INT_MAX;
    for (int k = 1; k <= N; k++) {
        int E = k * X + 2 * (S[N - 1] - (k - 1 >= N? 0 : S[k - 1 - 1]));
        ans = (ans < E)? ans : E;
    }
    printf("%d\n", ans + N * X + 5 * S[N - 1]);
    return 0;
}
// END-OF-CODE