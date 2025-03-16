#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  long long x, y;
  scanf("%lld %lld", &x, &y);  // Read two integers from standard input
  if(abs(x-y) <= 1) printf("Brown\n");  // Check if the absolute difference is less than or equal to 1
  else printf("Alice\n");  // Otherwise, print "Alice"
}

