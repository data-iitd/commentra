#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, count = 0;
    printf("Enter the number of arrays (n): ");
    scanf("%d", &n);

    // Create an empty list called 'q' to store these arrays
    char **q = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        // Ask user for an array (a)
        q[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each array
        printf("Enter array %d: ", i + 1);
        scanf("%s", q[i]);
    }

    // Use another for loop to iterate through each array in our list 'q'
    for (int j = 0; j < n; j++) {
        // For each array 'j', use another for loop to iterate through every other array in our list 'q'
        for (int k = 0; k < n; k++) {
            // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
            if (j == k) {
                continue;
            }
            // Check if the last element of the second array 'k' matches the first element of the first array 'j'
            if (q[k][strlen(q[k]) - 1] == q[j][0]) {
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
