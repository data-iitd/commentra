

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Method to check if a given string represents a valid solution
bool isSolution(int columnsCount, char* x) {
    bool allXs[columnsCount]; // Initialize an array to keep track of the presence of 'X' in each column
    memset(allXs, true, sizeof(allXs)); // Set all columns to have 'X' initially

    // Iterate through the given string and mark the corresponding columns as not having 'X'
    for (int i = 0; i < 12; i++) {
        if (x[i]!= 'X') {
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
        int possibleSolutions = 0; // Initialize the counter for the number of valid solutions
        char solutions[1000]; // Initialize a string to store the valid solutions
        memset(solutions, 0, sizeof(solutions)); // Set the string to empty

        char s[13]; // Read the given string
        scanf("%s", s);

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

    return 0; // Return 0 to indicate successful execution
}

These comments should provide a clear understanding of the code logic for each block.