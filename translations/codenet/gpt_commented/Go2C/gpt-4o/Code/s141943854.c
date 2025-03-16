#include <stdio.h>
#include <stdlib.h>

// check is a utility function that logs an error and exits the program if an error is encountered.
void check(int condition) {
    if (condition) {
        fprintf(stderr, "error: invalid input\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char sage[10]; // Buffer to hold the input string.

    // Read the first line of input.
    fgets(sage, sizeof(sage), stdin);
    
    // Remove the newline character from the input if present.
    sage[strcspn(sage, "\n")] = 0;

    // Use a switch statement to handle different cases based on the input value.
    if (strcmp(sage, "1") == 0) {
        // If the input is "1", print "Hello World".
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        // If the input is "2", initialize a variable to hold the sum of two numbers.
        int sum = 0;
        // Loop to read two numbers from input.
        for (int i = 0; i < 2; i++) {
            int num;
            // Read the next line of input.
            check(scanf("%d", &num) != 1); // Check for any input errors.
            sum += num; // Add the number to the sum.
        }
        // Print the total sum of the two numbers.
        printf("%d\n", sum);
    }

    return 0;
}
