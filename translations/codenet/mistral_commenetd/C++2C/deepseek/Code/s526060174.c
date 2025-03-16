#include <stdio.h>

int main() {
  int n, m; // Declare variables n and m for input size
  int k, a; // Declare variables k and a for intermediate calculations
  int x[31] = {}; // Initialize an array x of size 31 with zeros

  // Read input values for n and m
  scanf("%d %d", &n, &m);

  // Process each input value for n times
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k); // Read the number of elements in the current input

    // Process each element in the current input
    for (int j = 0; j < k; ++j) {
      scanf("%d", &a); // Read the value of the current element
      x[a]++; // Increment the count of the current value in the array x
    }
  }

  // Initialize answer variable to zero
  int ans = 0;

  // Check each value from 1 to m and increment the answer if the count is equal to n
  for (int i = 1; i <= m; ++i) {
    if (x[i] == n) { // Check if the count of the current value is equal to n
      ans++; // Increment the answer if true
    }
  }

  // Output the final answer
  printf("%d\n", ans);

  return 0;
}

