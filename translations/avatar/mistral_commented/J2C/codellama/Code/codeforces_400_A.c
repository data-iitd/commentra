
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to check if a given string represents a valid solution
int isSolution(int columnsCount, char *x) {
    int allXs[columnsCount]; // Initialize an array to keep track of the presence of 'X' in each column
    memset(allXs, 1, columnsCount * sizeof(int)); // Set all columns to have 'X' initially

    // Iterate through the given string and mark the corresponding columns as not having 'X'
    for (int i = 0; i < 12; i++) {
        if (x[i] != 'X') {
            allXs[i % columnsCount] = 0; // Update the corresponding column
        }
    }

    // Check if there is any column having 'X'
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) { // If 'X' is present in this column
            return 1; // Return true as this is a valid solution
        }
    }

    return 0; // If no column has 'X', then this is not a valid solution
}

int main() {
    int t; // Initialize the number of test cases
    scanf("%d", &t); // Read the number of test cases

    for (int i = 0; i < t; i++) { // Iterate through each test case
        int possibleSolutions = 0; // Initialize the counter for the number of valid solutions
        char solutions[100]; // Initialize a string to store the valid solutions

        char s[13]; // Initialize a string to store the given string
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
        printf("%d ", possibleSolutions); // Write the number of valid solutions
        printf("%s\n", solutions); // Write the valid solutions
    }

    return 0;
}

