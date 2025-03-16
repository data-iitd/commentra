
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Initialize scanner to read input from the standard input
  int N;
  scanf("%d", &N);

  // Initialize an integer array P of size N
  int *P = (int *)malloc(N * sizeof(int));

  // Read each element of P from the standard input and store it in the corresponding index of the array
  for (int i = 0; i < N; ++i)
    scanf("%d", &P[i]);

  // Create an empty HashMap to store the indices of the array P corresponding to each unique element
  int *map = (int *)malloc(N * sizeof(int));

  // Iterate through each element of the array P and add its index to the HashMap
  for (int i = 0; i < N; ++i)
    map[P[i]] = i;

  // Create an empty ArrayList to store the indices of the non-decreasing subsequences
  int *nglist = (int *)malloc(N * sizeof(int));

  // Iterate through each index i of the array P, where i < N - 1
  for (int i = 0; i < N - 1; ++i) {
    // If the index i corresponds to a smaller element than the next index, add its index to the ArrayList
    if (map[i] > map[i + 1])
      nglist[i] = i;
  }

  // If there are no non-decreasing subsequences, print 0 and exit the program
  if (nglist[0] == 0) {
    printf("0\n");
    return 0;
  }

  // Calculate the answer by finding the minimum length of a non-decreasing subsequence
  int ans = N - nglist[0] - 1;

  // Iterate through each pair of consecutive indices in the ArrayList nglist and update the answer if necessary
  for (int i = 0; i < N - 1; ++i) {
    ans = min(ans, nglist[i] + 1 + N - nglist[i + 1] - 1);
  }

  // Print the answer
  printf("%d\n", ans);

  // Free the memory allocated for the array P and the HashMap
  free(P);
  free(map);
  free(nglist);

  return 0;
}

