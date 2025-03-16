#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef long long ll;

int chmin(int *a, int b) {
  if (*a > b) {
    *a = b;
    return 1;
  }
  return 0;
}

int chmax(int *a, int b) {
  if (*a < b) {
    *a = b;
    return 1;
  }
  return 0;
}

const int INF = (1 << 30) - 1;
const long long INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a), (a) + n
#define RALL(a) (a), (a) + n
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int A, B, C, K;
  scanf("%d %d %d %d", &A, &B, &C, &K);
  if (A + B >= K) {
    printf("%d\n", A < K ? A : K);
  } else {
    printf("%d\n", A - (K - (A + B)));
  }
}
