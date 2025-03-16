#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (1 << 29)
#define LL long long int

LL const MOD = 1000000007;

int main() {
    LL n, c;
    scanf("%lld %lld", &n, &c);

    LL *x = (LL *)malloc((n + 1) * sizeof(LL));
    LL *v = (LL *)malloc((n + 1) * sizeof(LL));
    LL *lefttotal = (LL *)malloc((n + 1) * sizeof(LL));
    LL *maxlefttotal = (LL *)malloc((n + 1) * sizeof(LL));
    LL *righttotal = (LL *)malloc((n + 1) * sizeof(LL));
    LL *maxrighttotal = (LL *)malloc((n + 1) * sizeof(LL));

    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &v[i]);
    }

    lefttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        lefttotal[i] = lefttotal[i - 1] + v[i];
    }

    maxlefttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        maxlefttotal[i] = (maxlefttotal[i - 1] > (lefttotal[i] - x[i])) ? maxlefttotal[i - 1] : (lefttotal[i] - x[i]);
    }

    righttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        righttotal[i] = righttotal[i - 1] + v[n - i + 1];
    }

    maxrighttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        maxrighttotal[i] = (maxrighttotal[i - 1] > (righttotal[i] - (c - x[n + 1 - i]))) ? maxrighttotal[i - 1] : (righttotal[i] - (c - x[n + 1 - i]));
    }

    LL ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = (ans > (lefttotal[i] - x[i])) ? ans : (lefttotal[i] - x[i]);
        ans = (ans > (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i])) ? ans : (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]);
        ans = (ans > (righttotal[i] - (c - x[n + 1 - i]))) ? ans : (righttotal[i] - (c - x[n + 1 - i]));
        ans = (ans > (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i])) ? ans : (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]);
    }

    printf("%lld\n", ans);

    free(x);
    free(v);
    free(lefttotal);
    free(maxlefttotal);
    free(righttotal);
    free(maxrighttotal);

    return 0;
}

// <END-OF-CODE>
