#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Variable to store the input number
    int sq[10000], fr[5000]; // Arrays to store squares and frequency counts
<<<<<<< HEAD
    int *com; // Dynamic array to store unique square values
=======
    int *com; // Pointer to store unique square values
>>>>>>> 98c87cb78a (data updated)
    int com_size = 0; // Size of the unique squares array
    int tmp; // Temporary variable for calculations

    // Infinite loop to continuously read input until a zero is entered
    while (1) {
        scanf("%d", &n); // Read an integer from input
        if (!n) break; // Exit the loop if the input is zero

        // Calculate the squares of numbers from 1 to n-1 modulo n
        for (int i = 1; i < n; i++) {
            sq[i] = (i * i) % n;
        }

<<<<<<< HEAD
        // Allocate memory for the unique squares array
        com = (int *)malloc(n * sizeof(int));
        com_size = 0; // Reset the size of the unique squares array
=======
        // Allocate memory for unique squares
        com = (int *)malloc(n * sizeof(int));
        com_size = 0; // Reset the size of unique squares
>>>>>>> 98c87cb78a (data updated)

        // Collect unique square values into the array 'com'
        for (int i = 1; i < n; i++) {
            int f = 1; // Flag to check if the square is unique
            for (int j = 0; j < com_size; j++) {
                if (com[j] == sq[i]) { // Check if the square is already in 'com'
                    f = 0; // Not unique
                    break;
                }
            }
            if (f) {
                com[com_size++] = sq[i]; // Add to 'com' if unique
            }
        }

        // Initialize frequency array to count occurrences of differences
        for (int i = 0; i <= (n - 1) / 2; i++) {
            fr[i] = 0;
        }

        // Calculate the frequency of differences between unique squares
        for (int i = 0; i < com_size; i++) {
            for (int j = 0; j < com_size; j++) {
                if (i != j) { // Ensure we are not comparing the same element
                    tmp = com[i] - com[j]; // Calculate the difference
                    if (tmp < 0) tmp += n; // Adjust if negative
                    if (tmp > (n - 1) / 2) tmp = n - tmp; // Adjust to be within the range
                    fr[tmp]++; // Increment the frequency count for this difference
                }
            }
        }

        // Output the frequency counts for differences from 1 to (n-1)/2
        for (int i = 1; i <= (n - 1) / 2; i++) {
            printf("%d\n", fr[i]);
        }

<<<<<<< HEAD
        // Free the allocated memory for unique squares
=======
        // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
        free(com);
    }

    return 0;
}

// <END-OF-CODE>
