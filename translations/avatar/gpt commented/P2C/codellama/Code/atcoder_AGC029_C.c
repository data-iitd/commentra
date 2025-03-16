
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to cut the array based on a given index
void cut(int *array, int index, int *length) {
    // If the index is less than 1, return an empty list
    if (index < 1) {
        *length = 0;
        return;
    }
    
    // If the index is less than or equal to the first element, return it with the first element's second value
    if (index <= array[0]) {
        array[0] = index;
        *length = 1;
        return;
    }
    
    // Iterate backwards through the array to find the appropriate cut point
    for (int i = *length - 1; i > 0; i--) {
        if (array[i - 1] < index) {
            array[i] = index;
            *length = i + 1;
            return;
        }
    }
}

// Function to check if a certain condition is possible with K
int is_possible(int *array, int length, int K) {
    // Initialize the dynamic programming array with the first element
    int dp[length];
    dp[0] = array[0];
    
    // Iterate through the remaining elements in A
    for (int i = 1; i < length; i++) {
        // If the current element is less than or equal to the last element in dp, cut dp
        if (array[i] <= dp[i - 1]) {
            cut(dp, array[i], &length);
        } else {
            // Otherwise, append the current element to dp
            dp[i] = array[i];
        }
        
        int is_added = 0;
        
        // Iterate backwards through dp to check conditions
        for (int j = length - 1; j > 0; j--) {
            // If the second value of the current tuple is less than K-1
            if (dp[j - 1] < K - 1) {
                // Cut dp and increment the second value of the current tuple
                cut(dp, dp[j - 1] - 1, &length);
                dp[j - 1] += 1;
                
                // If the last element in dp is less than a, append a to dp
                if (dp[length - 1] < array[i]) {
                    dp[length] = array[i];
                    length += 1;
                }
                
                is_added = 1;
                break;
            }
        }
        
        // If no element was added, return False
        if (!is_added) {
            return 0;
        }
    }
    
    // If all conditions are satisfied, return True
    return 1;
}

// Function to perform binary search to find the maximum K
int bis(int x, int y) {
    // If the range is narrowed down to one element, return y
    if (y == x + 1) {
        return y;
    }
    // If is_possible is true for the midpoint, search in the left half
    if (is_possible(x, y - 1)) {
        return bis(x, (x + y) / 2);
    }
    // Otherwise, search in the right half
    else {
        return bis((x + y) / 2, y);
    }
}

int main() {
    // Read input from the user
    int N;
    scanf("%d", &N);
    
    // Parse the input into a list of integers
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Print the result of the binary search
    printf("%d\n", bis(0, N));
    
    return 0;
}

