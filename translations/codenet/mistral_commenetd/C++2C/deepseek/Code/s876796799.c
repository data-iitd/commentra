#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize an array 'a' of size N and an array 'ind_a' of size N
long long a[200000];
int ind_a[200000];

int main(){
  int N; // Read the number of elements N from the standard input
  scanf("%d", &N);

  // Read N elements from the standard input and store them in the array 'a'
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]);
  }

  // Initialize an empty set 'used_inds' to keep track of indices already used
  int *used_inds = (int *)malloc(N * sizeof(int));
  int used_size = 0;

  long long ans = 0; // Initialize an answer variable 'ans' to 0

  // Iterate through each index i from 0 to N-1
  for(int i = 0; i < N; i++){
    long long left_border; // Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
    long long right_border;

    int cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

    // Find the index of the left neighbor of the current index i in the set 'used_inds'
    int left_border_ind = -1;
    for(int j = used_size - 1; j >= 0; j--){
      if(used_inds[j] < cur_ind){
        left_border_ind = used_inds[j];
        break;
      }
    }

    // If the left neighbor does not exist, set 'left_border' to -1
    left_border = left_border_ind;

    // Find the index of the right neighbor of the current index i in the set 'used_inds'
    int right_border_ind = N;
    for(int j = used_size; j < N; j++){
      if(used_inds[j] > cur_ind){
        right_border_ind = used_inds[j];
        break;
      }
    }
    right_border = right_border_ind;

    // Calculate the contribution of the current index i to the answer 'ans'
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

    // Insert the index of the current element a[i] into the set 'used_inds'
    used_inds[used_size++] = cur_ind;
    // Sort the array 'used_inds' to maintain order
    for(int j = used_size - 1; j > 0 && used_inds[j] < used_inds[j - 1]; j--){
      int temp = used_inds[j];
      used_inds[j] = used_inds[j - 1];
      used_inds[j - 1] = temp;
    }

    // Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
    // printf("%d %lld %lld\n", i, left_border, right_border);
    // printf("%lld\n", ans);
  }

  // Print the final answer 'ans' to the standard output
  printf("%lld\n", ans);

  // Free the allocated memory for 'used_inds'
  free(used_inds);

  // Return 0 to indicate successful execution of the program
  return 0;
}
