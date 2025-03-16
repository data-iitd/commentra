#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

int main() {
  int n, k; scanf("%d %d", &n, &k);
  printf("%d\n", pow(k, n));
}

