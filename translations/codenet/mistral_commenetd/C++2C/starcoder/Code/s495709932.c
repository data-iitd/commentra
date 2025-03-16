
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#define rep(i, n) for (int i = 0; i < (n); i++) // Define a shorthand for repetition

int main(void) {
  // Read the number of elements in the vector
  int N;
  scanf("%d", &N);

  // Initialize a vector of size N with integers
  int A[N];
  rep(i, N) { // Iterate through each element in the vector and read its value
    scanf("%d", &A[i]);
  }

  // Initialize the answer variable to 0
  int64_t answer = 0;

  // Outer loop iterates through each element in the vector except the last one
  for (int i = 0; i < N - 1; ++i) {
    // Inner loop iterates through the remaining elements in the vector starting from the next element
    for (int j = i + 1; j < N; ++j) {
      // Calculate the absolute difference between the current and next elements
      int64_t diff = abs(A[i] - A[j]);

      // Update the answer variable with the maximum difference found so far
      answer = max(answer, diff);
    }
  }

  // Print the answer
  printf("%d\n", answer);

  return 0;
}

