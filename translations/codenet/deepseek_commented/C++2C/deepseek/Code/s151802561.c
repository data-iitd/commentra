#include <stdio.h>

int main() {
  int A[100], n, i, j, t, sw = 0, mini;

  // Step 1: Reading the number of elements (n)
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  // Step 2: Reading the elements of the array
  // Step 3: Selection Sort Implementation
  for (i = 0; i < n; i++) {
    mini = i;
    // Find the index of the minimum element in the unsorted part of the array
    for (j = i; j < n; j++) {
      if (A[j] < A[mini]) mini = j;
    }
    // Swap the found minimum element with the first element of the unsorted part
    t = A[i]; A[i] = A[mini]; A[mini] = t;
    // Increment the swap counter if a swap was made
    if (i != mini) sw++;
  }

  // Step 4: Counting the number of swaps
  // Step 5: Printing the sorted array
  for (i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  // Step 6: Printing the number of swaps
  printf("%d\n", sw);

  return 0;
}
