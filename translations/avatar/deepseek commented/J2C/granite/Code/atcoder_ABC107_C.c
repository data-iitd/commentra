

#include <stdio.h> // Include the standard input/output library

int main() {
    int N, K, S[100000], temp, ans = 1000000000; // Declare and initialize variables
    
    // Read the values of N and K
    scanf("%d %d", &N, &K);
    
    // Read the elements of the array S
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    
    // Check if K is equal to 1
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i]; // Store the current element in temp
            ans = (ans < abs(temp))? ans : abs(temp); // Update ans with the minimum absolute value
        }
        printf("%d\n", ans); // Print the minimum absolute value
    } else if (N - K!= 0) { // Check if the length of the subarray is not zero
        for (int i = 0; i <= N - K; i++) {
            int min = S[i], max = S[i + K - 1]; // Initialize min and max with the first and last elements of the subarray
            
            // Check if the subarray contains both positive and negative numbers
            if (min < 0 && max > 0) {
                temp = (2 * (-min) + max < (-min) + 2 * max)? 2 * (-min) + max : (-min) + 2 * max; // Calculate the minimum difference
            } else {
                temp = (ans < abs(min))? ans : abs(min); // Calculate the maximum absolute value
            }
            
            ans = (ans < temp)? ans : temp; // Update ans with the minimum difference
        }
        printf("%d\n", ans); // Print the minimum difference
    } else { // If the length of the subarray is zero
        int min = S[0], max = S[N - 1]; // Initialize min and max with the first and last elements
        
        // Check if the array contains both positive and negative numbers
        if (min < 0 && max > 0) {
            printf("%d\n", (2 * (-min) + max < (-min) + 2 * max)? 2 * (-min) + max : (-min) + 2 * max); // Print the minimum difference
        } else {
            printf("%d\n", (ans < abs(min))? ans : abs(min)); // Print the maximum absolute value
        }
    }
    
    return 0; // Return 0 to indicate successful execution
}

