
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for(int i=0;i<n;i++)
#define FOR(i, s, n) for(int i=(s);i<(n);i++)
#define FOREQ(i, s, n) for(int i=(s);i<=(n);i++)
#define FORIT(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
  int n;
  scanf("%d", &n);
  ll a[n];
  REP(i, n) scanf("%lld", &a[i]);
  sort(a, a+n, greater<ll>());
  int index;
  ll max = 1LL<<60;
  FOR(i, 1, n) {
    if(max>llabs(a[0]-2*a[i])) {
      max = llabs(a[0]-2*a[i]);
      index = i;
    }
  }
  printf("%lld %lld\n", a[0], a[index]);
  return 0;
}


