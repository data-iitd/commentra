#include <stdio.h>
#include <stdlib.h>

int pow2(int a) {
  int ret = 1;
  for (int i = 0; i < a; i++) ret *= 2;
  return ret;
}

int count(int** hw, int h, int w, int a, int b) {
  int sum = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((a & (1 << i)) && (b & (1 << j)) && hw[i][j] == 1) sum++;
    }
  }
  return sum;
}

int main() {
  int h, w, k; 
  scanf("%d %d %d", &h, &w, &k);
  int** hw = (int**)malloc(h * sizeof(int*));
  for (int i = 0; i < h; i++) {
    hw[i] = (int*)malloc(w * sizeof(int));
    for (int j = 0; j < w; j++) {
      char c; 
      scanf(" %c", &c);
      if (c == '#') hw[i][j] = 1;
      else hw[i][j] = 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < pow2(h); i++) {
    for (int j = 0; j < pow2(w); j++) {
      if (count(hw, h, w, i, j) == k) sum++;
    }
  }
  printf("%d\n", sum);
  for (int i = 0; i < h; i++) {
    free(hw[i]);
  }
  free(hw);
}
