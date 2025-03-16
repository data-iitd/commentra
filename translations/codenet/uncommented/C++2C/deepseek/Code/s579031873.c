#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cfloat.h>
#include <complex.h>
#include <functional.h>
#include <iostream.h>
#include <map.h>
#include <queue.h>
#include <set.h>
#include <stack.h>
#include <string.h>
#include <unordered_map.h>
#include <vector.h>

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} P;

vector_t table;
vector_t roads;
vector_t qs;

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
