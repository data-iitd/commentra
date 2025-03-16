#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, a, y;
    char buffer[100];
    char *token;

    // Read a line of input from the console
    fgets(buffer, sizeof(buffer), stdin);

    // Split the line into an array of strings using space character as delimiter
    token = strtok(buffer, " ");
    x = atoi(token);
    token = strtok(NULL, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    y = atoi(token);

    // Initialize a string variable h with the value "NO"
    char h[] = "NO";

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h[0] = 'Y';
            h[1] = 'E';
            h[2] = 'S';
        }
    }

    // Print the value of h to the console
    printf("%s\n", h);

    return 0;
}
