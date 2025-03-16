

#include <stdio.h>
#include <stdlib.h>

int main() {

  // Read the number of elements in the array P from the standard input
  int N;
  scanf("%d", &N);

  // Initialize an integer array P of size N
  int P[N];

  // Read each element of P from the standard input and store it in the corresponding index of the array
  for (int i = 0; i < N; ++i)
    scanf("%d", &P[i]);

  // Create an empty HashMap to store the indices of the array P corresponding to each unique element
  int* map = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; ++i)
    map[P[i] - 1] = i;

  // Create an empty ArrayList to store the indices of the non-decreasing subsequences
  int* nglist = (int*)malloc(sizeof(int) * N);
  int nglist_size = 0;

  // Iterate through each index i of the array P, where i < N - 1
  for (int i = 0; i < N - 1; ++i) {
    // If the index i corresponds to a smaller element than the next index, add its index to the ArrayList
    if (map[i] > map[i + 1])
      nglist[nglist_size++] = i;
  }

  // If there are no non-decreasing subsequences, print 0 and exit the program
  if (nglist_size == 0) {
    printf("0\n");
    return 0;
  }

  // Calculate the answer by finding the minimum length of a non-decreasing subsequence
  int ans = nglist[0] + 1 < N - nglist[nglist_size - 1] - 1? nglist[0] + 1 : N - nglist[nglist_size - 1] - 1;

  // Iterate through each pair of consecutive indices in the ArrayList nglist and update the answer if necessary
  for (int i = 0; i < nglist_size - 1; ++i) {
    ans = nglist[i] + 1 + N - nglist[i + 1] - 1 < ans? nglist[i] + 1 + N - nglist[i + 1] - 1 : ans;
  }

  // Print the answer
  printf("%d\n", ans);

  // Free the allocated memory for the HashMap and ArrayList
  free(map);
  free(nglist);

  return 0;
}

