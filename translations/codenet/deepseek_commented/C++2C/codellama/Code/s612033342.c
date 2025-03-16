#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Computes 2^a
int pow2(int a) {
  int ret = 1;
  for (int i = 0; i < a; i++) ret *= 2;
  return ret;
}

// Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
int count(int **hw, int a, int b) {
  int sum = 0;
  for (int i = 0; i < hw[0][0]; i++) {
    for (int j = 0; j < hw[0][1]; j++) {
      if (a >> i & 1 && b >> j & 1 && hw[i][j] == 1) sum++;
    }
  }
  return sum;
}

int main() {
  int h, w, k; scanf("%d %d %d", &h, &w, &k);
  
  // Initialize the grid with dimensions h x w, filled with 0s
  int **hw = (int **)malloc(h * sizeof(int *));
  for (int i = 0; i < h; i++) {
    hw[i] = (int *)malloc(w * sizeof(int));
    for (int j = 0; j < w; j++) hw[i][j] = 0;
  }
  
  // Read the grid and set 1s where there is a '#'
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c; scanf(" %c", &c);
      if (c == '#') hw[i][j] = 1;
    }
  }
  
  int sum = 0;
  
  // Iterate over all possible combinations of row and column selections
  for (int i = 0; i < pow2(h); i++) {
    for (int j = 0; j < pow2(w); j++) {
      if (count(hw, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
    }
  }
  
  // Output the result
  printf("%d\n", sum);
  
  // Free the memory
  for (int i = 0; i < h; i++) free(hw[i]);
  free(hw);
  
  return 0;
}

