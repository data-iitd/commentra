#include <stdio.h>
#define rep(S, L) for (int i = S; i < L; ++i)
int main() {
  int n, m; // 1. Input Reading: Declare variables to store the number of sets and the maximum element value.
  int k, a; // Declare variables to store the number of elements in each set and individual elements.
  int x[31] = {}; // 2. Array Initialization: Initialize an array to count occurrences of each element from 1 to 30.
  scanf("%d %d", &n, &m); // Read the number of sets and the maximum element value.
  for (int i = 0; i < n; ++i) { // 3. Nested Loops for Input: Loop through each set.
    scanf("%d", &k); // Read the number of elements in the current set.
    for (int j = 0; j < k; ++j) { // Loop through each element in the current set.
      scanf("%d", &a); // Read an element.
      x[a]++; // Increment the count of the element in the array x.
    }
  }
  int ans = 0; // 4. Counting Elements: Initialize a variable to store the count of elements that appear in every set.
  for (int i = 1; i <= m; ++i) { // Loop through each element from 1 to m.
    if (x[i] == n) { // Check if the element appears in every set.
      ans++; // Increment the count if the condition is met.
    }
  }
  printf("%d\n", ans); // 5. Output the Result: Print the final count of elements that appear in every set.
  return 0;
}
