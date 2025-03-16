

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);
  int a[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  int leftl[N];
  int rightl[N];
  int que[N];
  int index = 0;
  while (index < N) {
    while (index < N && que[0] < N && a[que[0]] < a[index]) {
      int ind = que[0];
      rightl[ind] = index - ind - 1;
      memmove(que + 1, que, sizeof(int) * (N - ind - 1));
      que[0] = index++;
    }
    que[0] = index++;
  }
  index = N - 1;
  while (index >= 0) {
    while (index >= 0 && que[0] >= 0 && a[que[0]] <= a[index]) {
      int ind = que[0];
      leftl[ind] = ind - index - 1;
      memmove(que + 1, que, sizeof(int) * (ind + 1));
      que[0] = --index;
    }
    que[0] = --index;
  }
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += (long long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
