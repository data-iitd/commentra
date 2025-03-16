#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char *numlist[2];
    int Sheep, Wolve;

    // Read input lines until EOF
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Tokenize the input line
        char *token = strtok(input, " ");
        int index = 0;
        while (token != NULL) {
            numlist[index++] = token;
            token = strtok(NULL, " ");
        }

        // Parse the first two elements as integers
        Sheep = atoi(numlist[0]);
        Wolve = atoi(numlist[1]);

        // Check if the number of wolves is greater than or equal to the number of sheep
        if (Wolve >= Sheep) {
            printf("unsafe\n");
        } else {
            printf("safe\n");
        }
    }

    return 0;
}
