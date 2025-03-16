#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 200000

long long a[MAX_N]; // Array to store the elements
int ind_a[MAX_N]; // Array to store the indices of elements in array a

int main(){
  int N;
  scanf("%d", &N); // Read the number of elements
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]); // Read the elements into array a
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
  }

  int used_inds[MAX_N]; // Set to keep track of used indices
  long long ans = 0; // Variable to store the final answer
  for(int i = 0; i < N; i++){
    long long left_border; // Variable to store the left boundary
    long long right_border; // Variable to store the right boundary
    long long cur_ind = ind_a[i]; // Current index of the element being processed
    int left_it = 0; // Iterator to the lower bound of cur_ind in used_inds
    int right_it = 0; // Iterator to the lower bound of cur_ind + 1 in used_inds

    while(left_it < N && used_inds[left_it] < cur_ind){
      left_it ++; // Adjust left_it if it points to an element less than cur_ind
    }
    if(left_it == 0){
      left_border = -1; // If left_it is the first element, set left_border to -1
    } else {
      left_border = used_inds[left_it - 1]; // Set left_border to the value pointed by left_it
    }
    while(right_it < N && used_inds[right_it] <= cur_ind){
      right_it ++; // Adjust right_it if it points to an element less than or equal to cur_ind
    }
    if(right_it == N){
      right_border = N; // If right_it is the end, set right_border to N
    } else {
      right_border = used_inds[right_it]; // Set right_border to the value pointed by right_it
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

    // Debugging output (commented out)
    //printf("%d %lld %lld\n", i, left_border, right_border);
    //printf("%lld\n", ans);

    used_inds[i] = cur_ind; // Insert the current index into the set used_inds
  }

  printf("%lld\n", ans); // Output the final answer
  return 0;
}

