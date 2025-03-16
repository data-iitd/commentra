#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define long long type alias for convenience
typedef long long int lint;

// Constants for large values and mathematical constants
const lint INF = 1001001001001001LL;
const int inf = 1000000007;
const lint MOD = 1000000007LL;
const double PI = 3.1415926535897932;

// Function to update the minimum value
template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}

// Function to update the maximum value
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

// Macros for convenience in iterating through containers
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  // Read the number of elements
  int n; 
  scanf("%d", &n);

  // Initialize a vector to store the input values and a vector for prefix sums
  lint *a = (lint *)malloc(n * sizeof(lint));
  lint *acc = (lint *)malloc((n + 1) * sizeof(lint));

  // Read input values and compute prefix sums modulo MOD
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
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
  printf("%lld\n", ans);

  // Free memory
  free(a);
  free(acc);

  return 0; // End of the program
}

