
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a variable to hold the result, defaulting to "NO"
    char h[] = "NO";

    // Read a line of input and split it into an array of strings
    char line[100];
    fgets(line, sizeof(line), stdin);
    char *list[3];
    int i = 0;
    char *token = strtok(line, " ");
    while (token!= NULL) {
        list[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    // Parse the first three elements of the input into integers
    int x = atoi(list[0]);
    int a = atoi(list[1]);
    int y = atoi(list[2]);

    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) {
            h[0] = 'Y';
            h[1] = 'E';
            h[2] = 'S';
        }
    }

    // Output the result
    printf("%s\n", h);

    return 0;
}
