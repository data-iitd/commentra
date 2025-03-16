#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)

int main() {
  long long H, W;
  scanf("%lld %lld", &H, &W);

  long long ans;
  if (H == 1 || W == 1) {
    ans = 1;
  } else {
    long long m = H*W;
    if (m % 2 == 0) ans = m/2;
    else ans = m/2+1;
  }
  printf("%lld\n", ans);
  return 0;
}

