
#include <stdio.h>

int main() {
  int n; scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  int acc[n + 1];
  acc[0] = 0;
  for (int i = 0; i < n; i++) {
    acc[i + 1] = acc[i] + a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * (acc[n] - acc[i + 1]);
  }
  printf("%d\n", ans);
  return 0;
}
