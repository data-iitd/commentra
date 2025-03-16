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
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll A[N];
    REP(i, N) scanf("%lld", &A[i]);

    // 解法 
    ll ans1 = 0;
    REP(i, N) {
        REP(j, N) {
            if (i >= j) continue; // Skip if i is not less than j
            if (A[i] > A[j]) ans1++; // Increment ans1 if A[i] > A[j]
            ans1 %= mod; // Take modulo to prevent overflow
        }
    }
    
    // Count the frequency of each element in the array A
    ll count[2005] = {0};
    REP(i, N) {
        count[A[i]-1]++; // Store frequency of A[i]
    }

    ll ans2 = 0;
    ll remain = N;
    REP(i, 2005) {
        remain -= count[i]; // Reduce the remaining count
        ans2 += count[i] * remain; // Calculate the number of valid pairs
    }

    // Calculate the final answer
    ll tmp = K * (K - 1) / 2;
    tmp %= mod; // Take modulo to prevent overflow
    tmp *= ans2; // Multiply with ans2
    tmp %= mod; // Take modulo to prevent overflow
    ll ans = 0;
    ans += ans1 * K; // Add contribution from ans1
    ans %= mod; // Take modulo to prevent overflow
    ans += tmp; // Add contribution from tmp
    ans %= mod; // Take modulo to prevent overflow

    // Output the final answer
    printf("%lld\n", ans);
}
