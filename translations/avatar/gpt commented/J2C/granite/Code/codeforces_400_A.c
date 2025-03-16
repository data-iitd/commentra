
#include <stdio.h>
#include <string.h>

// Method to check if a given string can form a solution for a specific column count
int isSolution(int columnsCount, char* x) {
    // Create an array to track if all positions for each column are 'X'
    int allXs[columnsCount];
    memset(allXs, 1, sizeof(allXs)); // Initialize all positions as true (all 'X's)

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
    // Initialize variables to read input from the console
    char s[13];
    int t;

    // Read the number of test cases
    scanf("%d", &t);

    // Process each test case
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0; // Counter for possible solutions
        char solutions[100]; // To store the solutions
        memset(solutions, 0, sizeof(solutions)); // Initialize solutions as empty string

        // Read the input string
        scanf("%s", s);

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
