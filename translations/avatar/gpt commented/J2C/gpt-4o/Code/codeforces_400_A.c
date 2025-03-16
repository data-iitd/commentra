#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 12

// Function to check if a given string can form a solution for a specific column count
bool isSolution(int columnsCount, const char *x) {
    // Create an array to track if all positions for each column are 'X'
    bool allXs[columnsCount];
    for (int i = 0; i < columnsCount; i++) {
        allXs[i] = true; // Initialize all positions as true (all 'X's)
    }

    // Check each character in the string
    for (int i = 0; i < MAX_LENGTH; i++) {
        // If the character is not 'X', mark the corresponding column as false
        if (x[i] != 'X') {
            allXs[i % columnsCount] = false;
        }
    }

    // Check if any column has all 'X's
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) {
            return true; // Return true if a valid solution is found
        }
    }

    return false; // Return false if no valid solution is found
}

int main() {
    // Initialize variables
    int t;
    scanf("%d", &t); // Read the number of test cases
    getchar(); // Consume the newline character after the integer input

    // Process each test case
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0; // Counter for possible solutions
        char solutions[100] = ""; // To store the solutions
        char s[MAX_LENGTH + 1]; // Input string (12 characters + null terminator)

        // Read the input string
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0; // Remove the newline character

        // Check for various column configurations and append valid solutions
        if (isSolution(12, s)) {
            strcat(solutions, " 1x12");
            possibleSolutions++;
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

        // Output the number of possible solutions and the solutions themselves
        printf("%d%s\n", possibleSolutions, solutions);
    }

    return 0;
}

// <END-OF-CODE>
