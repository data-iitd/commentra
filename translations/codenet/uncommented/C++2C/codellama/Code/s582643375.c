#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mod 1000000007
#define NMAX 1000010

long long fac[NMAX], finv[NMAX], inv[NMAX];

void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < NMAX; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

long long C(int n,int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main() {
  init();
  int X, Y; scanf("%d %d", &X, &Y);
  if((X+Y) % 3 != 0) {
    printf("0\n");
    return 0;
  }
  int n = (X+Y) / 3+1;
  int k = 2*(n-1) - Y + 1; // y = 2xより最も上にくる点からどれだけ離れているか。
  printf("%lld\n", C(n-1, k-1));
  return 0;
}
