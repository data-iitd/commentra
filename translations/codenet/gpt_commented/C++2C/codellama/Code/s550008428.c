#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int s, x, d = 2; // Initialize variables: s for input, x for calculations, d for depth
    scanf("%d", &s); // Read an integer input from the user
    int *a = (int *)malloc(sizeof(int)); // Create a set to store unique values of s
    a[0] = s; // Insert the initial value of s into the set

    // Start an infinite loop to process the value of s
    while (1) {
        // Check if s is even
        if (s % 2 == 0) {
            x = s / 2; // If even, calculate the next value as half of s
            // Check if the new value x already exists in the set
            for (int i = 0; i < d; i++) {
                if (a[i] == x) {
                    printf("%d\n", d); // If it exists, print the depth and exit
                    free(a);
                    return 0;
                }
            }
            a = (int *)realloc(a, sizeof(int) * (d + 1)); // Insert the new value x into the set
            a[d] = x;
        } else {
            // If s is odd, calculate the next value using the formula 3*s + 1
            x = 3 * s + 1; 
            // Check if the new value x already exists in the set
            for (int i = 0; i < d; i++) {
                if (a[i] == x) {
                    printf("%d\n", d); // If it exists, print the depth and exit
                    free(a);
                    return 0;
                }
            }
            a = (int *)realloc(a, sizeof(int) * (d + 1)); // Insert the new value x into the set
            a[d] = x;
        }
        s = x; // Update s to the new value x for the next iteration
        d++; // Increment the depth counter
    }

    // This line will never be reached due to the infinite loop
    printf("%d\n", d); // Print the depth (not reached)
    free(a);

    return 0; // Return 0 to indicate successful completion of the program
}

