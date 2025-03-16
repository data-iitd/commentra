

#include <stdio.h>
#include <string.h>

// Method to check if there's a column filled with 'X' characters in the given string
bool isSolution(int columnsCount, char* x) {
    bool allXs[columnsCount];
    memset(allXs, true, sizeof(allXs));
    for (int i = 0; i < 12; i++) {
        if (x[i]!= 'X') {
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

// Main method where the program starts
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0;
        char solutions[1000];
        char s[13];
        scanf("%s", s);
        if (isSolution(12, s)) {
            sprintf(solutions, " 1x12");
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            sprintf(solutions, "%s 2x6", solutions);
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            sprintf(solutions, "%s 3x4", solutions);
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            sprintf(solutions, "%s 4x3", solutions);
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            sprintf(solutions, "%s 6x2", solutions);
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            sprintf(solutions, "%s 12x1", solutions);
            possibleSolutions++;
        }
        printf("%d%s\n", possibleSolutions, solutions);
    }
    return 0;
}

