#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to check if a given string can form a solution for a specific column count
int isSolution(int columnsCount, char x[]) {
    // Create an array to track if all positions for each column are 'X'
    int allXs[columnsCount];
    for (int i = 0; i < columnsCount; i++)
        allXs[i] = 1; // Initialize all positions as true (all 'X's)

    // Check each character in the string
    for (int i = 0; i < 12; i++) {
        // If the character is not 'X', mark the corresponding column as false
        if (x[i]!= 'X')
            allXs[i % columnsCount] = 0;
    }

    // Check if any column has all 'X's
    for (int i = 0; i < columnsCount; i++)
        if (allXs[i])
            return 1; // Return true if a valid solution is found

    return 0; // Return false if no valid solution is found
}

int main() {
    // Read the number of test cases
    int t;
    scanf("%d", &t);

    // Process each test case
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0; // Counter for possible solutions
        char s[13]; // To store the solutions
        scanf("%s", s); // Read the input string

        // Check for various column configurations and append valid solutions
        if (isSolution(12, s)) {
            printf(" 1x12");
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            printf(" 2x6");
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            printf(" 3x4");
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            printf(" 4x3");
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            printf(" 6x2");
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            printf(" 12x1");
            possibleSolutions++;
        }

        // Output the number of possible solutions and the solutions themselves
        printf("%d", possibleSolutions);
        printf("%s", "\n");
    }

    return 0;
}

