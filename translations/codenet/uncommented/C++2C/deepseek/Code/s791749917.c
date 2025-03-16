#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  long long H, W;
  scanf("%lld %lld", &H, &W);

  long long ans;
  if (H == 1 || W == 1) {
    ans = 1;
  } else {
    long long m = H * W;
    if (m % 2 == 0) ans = m / 2;
    else ans = m / 2 + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
