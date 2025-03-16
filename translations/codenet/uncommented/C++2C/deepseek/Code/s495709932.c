#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int64_t A[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  int64_t answer = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int64_t diff = llabs(A[i] - A[j]);
      if (diff > answer) {
        answer = diff;
      }
    }
  }
  printf("%lld\n", answer);
  return 0;
}
