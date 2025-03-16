#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a string variable h with the value "NO"
    char h[4] = "NO";

    // Read a line of input from the console
    char line[100];
    fgets(line, 100, stdin);

    // Split the line into an array of strings using space character as delimiter
    char *list[100];
    list[0] = strtok(line, " ");
    int i = 1;
    while (list[i - 1] != NULL) {
        list[i] = strtok(NULL, " ");
        i++;
    }

    // Parse the first three elements of the array as integers x, a, and y
    int x = atoi(list[0]);
    int a = atoi(list[1]);
    int y = atoi(list[2]);

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            strcpy(h, "YES");
        }
    }

    // Print the value of h to the console
    printf("%s\n", h);

    return 0;
}

