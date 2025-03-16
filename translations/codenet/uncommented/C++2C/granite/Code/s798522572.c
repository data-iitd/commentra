
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
  int N, T;
  scanf("%d %d", &N, &T);
  int A[N];
  int B[N];
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  int m = A[0];
  B[1] = A[1] - m;
  m = std::min(m, A[1]);
  for(int i = 2; i < N; i++){
    B[i] = A[i] - m;
    m = std::min(m, A[i]);
  }
  int max = 0;
  for(int i = 0; i < N; i++) max = std::max(max, B[i]);
  int count = 0;
  for(int i = 0; i < N; i++) if(B[i] == max) count++;
  printf("%d\n", count);
}
