#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007

int main() {
  int n; scanf("%d", &n);
  int a[n];
  int acc[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    acc[i + 1] = acc[i] + a[i];
    acc[i + 1] %= MOD;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD;
    ans %= MOD;
  }
  printf("%d\n", ans);
  return 0;
}

