#include <stdio.h>
#include <stdlib.h>
 
int main() {
  int n, x;
  scanf("%d", &n);
  scanf("%d", &x);
  int *l = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  
  int tmpSum = 0;
  int rs = 0;
  for (int i = 0; i < n; i++) {
    tmpSum += l[i];
    if (tmpSum <= x) {
      rs = i + 2;
    } else if (tmpSum > x) {
      break;
    }
  }
  printf("%d", rs);
  return 0;
}
