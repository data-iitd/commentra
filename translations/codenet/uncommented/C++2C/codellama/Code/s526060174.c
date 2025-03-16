#include <stdio.h>
#define rep(S, L) for (int i = S; i < L; ++i)
int main() {
  int n, m;
  int k, a;
  int x[31] = {};
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &a);
      x[a]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    if (x[i] == n) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
