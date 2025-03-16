
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main(int argc, char **argv)
{
    // Declare an array to hold the input values and an array to store their indices
    long long a[200000];
    int ind_a[200000];

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
    int used_inds[200000];
    int used_inds_size = 0;
    long long ans = 0; // Variable to accumulate the final answer

    // Iterate through each element's index
    for(int i = 0; i < N; i++){
        int left_border; // Variable to store the left border index
        int right_border; // Variable to store the right border index
        int cur_ind = ind_a[i]; // Current index of the element being processed

        // Find the first used index that is not less than cur_ind
        int left_it = 0;
        int right_it = used_inds_size;
        while(left_it < right_it){
            int mid = (left_it + right_it) / 2;
            if(used_inds[mid] < cur_ind){
                left_it = mid + 1;
            } else {
                right_it = mid;
            }
        }
        left_border = (left_it == 0)? -1 : used_inds[left_it - 1]; // Set the left border to the found index

        // Find the first used index that is greater than cur_ind
        left_it = 0;
        right_it = used_inds_size;
        while(left_it < right_it){
            int mid = (left_it + right_it) / 2;
            if(used_inds[mid] <= cur_ind){
                left_it = mid + 1;
            } else {
                right_it = mid;
            }
        }
        right_border = (left_it == used_inds_size)? N : used_inds[left_it]; // Set the right border to the found index

        // Calculate the contribution of the current index to the answer
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

        // Uncomment the lines below for debugging purposes
        // printf("%d %d %d\n", i, left_border, right_border);
        // printf("%lld\n", ans);

        // Insert the current index into the set of used indices
        used_inds[used_inds_size++] = cur_ind;
    }

    // Output the final answer
    printf("%lld\n", ans);

    return 0;
}
