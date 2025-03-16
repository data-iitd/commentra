#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int result = 0;

    // Reading input from the console
    fgets(input, sizeof(input), stdin);

    // Tokenizing the input string
    char *token = strtok(input, " ");
    while (token != NULL) {
        result++;
        // Check if the token is "0"
        if (strcmp(token, "0") == 0) {
            break;
        }
        token = strtok(NULL, " ");
    }

    // Writing the result to the console
    printf("%d\n", result);

    return 0;
}
