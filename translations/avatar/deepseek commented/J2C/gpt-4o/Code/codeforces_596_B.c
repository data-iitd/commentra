#include <stdio.h> // Step 1: Include the standard input-output library.
#include <stdlib.h> // Step 2: Include the standard library for abs function.

int main() { // Step 3: Implement the main function.
    int n; // Step 4: Declare a variable to store the size of the array.
    scanf("%d", &n); // Step 5: Read the size of the array from the user.
    
    long *arr = (long *)malloc(n * sizeof(long)); // Step 6: Create an array to store the elements of the array.
    for (int i = 0; i < n; i++) { // Step 7: Read the elements of the array from the user.
        scanf("%ld", &arr[i]);
    }
    
    long answer = abs(arr[0]); // Step 8: Initialize a variable to store the answer.
    for (int i = 1; i < n; i++) { // Step 9: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += abs(arr[i] - arr[i - 1]);
    }
    
    printf("%ld\n", answer); // Step 10: Print the final answer.
    
    free(arr); // Free the allocated memory for the array.
    return 0; // Return 0 to indicate successful execution.
} // <END-OF-CODE>
