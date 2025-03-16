#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void solve() {
    int N;
    long X;
    scanf("%d", &N);
    scanf("%ld", &X);
    
    long *x = (long *)malloc(N * sizeof(long));
    long *xsum = (long *)malloc((N + 1) * sizeof(long));
    
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }
    
    long ans = X * N + 5 * xsum[N];
    for (int i = 1; i < N; i++) {
        long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k - i < 0 ? 0 : k - i]);
        }
        if (cost < ans) {
            ans = cost;
        }
    }
    
    printf("%ld\n", ans + N * X);
    
    free(x);
    free(xsum);
}

int main() {
    solve();
    return 0;
}
