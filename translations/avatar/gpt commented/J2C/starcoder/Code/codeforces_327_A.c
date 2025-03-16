#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Check if there is input available
    if (n > 0) {
        // Initialize the array to hold n integers
        int arr[n];
        
        // Populate the array with user input
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        // Initialize max to the smallest possible integer value
        int max = INT_MIN;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Initialize a temporary variable to track the index for brr
                int x = 0;
                // Create a copy of the original array
                int brr[n];
                for (int k = 0; k < n; k++)
                    brr[x++] = arr[k];
                
                // Flip the values in the subarray from index i to j
                for (int k = i; k <= j; k++) {
                    if (brr[k] == 0)
                        brr[k] = 1; // Change 0 to 1
                    else
                        brr[k] = 0; // Change 1 to 0
                }
                
                // Count the number of 1's in the modified array
                int count = 0;
                for (int k = 0; k < n; k++)
                    if (brr[k] == 1)
                        ++count;
                
                // Update max if the current count is greater
                if (count > max)
                    max = count;
            }
        }
        
        // Handle the case when there is only one element in the array
        if (n == 1) {
            if (arr[0] == 1)
                printf("0\n"); // Output 0 if the single element is 1
            else
                printf("1\n"); // Output 1 if the single element is 0
        } else {
            // Output the maximum count of 1's found
            printf("%d\n", max);
        }
    }
    
    return 0;
}

