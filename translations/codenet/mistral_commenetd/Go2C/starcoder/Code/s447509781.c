#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main function
int main() {
  // Read the first integer from the input
  int n; scanf("%d",&n);

  // Read the second integer array from the input
  int *s = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++) { scanf("%d",&s[i]); }

  // Initialize a boolean array of size n
  bool *u = (bool *)malloc(n*sizeof(bool));

  // Initialize two integer variables m and f
  int m, f;

  // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for(int c=1;c<n-1;c++) {
    // Initialize a variable f to 0
    f = 0;

    // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for(int k=0;c<n-1-k*c;k++) {
      // Set the boolean value of the current index to true
      u[k*c] = true;

      // Check if the boolean value of the last index of the current subarray is already set to true
      // If it is, break the inner loop as we don't need to check further
      if(u[n-1-k*c]) { break; }

      // Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c];

      // Update the value of m if the current sum is greater than the previous maximum sum
      if(m < f) { m = f; }

      // Set all the boolean values of the current subarray to false
    }

    // Iterate through all the indices of the current subarray and set their boolean values to false
    for(int k=0;k*c<n-1;k++) { u[k*c] = false; }
  }

  // Print the maximum sum
  printf("%d",m);
}

// Define the Input struct and its methods for reading input
struct Input {
  int n;
  int *s;
};

// Define the Input struct and its methods for reading input ends here

