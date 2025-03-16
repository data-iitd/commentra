#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1 << 29
#define LL long long int
#define MOD 1000000007

int main() {
    LL n, c;
    scanf("%lld %lld", &n, &c);

    LL x[n+1], v[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &v[i]);
    }

    LL lefttotal[n+1], maxlefttotal[n+1];
    memset(lefttotal, 0, sizeof(lefttotal));
    memset(maxlefttotal, 0, sizeof(maxlefttotal));

    for (int i = 1; i <= n; i++) {
        lefttotal[i] = lefttotal[i-1] + v[i];
        maxlefttotal[i] = lefttotal[i] - x[i] > maxlefttotal[i-1] ? lefttotal[i] - x[i] : maxlefttotal[i-1];
    }

    LL righttotal[n+1], maxrighttotal[n+1];
    memset(righttotal, 0, sizeof(righttotal));
    memset(maxrighttotal, 0, sizeof(maxrighttotal));

    for (int i = 1; i <= n; i++) {
        righttotal[i] = righttotal[i-1] + v[n-i+1];
        maxrighttotal[i] = righttotal[i] - (c - x[n+1-i]) > maxrighttotal[i-1] ? righttotal[i] - (c - x[n+1-i]) : maxrighttotal[i-1];
    }

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        LL temp = lefttotal[i] - x[i];
        if (temp > ans) ans = temp;

        temp = lefttotal[i] - 2*x[i] + maxrighttotal[n-i];
        if (temp > ans) ans = temp;

        temp = righttotal[i] - (c - x[n+1-i]);
        if (temp > ans) ans = temp;

        temp = righttotal[i] - 2*(c - x[n+1-i]) + maxlefttotal[n-i];
        if (temp > ans) ans = temp;
    }

    printf("%lld\n", ans);

    return 0;
}
