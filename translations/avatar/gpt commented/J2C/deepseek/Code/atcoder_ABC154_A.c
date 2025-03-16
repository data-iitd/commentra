#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[100];
    char *str[100];
    int a, b;
    char u[100];

    // Read a line of input, split it by spaces, and store it in an array
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    strcpy(str, buffer);

    // Create a StringTokenizer to read the next line of input
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    char *token = strtok(buffer, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    b = atoi(token);

    // Read another line of input and store it in variable 'u'
    fgets(u, sizeof(u), stdin);
    u[strcspn(u, "\n")] = 0; // Remove newline character

    // Compare the string 'u' with the first element of the array 'str'
    // Print the result based on the comparison
    if (strcmp(u, str[0]) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
