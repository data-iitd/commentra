#include <stdio.h>
#include <string.h>

int main() {
    char input[1000]; // Assuming the input will not exceed 1000 characters
    fgets(input, sizeof(input), stdin); // Read a line of input

    int result = 0;
    char *token = strtok(input, " "); // Tokenize the input by spaces

    while (token != NULL) {
        result += 1;
        if (strcmp(token, "0") == 0) break; // Check if the token is "0"
        token = strtok(NULL, " "); // Get the next token
    }

    printf("%d\n", result); // Print the result
    return 0;
}

// <END-OF-CODE>
