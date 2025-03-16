#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100][100]; // Assuming a maximum of 100 words with a maximum length of 100 characters
    int a, b;
    char u[100];

    // Read the first line and split it into words
    char line[1000];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    int index = 0;
    while (token != NULL) {
        strcpy(str[index++], token);
        token = strtok(NULL, " ");
    }

    // Read the second line
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d", &a, &b);

    // Read the third line
    fgets(u, sizeof(u), stdin);
    u[strcspn(u, "\n")] = 0; // Remove the newline character

    // Compare and print the result
    if (strcmp(u, str[0]) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
