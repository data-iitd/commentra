#include<stdio.h>

int main():
  int A[100], n, i, j, t, sw = 0, mini;

  scanf("%d", &n);
  for i in range(n):
    scanf("%d", &A[i]);

  for i in range(n):
    mini = i;
    for j in range(i, n):
      if A[j] < A[mini]:
        mini = j;
    t = A[i]; A[i] = A[mini]; A[mini] = t;
    if i != mini:
      sw++;

  for i in range(n):
    if i:
      printf(" ");
    printf("%d", A[i]);
  printf("\n");
  printf("%d\n", sw);

  return 0;

