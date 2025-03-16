#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read an integer input which represents the number of lists to be processed
    int n;
    scanf("%d", &n);

    // Initialize an array of pointers to store the input lists
    char ***q = malloc(n * sizeof(char**));
    int *list_sizes = malloc(n * sizeof(int)); // To store the sizes of each list
    int count = 0;

    // Loop to read 'n' lines of input and store them in the list 'q'
    for (int i = 0; i < n; i++) {
        // Allocate memory for the list and read the input
        q[i] = malloc(100 * sizeof(char*)); // Assuming max 100 elements per list
        char buffer[1000]; // Buffer to read the entire line
        scanf(" %[^\n]", buffer); // Read a line of input

        // Split the input line into words
        char *token = strtok(buffer, " ");
        int size = 0;
        while (token != NULL) {
            q[i][size] = malloc((strlen(token) + 1) * sizeof(char)); // Allocate memory for each word
            strcpy(q[i][size], token);
            size++;
            token = strtok(NULL, " ");
        }
        list_sizes[i] = size; // Store the size of the current list
    }

    // Nested loop to compare each list in 'q' with every other list
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // Skip comparison if both lists are the same
            if (k == j) {
                continue;
            }
            // Check if the first element of list 'j' matches the last element of list 'k'
            if (strcmp(q[j][0], q[k][list_sizes[k] - 1]) == 0) {
                // Increment the count if the condition is met
                count++;
            }
        }
    }

    // Print the final count of matching conditions
    printf("%d\n", count);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < list_sizes[i]; j++) {
            free(q[i][j]); // Free each word
        }
        free(q[i]); // Free the list
    }
    free(q); // Free the array of lists
    free(list_sizes); // Free the sizes array

    return 0;
}

// <END-OF-CODE>
