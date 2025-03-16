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

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

typedef long long int lint;
const lint INF = 1001001001001001LL;
const int inf = 1000000007;
const lint MOD = 1000000007LL;
const double PI = 3.1415926535897932;

void chmin(int *a, const int &b) {
  if (*a > b) *a = b;
}

void chmax(int *a, const int &b) {
  if (*a < b) *a = b;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  long long int acc[n + 1];
  memset(acc, 0, sizeof(acc));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    acc[i + 1] = acc[i] + a[i];
    acc[i + 1] %= MOD;
  }

  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
