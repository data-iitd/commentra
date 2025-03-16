#include<stdio.h>
#include<stdlib.h>

void run(void){
  // Read the number of elements (n) and the target value (k)
  int n, k;
  scanf("%d%d", &n, &k);
  
  // Declare an array to store the elements
  int a[100];
  
  // Declare loop variables
  int i, j;
  
  // Read n elements into the array a
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  // Allocate memory for the dynamic programming array dp
  int *dp = (int *)calloc(k + 1, sizeof(int));
  
  // Iterate from 1 to k to fill the dp array
  for (i = 1; i <= k; i++) {
    // Initialize the win flag to 0
    int win = 0;
    
    // Check each element in the array a to see if it can be subtracted from i
    for (j = 0; j < n && a[j] <= i; j++) {
      if (dp[i - a[j]] == 0) {
        // If the resulting value is zero, set win to 1
        win = 1;
      }
    }
    
    // Set dp[i] to the win flag
    dp[i] = win;
  }
  
  // Print the result based on the value of dp[k]
  printf("%s\n", dp[k] ? "First" : "Second");
}

int main(void){
  // Call the run function to execute the game strategy
  run();
  return 0;
}
