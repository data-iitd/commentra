#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char str[100][100]; // Array to hold the split strings
    int a, b;
    char u[100];

    // Read a line of input and split it by spaces
    char line[1000];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    int index = 0;
    while (token != NULL) {
        strcpy(str[index++], token);
        token = strtok(NULL, " ");
    }

    // Read the next line of input
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d", &a, &b);

    // Read another line of input
    fgets(u, sizeof(u), stdin);
    u[strcspn(u, "\n")] = 0; // Remove the newline character

    // Compare the string 'u' with the first element of the array 'str'
    // Print the result based on the comparison
    if (strcmp(u, str[0]) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
