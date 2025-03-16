#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int pow2(int a) {
  int ret = 1;
  for (int i = 0; i < a; i++) ret *= 2;
  return ret;
}

int count(int hw[][2], int a, int b) {
  int sum = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (a >> i & 1 && b >> j & 1 && hw[i][j] == 1) sum++;
    }
  }
  return sum;
}

int main() {
  int h, w, k; scanf("%d%d%d", &h, &w, &k);
  int hw[20][20] = {0};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c; scanf(" %c", &c);
      if (c == '#') hw[i][j] = 1;
    }
  }
  int sum = 0;
  for (int i = 0; i < pow2(h); i++) {
    for (int j = 0; j < pow2(w); j++) {
      if (count(hw, i, j) == k) sum++;
    }
  }
  printf("%d\n", sum);
}

