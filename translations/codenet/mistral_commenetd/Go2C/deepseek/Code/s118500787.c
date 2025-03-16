#include <stdio.h>
#include <string.h>

// Function to read a string from stdin
char* readString() {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Allocate memory for the string and copy the content
        char* str = (char*)malloc(strlen(buffer) + 1);
        strcpy(str, buffer);
        // Remove the newline character if present
        str[strcspn(str, "\n")] = 0;
        return str;
    }
    return NULL;
}

int main() {
    // Initialize two empty strings S and T
    char* S = readString();
    char* T = readString();

    // Initialize max as 0
    int max = 0;

    // Loop through all possible substrings of S with length equal to T
    for (int i = 0; i <= strlen(S) - strlen(T); i++) {
        // Initialize a counter c for the number of matching characters between S[i:i+strlen(T)] and T
        int c = 0;

        // Check character by character for matching characters
        for (int j = 0; j < strlen(T); j++) {
            // If current characters match, increment counter c
            if (S[i + j] == T[j]) {
                c++;
            }
        }

        // If current substring has more matching characters than the current max, update max
        if (max < c) {
            max = c;
        }
    }

    // Print the length of the shortest substring of S that matches T with all characters
    printf("%zu\n", strlen(T) - max);

    // Free allocated memory
    free(S);
    free(T);

    return 0;
}
