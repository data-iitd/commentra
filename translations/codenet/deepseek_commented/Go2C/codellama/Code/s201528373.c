
#include <stdio.h>
 
int main() {
  // Declare variables to hold the number of elements, the target sum, and the list of integers
  int n;
  int x;
  int l[100];
  
  // Read the number of elements and the target sum from the standard input
  scanf("%d", &n);
  scanf("%d", &x);
  
  // Read n integers from the standard input and append them to the list l
  for (int i = 0; i < n; i ++) {
    int tmpL;
    scanf("%d", &tmpL);
    l[i] = tmpL;
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
  printf("%d\n", rs);
  
  return 0;
}

