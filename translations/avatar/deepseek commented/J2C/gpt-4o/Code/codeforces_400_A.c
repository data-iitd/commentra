#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 12

// Function to check if there's a column filled with 'X' characters in the given string
bool isSolution(int columnsCount, const char *x) {
    bool allXs[columnsCount];
    for (int i = 0; i < columnsCount; i++) {
        allXs[i] = true;
    }
    
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (x[i] != 'X') {
            allXs[i % columnsCount] = false;
        }
    }
    
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) {
            return true;
        }
    }
    return false;
}

// Main function where the program starts
int main() {
    int t;
    scanf("%d", &t);
    getchar(); // To consume the newline character after the integer input

    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0;
        char solutions[100] = ""; // Buffer to store solutions
        char s[MAX_LENGTH + 1]; // Input string (12 characters + null terminator)
        
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0; // Remove newline character from the input string

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

        printf("%d%s\n", possibleSolutions, solutions);
    }

    return 0;
}

// <END-OF-CODE>
