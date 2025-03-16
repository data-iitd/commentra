#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to handle errors by printing an error message and exiting the program.
void check(char *error_message) {
    if (error_message != NULL) {
        fprintf(stderr, "error: %s\n", error_message);
        exit(1);
    }
}

int main() {
    char sage[10]; // Buffer to store the input string.
    fgets(sage, sizeof(sage), stdin); // Read a line of input from stdin.

    // Remove the newline character if present.
    sage[strcspn(sage, "\n")] = 0;

    // Use a switch statement to handle different cases based on the input value.
    if (strcmp(sage, "1") == 0) {
        // If the input is "1", print "Hello World".
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        // If the input is "2", initialize a variable to hold the sum of two numbers.
        int sum = 0;
        char buffer[10];

        // Loop to read two numbers from input.
        for (int i = 0; i < 2; i++) {
            fgets(buffer, sizeof(buffer), stdin); // Read the next line of input.
            int num = atoi(buffer); // Convert the input string to an integer.
            sum += num; // Add the number to the sum.
        }
        // Print the total sum of the two numbers.
        printf("%d\n", sum);
    }

    return 0;
}
