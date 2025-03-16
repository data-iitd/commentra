#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if there's a column filled with 'X' characters in the given string
bool isSolution(int columnsCount, char* x) {
    bool allXs[columnsCount];
    memset(allXs, true, columnsCount * sizeof(bool));
    for (int i = 0; i < 12; i++) {
        if (x[i] != 'X')
            allXs[i % columnsCount] = false;
    }
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i])
            return true;
    }
    return false;
}

// Main function where the program starts
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0;
        char solutions[100];
        char s[13];
        scanf("%s", s);
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
