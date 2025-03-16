#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>

int main() {
  int H, W;
  scanf("%d %d", &H, &W);

  int ans;
  if (H == 1 || W == 1) {
    ans = 1;
  } else {
    int m = H*W;
    if (m % 2 == 0) ans = m/2;
    else ans = m/2+1;
  }
  printf("%d\n", ans);
  return 0;
}

