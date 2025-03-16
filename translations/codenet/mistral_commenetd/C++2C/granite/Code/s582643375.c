

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 100000007

typedef long long ll;

ll fac[1000010];
ll finv[1000010];
ll inv[1000010];

void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < 1000010; i++) {
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

ll C(int n,int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
  init();
  int X, Y;
  scanf("%d %d", &X, &Y);
  if((X+Y) % 3!= 0) {
    printf("0\n");
    return 0;
  }
  int n = (X+Y) / 3+1;
  int k = 2*(n-1) - Y + 1;
  printf("%lld\n", C(n-1, k-1));
  return 0;
}

