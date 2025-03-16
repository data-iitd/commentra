#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000

long long a[MAX_SIZE];
int ind_a[MAX_SIZE];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N; // Read the number of elements N from the standard input
    scanf("%d", &N);

    // Read N elements from the standard input and store them in the array 'a'
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        ind_a[i] = i; // Initialize ind_a with the index values
    }

    // Sort the ind_a array based on the values in a
    qsort(ind_a, N, sizeof(int), compare);

    long long ans = 0; // Initialize an answer variable 'ans' to 0
    int *used_inds = (int *)malloc(N * sizeof(int));
    int used_count = 0;

    // Iterate through each index i from 0 to N-1
    for (int i = 0; i < N; i++) {
        long long left_border; // Initialize variables 'left_border' and 'right_border'
        long long right_border;

        long long cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

        // Find the index of the left neighbor of the current index i in the used_inds
        int left_index = -1;
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] < cur_ind) {
                left_index = j;
            } else {
                break;
            }
        }
        left_border = (left_index == -1) ? -1 : used_inds[left_index];

        // Find the index of the right neighbor of the current index i in the used_inds
        int right_index = used_count;
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] > cur_ind) {
                right_index = j;
                break;
            }
        }
        right_border = (right_index == used_count) ? N : used_inds[right_index];

        // Calculate the contribution of the current index i to the answer 'ans'
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

        // Insert the index of the current element a[i] into the used_inds
        used_inds[used_count++] = cur_ind;
    }

    // Print the final answer 'ans' to the standard output
    printf("%lld\n", ans);

    // Free allocated memory
    free(used_inds);

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
