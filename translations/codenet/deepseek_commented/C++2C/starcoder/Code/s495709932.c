#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
  int N;
  scanf("%d", &N);
  int A[N];
  rep(i, N) scanf("%d", &A[i]);

  int64_t answer = 0;
  // Calculate the maximum absolute difference between any two elements in the array
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int64_t diff = abs(A[i] - A[j]);
      answer = max(answer, diff);
    }
  }
  // Output the result
  printf("%lld\n", answer);
  return 0;
}
