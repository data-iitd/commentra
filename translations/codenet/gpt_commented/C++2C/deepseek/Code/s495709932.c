#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
  // Optimize input/output operations
  setvbuf(stdout, NULL, _IONBF, 0);
  
  // Read the number of elements in the array
  int N;
  scanf("%d", &N);
  
  // Initialize an array to store the elements
  int64_t A[N];
  
  // Read the elements into the array
  rep(i, N) scanf("%lld", &A[i]);

  // Initialize a variable to keep track of the maximum difference
  int64_t answer = 0;
  
  // Iterate through all pairs of elements to find the maximum difference
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      // Calculate the absolute difference between the two elements
      int64_t diff = abs(A[i] - A[j]);
      
      // Update the maximum difference found so far
      if (diff > answer) {
        answer = diff;
      }
    }
  }
  
  // Output the maximum difference
  printf("%lld\n", answer);
  
  return 0;
}
