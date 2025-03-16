
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int64_t *A = (int64_t *)malloc(sizeof(int64_t) * N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }

  int64_t answer = 0;
  // Calculate the maximum absolute difference between any two elements in the array
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int64_t diff = llabs(A[i] - A[j]);
      answer = diff > answer? diff : answer;
    }
  }
  // Output the result
  printf("%lld\n", answer);
  free(A);
  return 0;
}
