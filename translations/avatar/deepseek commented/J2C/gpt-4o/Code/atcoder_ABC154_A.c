#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a buffer to read input
    char buffer[100];
    
    // Read the first line of input
    fgets(buffer, sizeof(buffer), stdin);
    char *str[10]; // Assuming a maximum of 10 tokens
    int count = 0;

    // Tokenize the first line by spaces
    char *token = strtok(buffer, " \n");
    while (token != NULL) {
        str[count++] = token;
        token = strtok(NULL, " \n");
    }

    // Read the second line of input
    fgets(buffer, sizeof(buffer), stdin);
    int a, b;

    // Parse the integers from the second line
    sscanf(buffer, "%d %d", &a, &b);

    // Read another string from the input
    fgets(buffer, sizeof(buffer), stdin);
    // Remove the newline character from the string
    buffer[strcspn(buffer, "\n")] = 0;

    // Check if the read string is equal to the first element of the array and print accordingly
    if (strcmp(buffer, str[0]) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}

// <END-OF-CODE>
