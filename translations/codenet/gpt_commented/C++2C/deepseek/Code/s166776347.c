#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define INF (long long)1e18

typedef long long ll;
typedef struct {
    long long first;
    long long second;
} P;

ll mod = 1e9+7;

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll A[N];
    REP(i, N) scanf("%lld", &A[i]);

    ll ans1 = 0;
    REP(i, N) {
        REP(j, N) {
            if (i >= j) continue;
            if (A[i] > A[j]) ans1++;
            ans1 %= mod;
        }
    }

    ll count[2005] = {0};
    REP(i, N) {
        count[A[i] - 1]++;
    }

    ll ans2 = 0;
    ll remain = N;
    REP(i, 2005) {
        remain -= count[i];
        ans2 += count[i] * remain;
    }

    ll ans = 0;
    ll tmp = K * (K - 1);
    tmp /= 2;
    tmp %= mod;
    tmp *= ans2;
    tmp %= mod;
    ans += ans1 * K;
    ans %= mod;
    ans += tmp;
    ans %= mod;

    printf("%lld\n", ans);
}
