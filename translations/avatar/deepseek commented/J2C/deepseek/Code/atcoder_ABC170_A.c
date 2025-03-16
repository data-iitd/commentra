#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int result = 0;

    // Reading input from stdin
    fgets(input, sizeof(input), stdin);

    // Splitting the input into tokens
    char *token = strtok(input, " ");
    while (token != NULL) {
        result += 1;
        if (strcmp(token, "0") == 0) break;
        token = strtok(NULL, " ");
    }

    // Printing the result to stdout
    printf("%d\n", result);

    return 0;
}
