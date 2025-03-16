#######
// Import necessary libraries
#######
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Read input values for n and m
  int n = atoi(scanf("%d", &n));
  int m = atoi(scanf("%d", &m));

  // Calculate the greatest common divisor (GCD) of n and m
  int gcd = __gcd(n, m);

  // Read input strings s and t
  char s[100000];
  char t[100000];
  scanf("%s", s);
  scanf("%s", t);

  // Perform the required calculation and print the result
  long result = 0;
  for (int k = 0; k < gcd; k++) {
    if (s[k * n / gcd]!= t[k * m / gcd]) {
      result = -1;
      break;
    }
  }
  if (result == 0) {
    result = n * m / gcd;
  }

  // Print the result
  printf("%ld", result);
}

