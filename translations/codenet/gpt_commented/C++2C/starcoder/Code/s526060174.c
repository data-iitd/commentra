#include <stdio.h>
#define rep(S, L) for (int i = S; i < L; ++i)

int main() {
  // Declare variables for the number of groups (n) and the maximum number (m)
  int n, m;
  // Declare variables for the number of elements in each group (k) and the individual element (a)
  int k, a;
  // Array to count occurrences of each number from 1 to m
  int x[31] = {};
  
  // Read the number of groups (n) and the maximum number (m)
  scanf("%d %d", &n, &m);

  // Loop through each group
  rep(0, n) {
    // Read the number of elements in the current group
    scanf("%d", &k);
    // Loop through each element in the current group
    rep(0, k) {
      // Read the element and increment its count in the array
      scanf("%d", &a);
      x[a]++;
    }
  }

  // Initialize the answer variable to count how many numbers appear in all groups
  int ans = 0;
  
  // Check each number from 1 to m
  rep(1, m + 1) {
    // If the number appears in all n groups, increment the answer
    if (x[i] == n) {
      ans++;
    }
  }

  // Output the final count of numbers that appeared in all groups
  printf("%d\n", ans);
  
  return 0; // End of the program
}
