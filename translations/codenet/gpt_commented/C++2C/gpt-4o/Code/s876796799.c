#include <stdio.h>
#include <stdlib.h>

long long a[200000];
int ind_a[200000];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Input the elements into array 'a'
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }

    // Populate 'ind_a' with the indices of the elements in 'a'
    for (int i = 0; i < N; i++) {
        ind_a[a[i] - 1] = i; // Store the index of each element based on its value
    }

    // Array to keep track of used indices
    int *used_inds = (int *)malloc(N * sizeof(int));
    int used_count = 0; // Count of used indices
    long long ans = 0; // Variable to accumulate the final answer

    // Iterate through each element's index
    for (int i = 0; i < N; i++) {
        long long left_border; // Variable to store the left border index
        long long right_border; // Variable to store the right border index
        long long cur_ind = ind_a[i]; // Current index of the element being processed

        // Find the first used index that is not less than cur_ind
<<<<<<< HEAD
        int left_it = -1; // Initialize left iterator
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] >= cur_ind) {
                left_it = j;
                break;
            }
        }

        // Find the first used index that is greater than cur_ind
        int right_it = -1; // Initialize right iterator
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] > cur_ind) {
                right_it = j;
=======
        int left_it = -1;
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] >= cur_ind) {
                left_it = j - 1; // Move to the previous index
>>>>>>> 98c87cb78a (data updated)
                break;
            }
        }

        // Determine the left border
        if (left_it == -1) {
            left_border = -1; // No used index to the left
        } else {
<<<<<<< HEAD
            left_border = used_inds[left_it - 1]; // Set the left border to the found index
        }

        // Determine the right border
        if (right_it == -1) {
=======
            left_border = used_inds[left_it]; // Set the left border to the found index
        }

        // Determine the right border
        int right_it = used_count; // Start from the end
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] > cur_ind) {
                right_it = j; // Found the first used index greater than cur_ind
                break;
            }
        }

        if (right_it == used_count) {
>>>>>>> 98c87cb78a (data updated)
            right_border = N; // No used index to the right
        } else {
            right_border = used_inds[right_it]; // Set the right border to the found index
        }

        // Calculate the contribution of the current index to the answer
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

        // Insert the current index into the array of used indices
        used_inds[used_count++] = cur_ind;
    }

    // Output the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(used_inds);
    return 0;
}

// <END-OF-CODE>
