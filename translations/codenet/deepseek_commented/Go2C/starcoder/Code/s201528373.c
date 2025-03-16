
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
  // Declare variables to hold the number of elements, the target sum, and the list of integers
  int n, x;
  int *l;
  
  // Read the number of elements and the target sum from the standard input
  scanf("%d", &n);
  scanf("%d", &x);
  
  // Read n integers from the standard input and append them to the list l
  l = (int *) malloc(n * sizeof(int));
  for (int i = 0; i < n; i ++) {
    scanf("%d", &l[i]);
  }
  
  // Initialize variables to keep track of the sum and the result
  int tmpSum = 0;
  int rs = 0;
  
  // Iterate over the list l, updating the sum and checking the condition
  for (int i = 0; i < n; i ++) {
    tmpSum += l[i];
    // If the sum is less than or equal to x, update the result
    if (tmpSum <= x) {
      rs = i + 2;
    } else if (tmpSum > x) {
      break;
    }
  }
  
  // Print the result
  printf("%d", rs);
  
  // Free the memory allocated for the list l
  free(l);
  
  return 0;
}

