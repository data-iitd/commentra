#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits.h>
#include <climits>
#include <time.h>
#include <assert.h>
#include <numeric>
#include <functional>
#include <bitset>

typedef long long int lint;
const lint INF = 1001001001001001LL;
const int inf = 1000000007;
const lint MOD = 1000000007LL;
const double PI = 3.1415926535897932;

void chmin(lint *a, const lint b) {
    if (*a > b) *a = b;
}

void chmax(lint *a, const lint b) {
    if (*a < b) *a = b;
}

#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()

/* do your best */

int main() {
    int n;
    scanf("%d", &n);
    lint a[n];
    lint acc[n + 1];
    memset(acc, 0, sizeof(acc));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acc[i + 1] = acc[i] + a[i];
        acc[i + 1] %= MOD;
    }

    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
