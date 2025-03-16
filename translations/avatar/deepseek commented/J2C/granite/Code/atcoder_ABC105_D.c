
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long longull;
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 4e6 + 10;
const int MOD = 1e9 + 7;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

int n, m;
int a[MAXN];
map<int, int> mp;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 0, sum = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum = (sum - a[i] % m + m) % m;
        ans += mp[sum];
        mp[sum]++;
    }
    printf("%lld\n", ans);
    return 0;
}
