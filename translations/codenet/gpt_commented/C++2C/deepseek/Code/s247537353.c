#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function to update the value of 'a' to 'b' if 'b' is less than 'a'
bool chmin(int* a, int b) {
  if (*a > b) {
    *a = b; // Update 'a' to 'b'
    return true; // Indicate that 'a' was changed
  }
  return false; // Indicate that 'a' was not changed
}

// Function to update the value of 'a' to 'b' if 'b' is greater than 'a'
bool chmax(int* a, int b) {
  if (*a < b) {
    *a = b; // Update 'a' to 'b'
    return true; // Indicate that 'a' was changed
  }
  return false; // Indicate that 'a' was not changed
}

// Constants for infinity and modulo operations
const int INF = (1 << 30) - 1; // Integer infinity
const long long INFLL = (1LL << 61) - 1; // Long long infinity
const int MOD = 1000000007; // Modulo value for calculations

// Macros for convenience in iterating and accessing containers
#define ALL(a) (a), (a) + (sizeof(a) / sizeof(*a)) // Macro to access all elements of a container
#define rALL(a) (a), (a) + (sizeof(a) / sizeof(*a)) - 1 // Macro to access all elements in reverse order
#define FOR(i, a, b) for(int i = (a); i < (b); ++i) // Macro for a for-loop from a to b
#define REP(i, n) FOR(i, 0, n) // Macro for a for-loop from 0 to n

int main() {
  int A, B, C, K; // Declare variables for input
  scanf("%d %d %d %d", &A, &B, &C, &K); // Read input values for A, B, C, and K

  // Check if the sum of A and B is greater than or equal to K
  if (A + B >= K) {
    // If true, output the minimum of A and K
    printf("%d\n", A < K ? A : K);
  } else {
    // If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
    printf("%d\n", A - (K - (A + B)));
  }
}
