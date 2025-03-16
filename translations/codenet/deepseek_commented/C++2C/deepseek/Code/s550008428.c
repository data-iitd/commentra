#include <stdio.h>
#include <stdlib.h>

int main() {
    int s, x, d = 2;
    scanf("%d", &s); // Read the initial number from the user
    int* a = (int*)malloc(1000000 * sizeof(int)); // Allocate memory for the set
    a[0] = s; // Insert the initial number into the set
    int size = 1; // Initialize the size of the set

    while (1) { // Start an infinite loop
        if (s % 2 == 0) { // Check if the current number is even
            x = s / 2; // Halve the number
            for (int i = 0; i < size; i++) { // Check if the halved number has been encountered before
                if (a[i] == x) {
                    printf("%d\n", d); // Output the current step count and terminate the program
                    free(a); // Free the allocated memory
                    return 0;
                }
            }
            a[size++] = x; // Insert the halved number into the set
        } else { // The current number is odd
            x = 3 * s + 1; // Triple the number and add one
            for (int i = 0; i < size; i++) { // Check if the new number has been encountered before
                if (a[i] == x) {
                    printf("%d\n", d); // Output the current step count and terminate the program
                    free(a); // Free the allocated memory
                    return 0;
                }
            }
            a[size++] = x; // Insert the new number into the set
        }
        s = x; // Update the current number to the new number
        d++; // Increment the step count
    }

    printf("%d\n", d); // Output the step count (this line will never be reached)
    free(a); // Free the allocated memory

    return 0;
}
