#include <stdio.h>
#include <stdlib.h>

int main() {
    int s, x, d = 2; // Initialize variables: s for input, x for calculations, d for depth
    scanf("%d", &s); // Read an integer input from the user
    int *a = (int *)malloc(1000000 * sizeof(int)); // Create an array to store unique values of s
    int a_size = 0; // Size of the array to keep track of unique values
    a[a_size++] = s; // Insert the initial value of s into the array

    // Start an infinite loop to process the value of s
    while (1) {
        // Check if s is even
        if (s % 2 == 0) {
            x = s / 2; // If even, calculate the next value as half of s
        } else {
            // If s is odd, calculate the next value using the formula 3*s + 1
            x = 3 * s + 1; 
        }

        // Check if the new value x already exists in the array
        int found = 0;
        for (int i = 0; i < a_size; i++) {
            if (a[i] == x) {
                found = 1; // If it exists, mark found
                break;
            }
        }

        if (found) {
            printf("%d\n", d); // If it exists, print the depth and exit
            free(a); // Free allocated memory
            return 0;
        }

        a[a_size++] = x; // Insert the new value x into the array
        s = x; // Update s to the new value x for the next iteration
        d++; // Increment the depth counter
    }

    // This line will never be reached due to the infinite loop
    printf("%d\n", d); // Print the depth (not reached)

    free(a); // Free allocated memory
    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
