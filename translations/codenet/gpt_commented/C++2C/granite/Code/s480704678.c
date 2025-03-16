
#include <stdio.h>

// Define long long type alias for convenience
typedef long long lint;

// Constants for large values and mathematical constants
lint MOD = 1000000007LL;

int main() {
  
  // Read the number of elements
  int n; 
  scanf("%d", &n);

  // Initialize a vector to store the input values and a vector for prefix sums
  lint a[n];
  lint acc[n + 1] = {0};

  // Read input values and compute prefix sums modulo MOD
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    acc[i + 1] = (acc[i] + a[i]) % MOD; // Update prefix sum
  }

  // Initialize the answer variable
  lint ans = 0;

  // Calculate the final answer using the prefix sums
  for (int i = 0; i < n; i++) {
    ans = (ans + a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD) % MOD; // Update answer based on current element and remaining sum
  }

  // Output the final result
  printf("%lld\n", ans);

  return 0; // End of the program
}


