#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int S[N];
    
    // Read the elements of the array S
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    
    int temp = 0; // Initialize temp to store intermediate results
    int ans = 1000000000; // Initialize ans to store the minimum difference
    
    // Check if K is equal to 1
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i]; // Store the current element in temp
            ans = temp < 0 ? (ans < abs(temp) ? ans : abs(temp)) : (ans < temp ? ans : temp); // Update ans with the minimum absolute value
        }
        printf("%d\n", ans); // Print the minimum absolute value
    } else if (N - K != 0) { // Check if the length of the subarray is not zero
        for (int i = 0; i <= N - K; i++) {
            int min = S[i]; // Initialize min with the first element of the subarray
            int max = S[i + K - 1]; // Initialize max with the last element of the subarray
            
            // Check if the subarray contains both positive and negative numbers
            if (min < 0 && max > 0) {
                temp = min < 0 && max > 0 ? (2 * (-min) + max < (-min) + 2 * max ? 2 * (-min) + max : (-min) + 2 * max) : (min < 0 ? 2 * (-min) + max : (-min) + 2 * max); // Calculate the minimum difference
            } else {
                temp = min < 0 ? abs(min) : (max > 0 ? max : 0); // Calculate the maximum absolute value
            }
            
            ans = ans < temp ? ans : temp; // Update ans with the minimum difference
        }
        printf("%d\n", ans); // Print the minimum difference
    } else { // If the length of the subarray is zero
        int min = S[0]; // Initialize min with the first element
        int max = S[N - 1]; // Initialize max with the last element
        
        // Check if the array contains both positive and negative numbers
        if (min < 0 && max > 0) {
            printf("%d\n", min < 0 && max > 0 ? (2 * (-min) + max < (-min) + 2 * max ? 2 * (-min) + max : (-min) + 2 * max) : (min < 0 ? 2 * (-min) + max : (-min) + 2 * max)); // Print the minimum difference
        } else {
            printf("%d\n", min < 0 ? abs(min) : (max > 0 ? max : 0)); // Print the maximum absolute value
        }
    }
    
    return 0;
}
