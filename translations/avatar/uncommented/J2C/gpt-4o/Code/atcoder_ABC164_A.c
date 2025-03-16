#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // Buffer to store input
    int Sheep, Wolve;

    // Read input until EOF
    while (fgets(input, sizeof(input), stdin)) {
        // Split the input into tokens
        char *token = strtok(input, " ");
        if (token != NULL) {
            Sheep = atoi(token); // Convert first token to integer
            token = strtok(NULL, " ");
            if (token != NULL) {
                Wolve = atoi(token); // Convert second token to integer
            }
        }
    }

    // Check the condition and print the result
    if (Wolve >= Sheep) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }

    return 0;
}

// <END-OF-CODE>
