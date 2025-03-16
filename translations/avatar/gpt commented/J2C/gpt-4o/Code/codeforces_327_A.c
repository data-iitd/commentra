#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int checKNo(int* brr, int n) {
    int val = 0;
    // Count each occurrence of 1 in the array
    for (int i = 0; i < n; i++) {
        if (brr[i] == 1) {
            ++val;
        }
    }
    return val; // Return the total count of 1's
}

int main() {
    // Create a variable to hold the size of the array
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) == 1) {
        // Initialize the array to hold n integers
        int* arr = (int*)malloc(n * sizeof(int));
        
        // Populate the array with user input
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Initialize max to the smallest possible integer value
        int max = INT_MIN;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Create a copy of the original array
                int* brr = (int*)malloc(n * sizeof(int));
                for (int k = 0; k < n; k++) {
                    brr[k] = arr[k];
                }
                
                // Flip the values in the subarray from index i to j
                for (int k = i; k <= j; k++) {
                    if (brr[k] == 0) {
                        brr[k] = 1; // Change 0 to 1
                    } else {
                        brr[k] = 0; // Change 1 to 0
                    }
                }
                
                // Count the number of 1's in the modified array
                int count = checKNo(brr, n);
                
                // Update max if the current count is greater
                if (count > max) {
                    max = count;
                }
                
                // Free the allocated memory for brr
                free(brr);
            }
        }
        
        // Handle the case when there is only one element in the array
        if (n == 1) {
            if (arr[0] == 1) {
                printf("0\n"); // Output 0 if the single element is 1
            } else {
                printf("1\n"); // Output 1 if the single element is 0
            }
        } else {
            // Output the maximum count of 1's found
            printf("%d\n", max);
        }
        
        // Free the allocated memory for arr
        free(arr);
    }
    
    return 0;
}

// <END-OF-CODE>
