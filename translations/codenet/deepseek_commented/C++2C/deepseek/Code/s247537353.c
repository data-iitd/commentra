#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function to check and update the minimum value of a variable
bool chmin(int* a, int b) {
  if (*a > b) {
    *a = b;
    return true;
  }
  return false;
}

// Function to check and update the maximum value of a variable
bool chmax(int* a, int b) {
  if (*a < b) {
    *a = b;
    return true;
  }
  return false;
}

// Define constants for maximum values
const int INF = (1 << 30) - 1;
const long long INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;

// Macro to iterate over all elements in a container
#define ALL(a) (a), (a) + (sizeof(a) / sizeof(*a))
#define rALL(a) (a), (a) + (sizeof(a) / sizeof(*a)) - 1
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  // Fast I/O setup
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);

  // Declare variables to store input values
  int A, B, C, K;
  scanf("%d %d %d %d", &A, &B, &C, &K);

  // Check if the sum of A and B is greater than or equal to K
  if (A + B >= K) {
    // Output the minimum of A and K
    printf("%d\n", A < K ? A : K);
  } else {
    // Calculate the result by subtracting the excess amount from A
    printf("%d\n", A - (K - (A + B)));
  }

  return 0;
}
