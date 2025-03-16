#include <stdio.h>
#include <stdlib.h>

#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
    // Input
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll *A = (ll *)malloc(N * sizeof(ll));
    REP(i, N) scanf("%lld", &A[i]);

<<<<<<< HEAD
    // Solution
=======
    // Solution 
>>>>>>> 98c87cb78a (data updated)
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

    // Output
    printf("%lld\n", ans);

    free(A);
    return 0;
}

// <END-OF-CODE>
