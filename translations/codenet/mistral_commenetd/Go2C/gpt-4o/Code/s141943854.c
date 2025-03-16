#include <stdio.h>
#include <stdlib.h>

// Function to check for errors and exit with error message if any
void check(int condition, const char *message) {
    if (condition) {
        fprintf(stderr, "error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Initialize a variable to store the input
    char sage[10];

    // Read the first line from standard input
    fgets(sage, sizeof(sage), stdin);

    // Remove the newline character from the input
    sage[strcspn(sage, "\n")] = 0;

    // Use a switch statement to determine the action based on the first line read
    if (strcmp(sage, "1") == 0) {
        // Print "Hello World" if the first line is "1"
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        // Initialize a variable named 'sum' to store the sum of two numbers
        int sum = 0;

        // Use a for loop to read and sum two numbers
        for (int i = 0; i < 2; i++) {
            // Initialize a variable to store the number
            int num;

            // Read the next line from standard input
            char buffer[10];
            fgets(buffer, sizeof(buffer), stdin);

            // Convert the next line to an integer and store it in 'num'
            num = atoi(buffer);

            // Add the current number to the sum
            sum += num;
        }

        // Print the sum of the two numbers
        printf("%d\n", sum);
    }

    return 0;
}

// <END-OF-CODE>
