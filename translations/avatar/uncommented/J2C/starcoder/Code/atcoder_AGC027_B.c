#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int N;
    long X;
    scanf("%d %ld", &N, &X);
    long x[N];
    long xsum[N+1];
    for(int i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
    }
    xsum[0] = 0;
    for(int i = 0; i < N; i++) {
        xsum[i+1] = xsum[i] + x[i];
    }
    long ans = X * N + 5 * xsum[N];
    for(int i = 1; i < N; i++) {
        long cost = X * i + 5 * (xsum[N] - xsum[N-i]);
        for(int j = 5, k = N-i; k >= 0; j += 2, k -= i) {
            if(cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k-i]);
        }
        ans = min(ans, cost);
    }
    printf("%ld\n", ans + N * X);
    return 0;
}
