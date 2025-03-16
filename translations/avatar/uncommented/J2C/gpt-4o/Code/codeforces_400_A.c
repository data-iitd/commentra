#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSolution(int columnsCount, const char *x) {
    bool allXs[columnsCount];
    for (int i = 0; i < columnsCount; i++) {
        allXs[i] = true;
    }
    for (int i = 0; i < 12; i++) {
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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int possibleSolutions = 0;
        char solutions[100] = ""; // Buffer to hold solutions
        char s[13]; // Buffer for input string (12 characters + null terminator)
        scanf("%s", s);
        
        if (isSolution(12, s)) {
            possibleSolutions++;
            strcat(solutions, " 1x12");
        }
        if (isSolution(6, s)) {
            possibleSolutions++;
            strcat(solutions, " 2x6");
        }
        if (isSolution(4, s)) {
            possibleSolutions++;
            strcat(solutions, " 3x4");
        }
        if (isSolution(3, s)) {
            possibleSolutions++;
            strcat(solutions, " 4x3");
        }
        if (isSolution(2, s)) {
            possibleSolutions++;
            strcat(solutions, " 6x2");
        }
        if (isSolution(1, s)) {
            possibleSolutions++;
            strcat(solutions, " 12x1");
        }
        
        printf("%d%s\n", possibleSolutions, solutions);
    }
    return 0;
}

// <END-OF-CODE>
