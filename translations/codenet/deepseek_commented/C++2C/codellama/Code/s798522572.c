#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int N, T;
  scanf("%d %d", &N, &T); // Reading the number of elements and a threshold value
  int A[N]; // Declaring an array to store the elements
  int *B = (int *)malloc(N * sizeof(int)); // Declaring a vector to store the differences
  for(int i = 0; i < N; i++) scanf("%d", &A[i]); // Reading the elements into the array

  // Initializing the minimum value with the first element of A
  int m = A[0];
  // Calculating the difference between the second element and the initial minimum, and storing it in B[1]
  B[1] = A[1] - m;
  // Updating the minimum value to be the minimum of its current value and the second element of A
  m = min(m, A[1]);
  // For each subsequent element in A, calculate the difference, update the minimum, and store the difference in B
  for(int i = 2; i < N; i++){
    B[i] = A[i] - m;
    m = min(m, A[i]);
  }

  // Finding the maximum value in B
  int max_value = *max_element(B, B + N);
  // Counting how many times the maximum value appears in B
  printf("%d\n", count(B, B + N, max_value));

  // Freeing the memory allocated for B
  free(B);

  return 0;
}

