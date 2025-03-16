#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define INF 1000000000

bool debug=false; // Global variable to enable/disable debug mode

int main(){
  // Initialize variables
  int n, k, x, y;
  scanf("%d %d %d %d", &n, &k, &x, &y); // Read input values for n, k, x, and y from standard input

  int sum = 0; // Initialize sum variable to 0

  // Iterate through numbers from 1 to n
  for(int i=1;i<=n;i++){
    // If the current number i is greater than k, add y to the sum
    if(i>k)sum+=y;
    // Otherwise, add x to the sum
    else sum+=x;
  }

  // Output the final sum value to the standard output
  printf("%d\n", sum);

  return 0;
}
