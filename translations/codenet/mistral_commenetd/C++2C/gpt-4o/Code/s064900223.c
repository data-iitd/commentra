#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, ans; // Declare variables i, n, and ans

    // Read the number of elements in the array from the user
    scanf("%d", &n); // Read the size of the array

    // Allocate memory for the array p of size n
    int *p = (int *)malloc(n * sizeof(int)); // Initialize an array p of size n

    // Read elements of the array p from the user
    for(i = 0; i < n; i++) { // Loop through each element of the array p
        scanf("%d", &p[i]); // Read the value of the current element
    }

    // Initialize the answer variable ans to zero
    ans = 0;

    // Check each element of the array p starting from the first one
    for(i = 0; i < n - 1; i++) { // Loop through each element except the last one
        if(p[i] == i + 1) { // Check if the current element is equal to its index + 1
            p[i + 1] = p[i]; // Swap the current element with the next one if it is in the wrong position
            ans += 1; // Increment the answer if a swap was made
        }
    }

    // Check the last element of the array p
    if(p[n - 1] == n) { // Check if the last element is equal to its index + 1
        ans += 1; // Increment the answer if it is in the wrong position
    }

    // Print the answer to the user
    printf("%d\n", ans); // Output the answer

    // Free the allocated memory
    free(p); // Free the allocated memory for the array p

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
