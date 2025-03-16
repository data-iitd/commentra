#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (long long)1e18

typedef long long ll;
typedef struct {
    long long first;
    long long second;
} P;

ll mod = 1e9+7;

int main() {
    // 入力
    long long N, K;
    scanf("%lld %lld", &N, &K);
    long long A[N];
    REP(i, N) scanf("%lld", &A[i]);

    // 解法
    ll ans1 = 0;
    REP(i, N) {
        REP(j, N) {
            if (i >= j) continue;
            if (A[i] > A[j]) ans1++;
            ans1 %= mod;
        }
    }

    long long count[2005] = {0};
    REP(i, N) {
        count[A[i] - 1]++;
    }
    ll ans2 = 0;
    long long remain = N;
    REP(i, 2005) {
        remain -= count[i];
        ans2 += count[i] * remain;
    }
    ll tmp = K * (K - 1) / 2 % mod;
    tmp = tmp * ans2 % mod;
    ll ans = (ans1 * K % mod + tmp) % mod;

    // 出力
    printf("%lld\n", ans);
}
