
#include <stdio.h>

int main(){
  long long A, B, C, K; // Declare variables for input
  scanf("%lld %lld %lld %lld", &A, &B, &C, &K); // Read input values for A, B, C, and K

  // Check if the sum of A and B is greater than or equal to K
  if (A + B >= K) {
    // If true, output the minimum of A and K
    printf("%lld\n", A < K? A : K);
  } else {
    // If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
    printf("%lld\n", A - (K - (A + B)));
  }
}


