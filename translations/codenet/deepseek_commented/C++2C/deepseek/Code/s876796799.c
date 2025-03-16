#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a[200000]; // Array to store the elements
int ind_a[200000]; // Array to store the indices of elements in array a

int main(){
  int N;
  scanf("%d", &N); // Read the number of elements
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]); // Read the elements into array a
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
  }

  int* used_inds = (int*)malloc(N * sizeof(int)); // Allocate memory for the set used_inds
  int used_size = 0; // Initialize the size of the set used_inds
  long long ans = 0; // Variable to store the final answer
  for(int i = 0; i < N; i++){
    long long left_border; // Variable to store the left boundary
    long long right_border; // Variable to store the right boundary
    int cur_ind = ind_a[i]; // Current index of the element being processed
    int left_it = used_size; // Initialize left_it to the size of used_inds
    int right_it = used_size; // Initialize right_it to the size of used_inds

    // Find the position of cur_ind in used_inds
    for(int j = 0; j < used_size; j++){
      if(used_inds[j] > cur_ind){
        right_it = j;
        break;
      }
      if(used_inds[j] == cur_ind){
        right_it = j + 1;
        break;
      }
      left_it = j;
    }

    if(left_it == -1){
      left_border = -1; // If left_it is -1, set left_border to -1
    } else {
      left_border = used_inds[left_it]; // Set left_border to the value at left_it
    }
    if(right_it == used_size){
      right_border = N; // If right_it is the end, set right_border to N
    } else {
      right_border = used_inds[right_it]; // Set right_border to the value at right_it
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

    // Debugging output (commented out)
    //printf("%d %lld %lld\n", i, left_border, right_border);
    //printf("%lld\n", ans);

    // Insert cur_ind into used_inds
    if(right_it == used_size){
      used_inds[used_size++] = cur_ind;
    } else {
      for(int j = used_size; j > right_it; j--){
        used_inds[j] = used_inds[j - 1];
      }
      used_inds[right_it] = cur_ind;
      used_size++;
    }
  }

  printf("%lld\n", ans); // Output the final answer
  free(used_inds); // Free the allocated memory
  return 0;
}
