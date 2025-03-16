#include <stdio.h>

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initialize an array to hold the integers and a variable to store the sum
    int arr[n];
    int sum = 0;
    
    // Read the integers into the array and calculate the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Accumulate the sum of the elements
    }
    
    // Initialize a counter for valid indices and a variable for output
    int c = 0;
    
    // Check each element to see if it can be the "removed" element
    for (int i = 0; i < n; i++) {
        // Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count of valid indices
            printf("%d ", i + 1); // Output the 1-based index
        }
    }
    
    // Output the count of valid indices
    printf("\n%d\n", c);
    
    return 0;
}

// <END-OF-CODE>
