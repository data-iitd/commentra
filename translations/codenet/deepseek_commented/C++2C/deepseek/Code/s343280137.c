#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define INF INT_MAX
#define LL long long int
#define MOD 1000000007

int main() {
    LL n, c;
    scanf("%lld %lld", &n, &c);

    LL x[n+1], v[n+1];
    for(int i = 1; i < n+1; i++) {
        scanf("%lld %lld", &x[i], &v[i]);
    }

    LL lefttotal[n+1], maxlefttotal[n+1];
    memset(lefttotal, 0, sizeof(lefttotal));
    memset(maxlefttotal, 0, sizeof(maxlefttotal));

    for(int i = 1; i < n+1; i++) {
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    for(int i = 1; i < n+1; i++) {
        maxlefttotal[i] = lefttotal[i] - x[i] > maxlefttotal[i-1] ? lefttotal[i] - x[i] : maxlefttotal[i-1];
    }

    LL righttotal[n+1], maxrighttotal[n+1];
    memset(righttotal, 0, sizeof(righttotal));
    memset(maxrighttotal, 0, sizeof(maxrighttotal));

    for(int i = 1; i < n+1; i++) {
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }

    for(int i = 1; i < n+1; i++) {
        maxrighttotal[i] = righttotal[i] - (c - x[n+1-i]) > maxrighttotal[i-1] ? righttotal[i] - (c - x[n+1-i]) : maxrighttotal[i-1];
    }

    LL ans = 0;
    for(int i = 1; i < n+1; i++) {
        LL temp1 = lefttotal[i] - x[i];
        LL temp2 = lefttotal[i] - 2*x[i] + maxrighttotal[n-i];
        LL temp3 = righttotal[i] - (c - x[n+1-i]);
        LL temp4 = righttotal[i] - 2*(c - x[n+1-i]) + maxlefttotal[n-i];
        if(temp1 > ans) ans = temp1;
        if(temp2 > ans) ans = temp2;
        if(temp3 > ans) ans = temp3;
        if(temp4 > ans) ans = temp4;
    }

    printf("%lld\n", ans);
    return 0;
}
