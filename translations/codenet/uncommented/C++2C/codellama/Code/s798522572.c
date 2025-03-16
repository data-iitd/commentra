#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int N, T;
  scanf("%d %d", &N, &T);
  int A[N];
  int *B = (int *)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  int m = A[0];
  B[1] = A[1] - m;
  m = min(m, A[1]);
  for(int i = 2; i < N; i++){
    B[i] = A[i] - m;
    m = min(m, A[i]);
  }
  printf("%d\n", count(B, B + N, *max_element(B, B + N)));
  free(B);
  return 0;
}

