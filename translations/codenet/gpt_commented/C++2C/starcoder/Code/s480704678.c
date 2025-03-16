#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define long long type alias for convenience
typedef long long int lint;

// Constants for large values and mathematical constants
#define INF 1001001001001001LL
#define inf 1000000007
#define MOD 1000000007LL
#define PI 3.1415926535897932

// Function to update the minimum value
#define chmin(a,b) if(a>b) a=b

// Function to update the maximum value
#define chmax(a,b) if(a<b) a=b

// Macros for convenience in iterating through containers
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  // Read the number of elements
  int n; 
  scanf("%d", &n);

  // Initialize a vector to store the input values and a vector for prefix sums
  lint a[n];
  lint acc[n + 1];

  // Read input values and compute prefix sums modulo MOD
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    acc[i + 1] = acc[i] + a[i]; // Update prefix sum
    acc[i + 1] %= MOD; // Ensure the prefix sum is within MOD
  }

  // Initialize the answer variable
  lint ans = 0;

  // Calculate the final answer using the prefix sums
  for (int i = 0; i < n; i++) {
    ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD; // Update answer based on current element and remaining sum
    ans %= MOD; // Ensure the answer is within MOD
  }

  // Output the final result
  printf("%d\n", ans);

  return 0; // End of the program
}

