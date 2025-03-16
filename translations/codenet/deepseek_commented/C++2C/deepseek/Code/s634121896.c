#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define DEBUG
#define fi first
#define se second
#define pqueue priority_queue
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define int long long
#define mk(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int vi;
typedef int vvi;
typedef int vull;
typedef int vll;
typedef int pii;
typedef int vpii;
typedef int pll;
typedef int vb;
typedef int vs;
typedef int vvll;
typedef int vc;

const ll INF = 1e9 + 228;
const ll INFLL = 1e18;
const ll MOD = 1e9 + 7;
const ld eps = 1e-6;
const ld eps2 = 1e-9;
const ll MOD2 = 998244353;
const ll dosz = 5e5;
const ll SZ = (1 << 18);
const ld PI = atan2l(0, -1);

void fast_io() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    // freopen("cowjog.in", "r", stdin);
    // freopen("cowjog.out", "w", stdout);
}

void solve() {
    int n;
    scanf("%lld", &n);
    vi nums[n];
    int last = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    
    vi dp[n + 1];
    dp[0] = 1;
    pii kek[n];
    pii prev[n];
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (prev[nums[i - 1]] != i - 1 ? kek[nums[i - 1]] : 0);
        dp[i] %= MOD;
        kek[nums[i - 1]] = dp[i];
        prev[nums[i - 1]] = i;
    }
    
    printf("%lld\n", dp[n]);
}

signed main() {
    fast_io();
    srand(time(NULL));
    int q = 1;
    // scanf("%lld", &q);
    while (q--)
        solve();
}
