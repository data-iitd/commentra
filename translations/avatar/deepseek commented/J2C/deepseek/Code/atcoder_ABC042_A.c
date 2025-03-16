#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, a, y;
    char line[100];
    char *token;

    // Read a line of input from the user
    fgets(line, sizeof(line), stdin);

    // Split the input line into an array of strings
    token = strtok(line, " ");
    x = atoi(token);
    token = strtok(NULL, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    y = atoi(token);

    // Initialize a variable to store the result
    char h[] = "NO";

    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // Check if the sum of the integers is 17
        if (x + y + a == 17) {
            strcpy(h, "YES");
        }
    }

    // Print the result
    printf("%s\n", h);

    return 0;
}
