#include <stdio.h>  // Including standard input-output library

int main() {
    char input[1000];  // Buffer to hold the input string
    fgets(input, sizeof(input), stdin);  // Reading input from standard input

    int result = 0;  // Initializing a variable to store the count of non-zero elements
    char *token = strtok(input, " ");  // Tokenizing the input string by spaces

    // Iterating through the tokens and updating the result
    while (token != NULL) {
        result += 1;  // Incrementing the result for each element
        if (strcmp(token, "0") == 0) break;  // Breaking the loop if a zero is encountered
        token = strtok(NULL, " ");  // Getting the next token
    }

    printf("%d\n", result);  // Printing the result to the console
    return 0;  // Returning from main
}

// <END-OF-CODE>
