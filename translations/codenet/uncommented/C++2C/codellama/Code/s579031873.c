#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

vector<vector<ll> > table;
vector<P> roads;
vector<P> qs;

int main() {
  ll N, X;
  scanf("%lld %lld", &N, &X);

  ll ans = 0;
  ll min = 1000000000;
  for (int i = 0; i < N; i++) {
    ll tmp;
    scanf("%lld", &tmp);
    X -= tmp;
    ans++;
    if (tmp < min) min = tmp;
  }

  ans += X / min;

  printf("%lld\n", ans);

  return 0;
}

