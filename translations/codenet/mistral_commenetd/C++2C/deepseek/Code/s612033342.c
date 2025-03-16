#include <stdio.h>
#include <stdlib.h>

// Function to calculate 2 raised to the power of a given number
int pow2(int a) {
  int ret = 1; // Initialize result to 1
  for (int i = 0; i < a; i++) ret *= 2; // Multiply result by 2 for each iteration of the loop
  return ret; // Return the final result
}

// Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
int count(int** hw, int h, int w, int a, int b) {
  int sum = 0; // Initialize sum to 0
  for (int i = 0; i < h; i++) { // Iterate through each row of the 2D grid
    for (int j = 0; j < w; j++) { // Iterate through each column of the current row
      if ((a & (1 << i)) && (b & (1 << j)) && hw[i][j] == 1) sum++; // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
    }
  }
  return sum; // Return the final sum
}

int main() {
  int h, w, k; // Declare variables for height, width, and target count
  scanf("%d %d %d", &h, &w, &k); // Read input values for height, width, and target count from standard input
  int** hw = (int**)malloc(h * sizeof(int*)); // Allocate memory for 2D grid
  for (int i = 0; i < h; i++) {
    hw[i] = (int*)malloc(w * sizeof(int)); // Allocate memory for each row
    for (int j = 0; j < w; j++) {
      char c; // Declare a variable to store the current character from input
      scanf(" %c", &c); // Read the character from standard input
      if (c == '#') hw[i][j] = 1; // If the character is '#', set the corresponding cell in the grid to 1
      else hw[i][j] = 0; // Otherwise, set the corresponding cell in the grid to 0
    }
  }
  int sum = 0; // Initialize sum to 0
  for (int i = 0; i < pow2(h); i++) { // Iterate through all possible binary combinations of height
    for (int j = 0; j < pow2(w); j++) { // Iterate through all possible binary combinations of width
      if (count(hw, h, w, i, j) == k) sum++; // If the number of 1's in the current combination matches the target count, increment sum
    }
  }
  printf("%d\n", sum); // Output the final sum to standard output

  // Free allocated memory
  for (int i = 0; i < h; i++) {
    free(hw[i]); // Free each row
  }
  free(hw); // Free the 2D grid

  return 0;
}
