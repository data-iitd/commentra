#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

// Declare an array to hold the input values and an array to store their indices
long long a[200000];
int ind_a[200000];

int main(){
  // Read the number of elements
  int N;
  scanf("%d", &N);

  // Input the elements into array 'a'
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]);
  }

  // Populate 'ind_a' with the indices of the elements in 'a'
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Store the index of each element based on its value
  }

  // Set to keep track of used indices
  set <int> used_inds;
  long long ans = 0; // Variable to accumulate the final answer

  // Iterate through each element's index
  for(int i = 0; i < N; i++){
    long long left_border; // Variable to store the left border index
    long long right_border; // Variable to store the right border index
    long long cur_ind = ind_a[i]; // Current index of the element being processed

    // Find the first used index that is not less than cur_ind
    auto left_it = used_inds.lower_bound(cur_ind);
    // Find the first used index that is greater than cur_ind
    auto right_it = used_inds.lower_bound(cur_ind + 1);

    // Determine the left border
    if(left_it == used_inds.begin()){
      left_border = -1; // No used index to the left
    } else {
      if(left_it == used_inds.end() || *left_it > cur_ind){
        left_it--; // Move to the previous index
      }
      left_border = *left_it; // Set the left border to the found index
    }

    // Determine the right border
    if(right_it == used_inds.end()){
      right_border = N; // No used index to the right
    } else {
      right_border = *right_it; // Set the right border to the found index
    }

    // Calculate the contribution of the current index to the answer
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

    // Uncomment the lines below for debugging purposes
    // printf("%d %lld %lld\n", i, left_border, right_border);
    // printf("%lld\n", ans);

    // Insert the current index into the set of used indices
    used_inds.insert(cur_ind);
  }

  // Output the final answer
  printf("%lld\n", ans);
  return 0;
}
