#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int result = 0;

    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        result += 1;
        if (strcmp(token, "0") == 0) {
            break;
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", result);
    return 0;
}
