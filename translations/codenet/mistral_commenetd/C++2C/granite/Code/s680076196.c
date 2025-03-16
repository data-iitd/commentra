
#include <stdio.h>   // Include input/output library
#include <stdlib.h>  // Include standard library functions
#include <math.h>    // Include mathematical functions library

typedef long long ll; // Define a new type alias for long long int

int main(){
  // Declare variables a, b, c, and d of type int
  int a, b, c, d;

  // Read values of variables a, b, c, and d from standard input
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Calculate the difference between a and c, and the difference between b and d
  ll difference_ab = (ll)a - (ll)c;
  ll difference_cd = (ll)b - (ll)d;

  // Multiply the differences and print the result to standard output
  printf("%lld\n", difference_ab * difference_cd);

  return 0; // Return 0 to indicate successful program execution
}
