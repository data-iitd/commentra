#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // Buffer to store input line
    int Sheep, Wolve;

    // Read input lines continuously until an error occurs
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Split the input line into tokens
        char *token = strtok(input, " ");
        if (token != NULL) {
            Sheep = atoi(token); // Convert first token to integer (number of sheep)
        }
        token = strtok(NULL, " ");
        if (token != NULL) {
            Wolve = atoi(token); // Convert second token to integer (number of wolves)
        }

        // Check if the number of wolves is greater than or equal to the number of sheep
        if (Wolve >= Sheep) {
            printf("unsafe\n"); // Print "unsafe" if the condition is true
        } else {
            printf("safe\n"); // Print "safe" otherwise
        }
    }

    return 0;
}

// <END-OF-CODE>
