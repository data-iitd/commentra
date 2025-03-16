#include <stdio.h>
#include <stdlib.h>

int main() {
    int *L = NULL; // Initialize an empty list L to store the results.
    int size = 0; // To keep track of the size of the list.
    char input[100]; // Buffer for input strings.
    
    // Take the first input from the user.
    fgets(input, sizeof(input), stdin);
    
    int r = 1; // Initialize the variable r to 1.
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        int k = atoi(token); // Convert the string to an integer.
        L = realloc(L, (size + k) * sizeof(int)); // Resize the array to accommodate new elements.
        
        for (int i = 0; i < k; i++) {
            L[size++] = r; // Append r to the list L k times.
        }
        
        r++; // Increment r by 1 for the next iteration.
        token = strtok(NULL, " "); // Get the next token.
    }
    
    // Take the second input from the user.
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    
    while (token != NULL) {
        int j = atoi(token); // Convert the string to an integer.
        printf("%d\n", L[j - 1]); // Print the element at the index specified by j - 1 from the list L.
        token = strtok(NULL, " "); // Get the next token.
    }
    
    free(L); // Free the allocated memory for L.
    return 0;
}

// <END-OF-CODE>
