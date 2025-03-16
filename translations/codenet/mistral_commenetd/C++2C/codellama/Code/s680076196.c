#include <stdio.h>   // Include input/output library
#include <stdlib.h>  // Include standard library
#include <math.h>    // Include mathematical functions library

int main(){
  // Declare variables a, b, c, and d of type int
  int a, b, c, d;

  // Read values of variables a, b, c, and d from standard input
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Calculate the difference between a and c, and the difference between b and d
  long long difference_ab = (long long)a - (long long)c;
  long long difference_cd = (long long)b - (long long)d;

  // Multiply the differences and print the result to standard output
  printf("%lld\n", difference_ab * difference_cd);
}

