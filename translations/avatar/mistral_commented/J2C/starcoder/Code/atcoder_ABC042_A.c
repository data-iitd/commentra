#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a variable named line to hold the input
    char line[100];

    // Read a line of input from the console
    scanf("%s", line);

    // Declare three integer variables named x, a, and y
    int x, a, y;

    // Parse the first three elements of the array as integers x, a, and y
    sscanf(line, "%d %d %d", &x, &a, &y);

    // Declare a variable named h to hold the value "NO"
    char h[] = "NO";

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h = "YES";
        }
    }

    // Print the value of h to the console
    printf("%s\n", h);

    return 0;
}

