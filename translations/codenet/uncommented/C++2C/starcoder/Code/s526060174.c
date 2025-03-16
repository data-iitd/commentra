#include <stdio.h>
#define rep(S, L) for (int i = S; i < L; ++i)

int main() {
  int n, m;
  int k, a;
  int x[31] = {};
  scanf("%d %d", &n, &m);
  rep(0, n) {
    scanf("%d", &k);
    rep(0, k) {
      scanf("%d", &a);
      x[a]++;
    }
  }
  int ans = 0;
  rep(1, m+1) {
    if (x[i] == n) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
