
#include <stdio.h>
#define MOD 100000007

int main(void) {
  long long N, A, B;
  scanf("%lld %lld %lld", &N, &A, &B);
  long long ans = 0;
  long long rep = N / (A + B);
  ans += rep * A;
  long long res = N - rep * (A + B);
  ans += (res < A? res : A);
  printf("%lld\n", ans);
  return 0;
}
// END-OF-CODE