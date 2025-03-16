#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

int compare_int(const void *a, const void *b):
  return *(long int*)b - *(long int*)a;

long int gcd(long int a, long int b):
  if(b == 0):
    return a;
  else:
    return gcd(b, a % b);

long int lcm(long int a, long int b):
  return a * b / gcd(a, b);

int main(void):
  long int n, k, q;
  long int a[100001];
  long long int point[100001] = {0};

  scanf("%ld%lld%ld", &n, &k, &q);

  for(long int i = 0; i < q; i++):
    scanf("%ld", &a[i]);
    point[a[i] - 1]++;
    for(long int j = 0; j < n; j++):
      if(a[i]!= (j + 1) && point[j] < k):
        point[j]++;
  for(long int i = 0; i < n; i++):
    if(k - (q - point[i]) > 0):
      printf("Yes\n");
    else:
      printf("No\n");

  return 0;

