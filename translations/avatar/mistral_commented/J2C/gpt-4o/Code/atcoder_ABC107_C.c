#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Initialize variables
    int N, K;
    
    // Read the first two integers from the standard input
    scanf("%d %d", &N, &K); // Read the number of elements in the array and the size of the sliding window

    // Allocate an integer array of size N to store the input elements
    int *S = (int *)malloc(N * sizeof(int));

    // Read the remaining elements of the array from the standard input
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]); // Read the next integer and store it in the array
    }

    // Initialize variables for calculating the answer
    int temp = 0;
    int ans = INT_MAX; // Use INT_MAX for a large initial value

    // Check the special case when the size of the sliding window is 1
    if (K == 1) {
        // Iterate through the array to find the minimum absolute value
        for (int i = 0; i < N; i++) {
            temp = S[i]; // Read the current element
            ans = (abs(temp) < ans) ? abs(temp) : ans; // Update the answer if necessary
        }

        // Print the answer
        printf("%d\n", ans);
    } else if (N - K != 0) { // Check the case when the size of the sliding window is not equal to the size of the array
        // Initialize variables for calculating the minimum and maximum elements in the sliding window
        int min, max;

        // Iterate through all possible positions of the sliding window
        for (int i = 0; i <= N - K; i++) {
            // Find the minimum and maximum elements in the current sliding window
            min = S[i];
            max = S[i + K - 1];

            // Calculate the sum of the absolute values of the minimum and maximum elements
            // and update the answer if necessary
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = (abs(min) > abs(max)) ? abs(min) : abs(max);
            }
            ans = (temp < ans) ? temp : ans;
        }

        // Print the answer
        printf("%d\n", ans);
    } else { // Check the case when the size of the sliding window is equal to the size of the array
        // Find the minimum and maximum elements in the array
        min = S[0];
        max = S[N - 1];

        // Calculate the sum of the absolute values of the minimum and maximum elements
        // and print the answer directly
        if (min < 0 && max > 0) {
            printf("%d\n", (2 * (abs(min)) + max < (abs(min) + 2 * max)) ? (2 * (abs(min)) + max) : (abs(min) + 2 * max));
        } else {
            printf("%d\n", (abs(min) > abs(max)) ? abs(min) : abs(max));
        }
    }

    // Free the allocated memory
    free(S);

    return 0;
}

// <END-OF-CODE>
