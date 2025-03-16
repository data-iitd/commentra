#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list to store the sequence
    int *L = NULL;
    int size = 0;

    // Read input (not used, but could be for prompting the user)
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        int k = atoi(token);
        // Extend the list 'L' by adding 'r' for 'k' times
        L = realloc(L, (size + k) * sizeof(int));
        for (int i = 0; i < k; i++) {
            L[size++] = r;
        }
        // Increment 'r' for the next number
        r++;
        token = strtok(NULL, " ");
    }

    // Read another line of input (not used, but could be for prompting the user)
    fgets(buffer, sizeof(buffer), stdin);

    // Read a line of input, split it into parts, and iterate over each part
    fgets(buffer, sizeof(buffer), stdin);
    token = strtok(buffer, " ");
    while (token != NULL) {
        int j = atoi(token);
        // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
        printf("%d\n", L[j - 1]);
        token = strtok(NULL, " ");
    }

    // Free the allocated memory
    free(L);
    return 0;
}

// <END-OF-CODE>
