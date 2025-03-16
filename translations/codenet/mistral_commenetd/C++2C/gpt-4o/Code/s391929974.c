#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int n;                       // Number of elements in the array
    int sq[10000];               // Square array to store squares of numbers from 1 to n-1
    int fr[5000];                // Frequency array to store the frequency of each difference between squares
    int *com;                    // Array to store unique squares
    int com_size = 0;            // Size of the unique squares array
    int tmp;                     // Temporary variable

    // Start of the infinite loop
    while (1) {
        scanf("%d", &n);         // Read the number of elements in the array from the user
        if (!n) break;           // If the number is zero, break the loop

        // Initialize square array
        for (int i = 1; i < n; i++) {
            sq[i] = (i * i) % n;
        }

        // Allocate memory for unique squares
        com = (int *)malloc(n * sizeof(int));
        com_size = 0;            // Reset the size of the unique squares array

        // Find unique squares and store them in the array
        for (int i = 1; i < n; i++) {
            int f = 1;           // Flag to check if the square is already present in the array
            for (int j = 0; j < com_size; j++) {
                if (com[j] == sq[i]) { // If the square is already present, set the flag to false
                    f = 0;
                    break;
                }
            }
            if (f) com[com_size++] = sq[i]; // If the square is not present, add it to the array
        }

        // Initialize frequency array
        for (int i = 0; i <= (n - 1) / 2; i++) {
            fr[i] = 0;
        }

        // Find the frequency of each difference between unique squares
        for (int i = 0; i < com_size; i++) {
            for (int j = 0; j < com_size; j++) {
                if (i != j) {         // If the indices are not the same
                    tmp = com[i] - com[j]; // Calculate the difference between two squares
                    if (tmp < 0) tmp += n; // If the difference is negative, make it positive by adding n
                    if (tmp > (n - 1) / 2) tmp = n - tmp; // If the difference is greater than half the size of the array, make it smaller
                    fr[tmp]++;       // Increment the frequency of the difference
                }
            }
        }

        // Print the frequency of each difference
        for (int i = 1; i <= (n - 1) / 2; i++) {
            printf("%d\n", fr[i]);
        }

        // Free allocated memory
        free(com);
    }

    return 0;
}

// <END-OF-CODE>
