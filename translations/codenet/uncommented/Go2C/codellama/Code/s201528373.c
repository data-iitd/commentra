#include <stdio.h>
 
int main() {
  int n;
  int x;
  int l[100];
  scanf("%d", &n);
  scanf("%d", &x);
  for (int i = 0; i < n; i ++) {
    int tmpL;
    scanf("%d", &tmpL);
    l[i] = tmpL;
  }
  
  int tmpSum = 0;
  int rs = 0;
  for (int i = 0; i < n; i ++) {
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
