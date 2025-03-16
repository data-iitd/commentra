
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSolution(int columnsCount, char *x) {
    int allXs[columnsCount];
    memset(allXs, 1, columnsCount);
    for (int i = 0; i < 12; i++) {
        if (x[i] != 'X') allXs[i % columnsCount] = 0;
    }
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) return 1;
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0;
        char s[13];
        scanf("%s", s);
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
        printf("%d\n", possibleSolutions);
    }
    return 0;
}

