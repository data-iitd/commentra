
#include <stdio.h>
#include <stdlib.h>

int pow2(int a) {
  int ret = 1;
  for (int i = 0; i < a; i++) ret *= 2;
  return ret;
}

int count(int **hw, int a, int b, int h, int w) {
  int sum = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a >> i & 1 && b >> j & 1 && hw[i][j] == 1) sum++;
    }
  }
  return sum;
}

int main() {
  int h, w, k; scanf("%d %d %d", &h, &w, &k);
  int **hw = (int **)malloc(sizeof(int *) * h);
  for (int i = 0; i < h; i++) {
    hw[i] = (int *)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
      char c; scanf(" %c", &c);
      hw[i][j] = (c == '#')? 1 : 0;
    }
  }

  int sum = 0;
  for (int i = 0; i < pow2(h); i++) {
    for (int j = 0; j < pow2(w); j++) {
      if (count(hw, i, j, h, w) == k) sum++;
    }
  }

  printf("%d\n", sum);

  for (int i = 0; i < h; i++) free(hw[i]);
  free(hw);

  return 0;
}
