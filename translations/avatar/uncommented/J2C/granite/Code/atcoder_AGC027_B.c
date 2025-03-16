
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, i, j, k;
    long X, ans, cost, *x, *xsum;
    scanf("%d %ld", &N, &X);
    x = (long*)malloc(sizeof(long) * N);
    xsum = (long*)malloc(sizeof(long) * (N + 1));
    for (i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }
    ans = X * N + 5 * xsum[N];
    for (i = 1; i < N; i++) {
        cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[MAX(k - i, 0)]);
        }
        ans = MIN(ans, cost);
    }
    printf("%ld\n", ans + N * X);
    free(x);
    free(xsum);
    return 0;
}
// END-OF-CODE