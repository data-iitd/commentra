#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements (N) and the size of the subset (K)
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Initialize an array to store the input integers
    int S[N];
    
    // Read N integers into the array S
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    
    // Initialize temporary variable and answer variable with a large number
    int temp = 0;
    int ans = 1000000000;

    // Case when K is 1: Find the minimum absolute value in the array
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = (temp < 0)? -temp : temp; // Update ans with the minimum absolute value
        }
        // Output the result
        printf("%d\n", ans);
    } 
    // Case when K is not equal to N: Calculate the minimum value based on subsets of size K
    else if (N - K!= 0) {
        for (int i = 0; i <= N - K; i++) {
            int min = S[i]; // Minimum value in the current subset
            int max = S[i + K - 1]; // Maximum value in the current subset
            
            // Calculate temp based on the values of min and max
            if (min < 0 && max > 0) {
                // If the subset contains both negative and positive values
                temp = (2 * (-min) + max < (-min) + 2 * max)? 2 * (-min) + max : (-min) + 2 * max;
            } else {
                // If the subset contains only negative or only positive values
                temp = (min < 0)? -min : max;
            }
            
            // Update the answer with the minimum value found
            ans = (ans < temp)? ans : temp;
        }
        // Output the result
        printf("%d\n", ans);
    } 
    // Case when K is equal to N: Handle the entire array as a single subset
    else {
        int min = S[0]; // Minimum value in the array
        int max = S[N - 1]; // Maximum value in the array
        
        // Check if the array contains both negative and positive values
        if (min < 0 && max > 0) {
            // Calculate and print the minimum value based on the formula
            printf("%d\n", (2 * (-min) + max < (-min) + 2 * max)? 2 * (-min) + max : (-min) + 2 * max);
        } else {
            // Print the maximum absolute value
            printf("%d\n", (min < 0)? -min : max);
        }
    }
    
    // Prevent resource leaks
    return 0;
}

