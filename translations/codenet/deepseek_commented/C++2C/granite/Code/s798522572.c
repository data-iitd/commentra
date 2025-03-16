
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
  int N, T;
  scanf("%d %d", &N, &T); // Reading the number of elements and a threshold value
  int A[N]; // Declaring an array to store the elements
  int B[N]; // Declaring an array to store the differences
  int i;
  for(i = 0; i < N; i++) scanf("%d", &A[i]); // Reading the elements into the array

  // Initializing the minimum value with the first element of A
  int m = A[0];
  // Calculating the difference between the second element and the initial minimum, and storing it in B[1]
  B[1] = A[1] - m;
  // Updating the minimum value to be the minimum of its current value and the second element of A
  m = (m < A[1])? m : A[1];
  // For each subsequent element in A, calculate the difference, update the minimum, and store the difference in B
  for(i = 2; i < N; i++){
    B[i] = A[i] - m;
    m = (m < A[i])? m : A[i];
  }

  // Finding the maximum value in B
  int max_value = INT_MIN;
  for(i = 0; i < N; i++) max_value = (max_value > B[i])? max_value : B[i];
  // Counting how many times the maximum value appears in B
  int count = 0;
  for(i = 0; i < N; i++) if(B[i] == max_value) count++;
  printf("%d\n", count);
}
