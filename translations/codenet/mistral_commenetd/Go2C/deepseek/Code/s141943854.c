#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for errors and exit with error message if any
void check(int error) {
    if (error != 0) {
        fprintf(stderr, "error: %d\n", error);
        exit(1);
    }
}

// Main function
int main() {
    // Initialize a buffer to read from standard input
    char sage[10];
    char buffer[10];
    int sum = 0;

    // Read the first line from standard input
    fgets(sage, sizeof(sage), stdin);

    // Remove newline character if present
    sage[strcspn(sage, "\n")] = 0;

    // Use a switch statement to determine the action based on the first line read
    if (strcmp(sage, "1") == 0) {
        // Print "Hello World" if the first line is "1"
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        // Use a for loop to read and sum two numbers
        for (int i = 0; i < 2; i++) {
            // Read the next line from standard input
            fgets(buffer, sizeof(buffer), stdin);

            // Convert the next line to an integer and store it in a variable named 'num'
            int num = atoi(buffer);

            // Add the current number to the sum
            sum += num;
        }

        // Print the sum of the two numbers
        printf("%d\n", sum);
    }

    return 0;
}

