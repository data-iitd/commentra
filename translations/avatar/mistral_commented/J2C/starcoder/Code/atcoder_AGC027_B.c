
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, k, ans, cost;
    long X, xsum [ 100000 ], x [ 100000 ];

    scanf("%d", &N);
    scanf("%ld", &X);

    for (i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
    }

    xsum[0] = 0;
    for (i = 0; i < N; i++) {
        xsum[i + 1] = xsum[i] + x[i];
    }

    ans = X * N + 5 * xsum[N];

    for (i = 1; i < N; i++) {
        cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k - i]);
        }
        ans = min(ans, cost);
    }

    printf("%ld\n", ans + N * X);

    return 0;
}

