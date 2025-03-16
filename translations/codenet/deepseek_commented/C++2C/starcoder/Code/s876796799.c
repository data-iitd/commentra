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
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

int main(){
  int N;
  scanf("%d", &N); // Read the number of elements
  int a[200000]; // Array to store the elements
  int ind_a[200000]; // Array to store the indices of elements in array a
  for(int i = 0; i < N; i++){
    scanf("%d", &a[i]); // Read the elements into array a
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
  }

  int used_inds[200000]; // Array to keep track of used indices
  int used_inds_size = 0; // Variable to keep track of the size of used_inds
  int ans = 0; // Variable to store the final answer
  for(int i = 0; i < N; i++){
    int left_border; // Variable to store the left boundary
    int right_border; // Variable to store the right boundary
    int cur_ind = ind_a[i]; // Current index of the element being processed
    int left_it = 0; // Iterator to the lower bound of cur_ind in used_inds
    int right_it = used_inds_size; // Iterator to the lower bound of cur_ind + 1 in used_inds

    if(left_it == 0){
      left_border = -1; // If left_it is the first element, set left_border to -1
    } else {
      if(left_it == used_inds_size || used_inds[left_it] > cur_ind){
        left_it --; // Adjust left_it if it points to an element greater than cur_ind
      }
      left_border = used_inds[left_it]; // Set left_border to the value pointed by left_it
    }
    if(right_it == used_inds_size){
      right_border = N; // If right_it is the end, set right_border to N
    } else {
      right_border = used_inds[right_it]; // Set right_border to the value pointed by right_it
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

    // Debugging output (commented out)
    //printf("%d %d %d\n", i, left_border, right_border);
    //printf("%d\n", ans);

    used_inds[used_inds_size] = cur_ind; // Insert the current index into the array used_inds
    used_inds_size ++; // Increment the size of used_inds
  }

  printf("%d\n", ans); // Output the final answer
  return 0;
}

