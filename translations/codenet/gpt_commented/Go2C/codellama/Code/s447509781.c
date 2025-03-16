#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize input reader with a buffer size of 1,000,000 bytes
struct Input {
  char buffer[1000000];
  char *cursor;
  char *limit;
};

// Read the number of elements and the array of integers from input
int n;
int *s;

// Create a boolean slice to track used indices
int *u;

// Initialize variables to store the maximum sum and a temporary sum
long long m, f;

// Iterate through possible values of c from 1 to n-2
for (int c = 1; c < n-1; c++) {
  f = 0; // Reset the temporary sum for each c
  
  // Iterate to find pairs of indices based on the current value of c
  for (int k = 0; c < n-1-k*c; k++) {
    u[k*c] = 1; // Mark the current index as used
    
    // Break if the corresponding index is already used
    if (u[n-1-k*c]) { break; }
    
    // Calculate the sum of the elements at the current indices
    f += s[n-1-k*c] + s[k*c];
    
    // Update the maximum sum if the current sum is greater
    if (m < f) { m = f; }
  }
  
  // Reset the used indices for the next iteration of c
  for (int k = 0; k*c < n-1; k++) { u[k*c] = 0; }
}

// Print the maximum sum found
printf("%lld\n", m);

