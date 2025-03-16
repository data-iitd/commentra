#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initializing variables to store the number of sheep and wolves
    int Sheep, Wolve;
    char input[100]; // Buffer to store input line

    // Reading the first line of input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Splitting the input line into tokens
        char *token = strtok(input, " ");
        if (token != NULL) {
            Sheep = atoi(token); // Parsing the first number as the count of sheep
            token = strtok(NULL, " ");
            if (token != NULL) {
                Wolve = atoi(token); // Parsing the second number as the count of wolves
            }
        }
    }

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        // If wolves are greater than or equal to sheep, it's unsafe
        printf("unsafe\n");
    } else {
        // If wolves are fewer than sheep, it's safe
        printf("safe\n");
    }

    return 0;
}

// <END-OF-CODE>
