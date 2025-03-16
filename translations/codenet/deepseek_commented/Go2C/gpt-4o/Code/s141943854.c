#include <stdio.h>  // For standard input and output
<<<<<<< HEAD
#include <stdlib.h> // For memory allocation and conversion functions

// Function to check for errors and exit if any occur
void check(int condition) {
    if (condition) {
        fprintf(stderr, "error: an error occurred\n");
=======
#include <stdlib.h> // For atoi function
#include <string.h> // For string operations

// Function to check for errors and print a message
void check(int condition, const char *message) {
    if (condition) {
        fprintf(stderr, "error: %s\n", message);
>>>>>>> 98c87cb78a (data updated)
        exit(EXIT_FAILURE);
    }
}

int main() {
<<<<<<< HEAD
    char input[10]; // Buffer to store user input
    fgets(input, sizeof(input), stdin); // Read input from standard input
    int sage = atoi(input); // Convert input string to integer

    switch (sage) {
        case 1:
            printf("Hello World\n"); // Print "Hello World" if input is "1"
            break;
        case 2: {
            int sum = 0; // Declare sum variable to store the sum of two integers
            for (int i = 0; i < 2; i++) {
                fgets(input, sizeof(input), stdin); // Read input from standard input
                int num = atoi(input); // Convert string to integer
                sum += num; // Add the integer to the sum
            }
            printf("%d\n", sum); // Print the sum of the two integers
            break;
        }
        default:
            fprintf(stderr, "Invalid input\n"); // Handle invalid input
            break;
=======
    char sage[10]; // Buffer to store input

    // Read input from standard input
    fgets(sage, sizeof(sage), stdin);
    sage[strcspn(sage, "\n")] = 0; // Remove newline character

    // Check the value of sage
    if (strcmp(sage, "1") == 0) {
        printf("Hello World\n"); // Print "Hello World" if input is "1"
    } else if (strcmp(sage, "2") == 0) {
        int sum = 0; // Declare sum variable to store the sum of two integers
        for (int i = 0; i < 2; i++) {
            char input[10]; // Buffer to store each number input
            fgets(input, sizeof(input), stdin); // Read input from standard input
            int num = atoi(input); // Convert string to integer
            sum += num; // Add the integer to the sum
        }
        printf("%d\n", sum); // Print the sum of the two integers
>>>>>>> 98c87cb78a (data updated)
    }

    return 0; // Return success
}

// <END-OF-CODE>
