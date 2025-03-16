#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char input[1000];
    char *token;
    int result = 0;

    // Read a line of input
    fgets(input, sizeof(input), stdin);

    // Tokenize the input based on spaces
    token = strtok(input, " ");

    // Iterate through each token
    while (token != NULL) {
        // Increment the counter for each token
        result += 1;

        // If the token is "0", break out of the loop
        if (strcmp(token, "0") == 0) break;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the result, which is the count of non-zero tokens before the first "0"
    printf("%d\n", result);

    // No need to close any specific resources as in Java

    return 0;
}
