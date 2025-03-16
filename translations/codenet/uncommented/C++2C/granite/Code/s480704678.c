
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <utility>
#include <numeric>
#include <functional>
#include <complex>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  int n; scanf("%d", &n);
  lint a[n];
  lint acc[n + 1] = {0};
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
