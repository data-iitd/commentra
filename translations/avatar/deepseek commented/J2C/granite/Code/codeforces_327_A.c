
#include <stdio.h> // Include the standard input/output library

int main() {
    int n; // Declare and initialize the size of the array
    scanf("%d", &n);
    
    int arr[n]; // Declare and initialize the array
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read the elements of the array
    }
    
    int max = -100000000; // Initialize max to a large negative value
    
    for (int i = 0; i < n; i++) { // Iterate over all possible starting points of subarrays
        for (int j = i; j < n; j++) { // Iterate over all possible ending points of subarrays
            int x = 0;
            int brr[n]; // Declare and initialize a copy of the array
            
            for (int k = 0; k < n; k++) {
                brr[x++] = arr[k]; // Copy the elements of arr to brr
            }
            
            for (int k = i; k <= j; k++) { // Flip the elements in the current subarray
                if (brr[k] == 0) {
                    brr[k] = 1;
                } else {
                    brr[k] = 0;
                }
            }
            
            int count = checkNo(brr); // Count the number of 1s in the modified subarray
            
            if (count > max) {
                max = count; // Update max if the current count is greater
            }
        }
    }
    
    if (n == 1) { // Handle the special case of a single element array
        if (arr[0] == 1) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else {
        printf("%d\n", max); // Print the maximum count of 1s found
    }
    
    return 0; // Return 0 to indicate successful execution
}

int checkNo(int brr[]) { // Helper function to count the number of 1s in an array
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (brr[i] == 1) {
            val++;
        }
    }
    return val;
}

