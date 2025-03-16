#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation functions
#include <stdbool.h> // Boolean type support

// Function to check if a given string represents a valid solution
bool isSolution(int columnsCount, const char *x) {
    bool allXs[columnsCount]; // Array to keep track of the presence of 'X' in each column
    for (int i = 0; i < columnsCount; i++) {
        allXs[i] = true; // Set all columns to have 'X' initially
    }

    // Iterate through the given string and mark the corresponding columns as not having 'X'
    for (int i = 0; i < 12; i++) {
        if (x[i] != 'X') {
            allXs[i % columnsCount] = false; // Update the corresponding column
        }
    }

    // Check if there is any column having 'X'
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) { // If 'X' is present in this column
            return true; // Return true as this is a valid solution
        }
    }

    return false; // If no column has 'X', then this is not a valid solution
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t); // Read the number of test cases

    for (int i = 0; i < t; i++) { // Iterate through each test case
        int possibleSolutions = 0; // Counter for the number of valid solutions
        char solutions[100] = ""; // String to store the valid solutions
        char s[13]; // Input string (12 characters + null terminator)

        scanf("%s", s); // Read the given string

        // Check if the given string represents a valid solution
        if (isSolution(12, s)) {
            strcat(solutions, " 1x12"); // Add the solution to the string
            possibleSolutions++; // Increment the counter
        }

        if (isSolution(6, s)) {
            strcat(solutions, " 2x6");
            possibleSolutions++;
        }

        if (isSolution(4, s)) {
            strcat(solutions, " 3x4");
            possibleSolutions++;
        }

        if (isSolution(3, s)) {
            strcat(solutions, " 4x3");
            possibleSolutions++;
        }

        if (isSolution(2, s)) {
            strcat(solutions, " 6x2");
            possibleSolutions++;
        }

        if (isSolution(1, s)) {
            strcat(solutions, " 12x1");
            possibleSolutions++;
        }

        // Write the output
        printf("%d%s\n", possibleSolutions, solutions); // Print the number of valid solutions and the valid solutions
    }

    return 0; // Return success
}

// <END-OF-CODE>
