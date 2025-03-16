
#include <stdio.h>

int main() {
  int n, x, l[100000], tmpL, tmpSum, rs, i;
  scanf("%d", &n);
  scanf("%d", &x);
  for (i = 0; i < n; i++) {
    scanf("%d", &tmpL);
    l[i] = tmpL;
  }
  
  tmpSum = 0;
  rs = 0;
  for (i = 0; i < n; i++) {
    tmpSum += l[i];
    if (i >= n) {
      rs = n;
      break;
    }
    if (tmpSum <= x) {
      rs = i + 2;
    } else if (tmpSum > x) {
      break;
    }
  }
  printf("%d\n", rs);
  return 0;
}
