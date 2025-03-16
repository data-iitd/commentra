#include <stdio.h>
#include <stdlib.h>

// Function to cut the array based on a given index
void cut(int** array, int* size, int index) {
    // If the index is less than 1, return an empty list
    if (index < 1) {
        return;
    }
    
    // If the index is less than or equal to the first element, return it with the first element's second value
    if (index <= (*array)[0]) {
        (*array)[0] = index;
        return;
    }
    
    // Iterate backwards through the array to find the appropriate cut point
    for (int i = *size - 1; i > 0; i--) {
        if ((*array)[i - 1] < index) {
            (*array)[i] = index;
            return;
        }
    }
}

// Function to check if a certain condition is possible with K
int is_possible(int* A, int N, int K) {
    // Initialize the dynamic programming array with the first element
    int* dp = (int*)malloc(N * sizeof(int));
    dp[0] = A[0];
    int dp_size = 1;
    
    // Iterate through the remaining elements in A
    for (int i = 1; i < N; i++) {
        // If the current element is less than or equal to the last element in dp, cut dp
        if (A[i] <= dp[dp_size - 1]) {
            cut(&dp, &dp_size, A[i]);
        } else {
            // Otherwise, append the current element to dp
            dp[dp_size++] = A[i];
        }
        
        int is_added = 0;
        
        // Iterate backwards through dp to check conditions
        for (int j = dp_size - 1; j >= 0; j--) {
            // If the second value of the current tuple is less than K-1
            if (dp[j] < K - 1) {
                // Cut dp and increment the second value of the current tuple
                cut(&dp, &dp_size, dp[j] - 1);
                dp[dp_size++] = dp[j];
                
                // If the last element in dp is less than a, append a to dp
                if (dp[dp_size - 1] < A[i]) {
                    dp[dp_size++] = A[i];
                }
                
                is_added = 1;
                break;
            }
        }
        
        // If no element was added, return False
        if (!is_added) {
            free(dp);
            return 0;
        }
    }
    
    // If all conditions are satisfied, return True
    free(dp);
    return 1;
}

// Function to perform binary search to find the maximum K
int bis(int* A, int N, int x, int y) {
    // If the range is narrowed down to one element, return y
    if (y == x + 1) {
        return y;
    }
    // If is_possible is true for the midpoint, search in the left half
    else if (is_possible(A, N, (x + y) / 2)) {
        return bis(A, N, x, (x + y) / 2);
    }
    // Otherwise, search in the right half
    else {
        return bis(A, N, (x + y) / 2, y);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Print the result of the binary search
    printf("%d\n", bis(A, N, 0, N));
    
    free(A);
    return 0;
}
