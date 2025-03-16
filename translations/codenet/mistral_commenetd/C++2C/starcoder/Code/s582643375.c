
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int X, Y; // Read input values for X and Y
  scanf("%d %d", &X, &Y);
  if((X+Y) % 3!= 0) { // Check if the sum of X and Y is not divisible by 3
    printf("0\n"); // If not, print 0 and exit
    return 0;
  }
  int n = (X+Y) / 3+1; // Calculate the value of n = (X+Y)/3 + 1
  int k = 2*(n-1) - Y + 1; // Calculate the value of k = 2*(n-1) - Y + 1
  printf("%d\n", C(n-1, k-1)); // Print the binomial coefficient C(n-1, k-1)
  return 0;
}

