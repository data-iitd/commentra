#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from input
int nextInt() {
    char *str;
    int i;
    scanf("%ms", &str);
    i = atoi(str);
    free(str);
    return i;
}

int main() {
    // Read the number of apples and pieces from input
    int appleNum = nextInt();
    int pieceNum = nextInt();

    // Calculate the number of pieces made from apples (3 pieces per apple)
    int pieceNumMadeFromApples = appleNum * 3;

    // Calculate the total number of pieces (pieces from apples + existing pieces)
    int totalPiece = pieceNumMadeFromApples + pieceNum;

    // Output the total number of complete sets of 2 pieces
    printf("%d\n", totalPiece / 2);

    return 0;
}

