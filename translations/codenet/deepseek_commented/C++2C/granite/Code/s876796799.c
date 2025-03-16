
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

int main(){
  int N;
  scanf("%d", &N); // Read the number of elements
  ll a[N]; // Array to store the elements
  int ind_a[N]; // Array to store the indices of elements in array a
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]); // Read the elements into array a
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
  }

  int used_inds[N]; // Array to keep track of used indices
  memset(used_inds, 0, sizeof(used_inds)); // Initialize used_inds with zeros
  ll ans = 0; // Variable to store the final answer
  for(int i = 0; i < N; i++){
    int left_border; // Variable to store the left boundary
    int right_border; // Variable to store the right boundary
    int cur_ind = ind_a[i]; // Current index of the element being processed
    int left_it = 0; // Iterator to the lower bound of cur_ind in used_inds
    int right_it = 0; // Iterator to the lower bound of cur_ind + 1 in used_inds
    while(left_it < N && used_inds[left_it] <= cur_ind){
      left_it ++; // Increment left_it until used_inds[left_it] > cur_ind
    }
    left_border = left_it - 1; // Set left_border to the value of left_it - 1
    while(right_it < N && used_inds[right_it] < cur_ind + 1){
      right_it ++; // Increment right_it until used_inds[right_it] >= cur_ind + 1
    }
    right_border = right_it; // Set right_border to the value of right_it
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((ll)i + 1); // Calculate the contribution of the current element to the answer

    // Debugging output (commented out)
    //printf("%d %d %d\n", i, left_border, right_border);
    //printf("%lld\n", ans);

    used_inds[cur_ind] = 1; // Insert the current index into the array used_inds
  }

  printf("%lld\n", ans); // Output the final answer
  return 0;
}

