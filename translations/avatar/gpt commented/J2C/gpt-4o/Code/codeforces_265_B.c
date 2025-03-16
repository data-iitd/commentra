#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initialize an array to hold the input integers
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Populate the array with integers from user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize the answer with the first element of the array plus one
    int ans = arr[0] + 1;
    
    // Calculate the total distance based on the differences between consecutive elements
    for (int i = 1; i < n; i++) {
        // Add the absolute difference between the current and previous element, plus 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }
    
    // Output the final calculated answer
    printf("%d\n", ans);
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}

// <END-OF-CODE>
