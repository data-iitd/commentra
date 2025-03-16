

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef long long ll;

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);
    ll pmin = 1000, mmin = 0;
    for (int i = n - 1; i >= 0; i--) {
        int v = s[i] - '0';
        ll npmin = (pmin + 10 - (v + 1)) % MOD;
        ll nmmin = (mmin + v + 1) % MOD;
        pmin = npmin;
        mmin = nmmin;
    }
    ll ans = (pmin < mmin)? pmin : mmin;
    printf("%lld\n", ans);
    return 0;
}

