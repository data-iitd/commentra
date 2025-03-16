#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define lint long long int
#define MOD 1000000007

int main() {
  int n; scanf("%d", &n);
  lint a[n], acc[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    acc[i + 1] = acc[i] + a[i];
    acc[i + 1] %= MOD;
  }

  lint ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD;
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}

