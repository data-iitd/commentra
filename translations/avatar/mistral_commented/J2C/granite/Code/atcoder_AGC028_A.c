
#####
// Include necessary libraries
#####
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Read input values for n and m
  int n, m;
  scanf("%d %d", &n, &m);

  // Calculate the greatest common divisor (GCD) of n and m
  int gcd = (int)gcd((double)n, (double)m);

  // Read input strings s and t
  char s[100001], t[100001];
  scanf("%s %s", s, t);

  // Perform the required calculation and print the result
  long result = -1;
  for (int k = 0; k < gcd; k++) {
    if (s[k * n / gcd]!= t[k * m / gcd]) {
      result = -1;
      break;
    }
  }
  if (result == -1) {
    result = (long)n * m / gcd;
  }

  // Print the result
  printf("%ld\n", result);

  return 0;
}
