#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
  int N;
  scanf("%d", &N);
  int64_t *A = (int64_t *)malloc(sizeof(int64_t) * N);
  rep(i, N) scanf("%lld", &A[i]);

  int64_t answer = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int64_t diff = abs(A[i] - A[j]);
      answer = max(answer, diff);
    }
  }
  printf("%lld\n", answer);
  free(A);
  return 0;
}

