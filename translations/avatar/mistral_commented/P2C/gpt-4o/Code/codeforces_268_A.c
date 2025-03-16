#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Ask user for the number of arrays (n) they want to input
    int n;
    scanf("%d", &n);

    // Create an array of pointers to store the arrays
    char **q = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        // Allocate memory for each array and read input
        q[i] = malloc(100 * sizeof(char)); // Assuming max length of each array is 100
        scanf("%s", q[i]);
    }

    // Initialize count variable
    int count = 0;

    // Use nested loops to compare arrays
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // Exclude the current array 'j' from comparison
            if (k == j) {
                continue;
            }
            // Check if the last element of the second array matches the first element of the first array
            if (q[j][0] == q[k][strlen(q[k]) - 1]) {
                // If it does, increment our 'count' variable
                count++;
            }
        }
    }

    // Finally, print out the value of our 'count' variable
    printf("%d\n", count);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(q[i]);
    }
    free(q);

    return 0;
}

// <END-OF-CODE>
