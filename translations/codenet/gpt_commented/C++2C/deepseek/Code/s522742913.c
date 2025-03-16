#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Declare a character array to hold the input
    char source[11];
    // Read input from the user
    fgets(source, sizeof(source), stdin);

    // Remove the newline character if present
    size_t len = strlen(source);
    if (len > 0 && source[len - 1] == '\n') {
        source[len - 1] = '\0';
    }

    // Check if the input length is valid (between 1 and 10 characters)
    if (strlen(source) > 10 || strlen(source) < 1) {
        // Return -1 if the input length is invalid
        return -1;
    }

    // Calculate the maximum number of combinations of '+' placements
    int max_i = (int)pow(2, strlen(source) - 1);

    // Initialize a variable to hold the cumulative sum of the evaluated expressions
    double sum = 0;

    // Iterate through all possible combinations of '+' placements
    for (int i = 0; i < max_i; ++i) {
        // Create a bitset to represent the current combination of '+' placements
        int bits[100] = {0};
        int bit_count = 0;
        int temp = i;
        while (temp > 0) {
            bits[bit_count++] = temp % 2;
            temp /= 2;
        }

        // Initialize a variable to hold the current number being evaluated
        double number = 0;

        // Create a working copy of the source string to manipulate
        char working[11];
        strcpy(working, source);

        // While there are still '+' placements to evaluate
        for (int j = 0; j < bit_count; ++j) {
            if (bits[j]) {
                // Convert the substring up to the current position to a double and add to sum
                sum += atof(working);
                // Update the working string to remove the processed segment
                working[j + 1] = '\0';
            }
        }
        // Add the remaining part of the working string to the sum
        sum += atof(working);
    }

    // Set the precision for output and print the final sum
    printf("%.0f\n", sum);

    return 0;
}
