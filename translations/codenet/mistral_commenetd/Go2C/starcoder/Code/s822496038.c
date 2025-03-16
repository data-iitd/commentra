
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int appleNum, pieceNum, pieceNumMadeFromApples, totalPiece;
    // Read the number of apples from the standard input
    scanf("%d", &appleNum);
    // Read the number of pieces to be made from apples from the standard input
    scanf("%d", &pieceNum);
    // Calculate the number of pieces made from apples
    pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    totalPiece = pieceNumMadeFromApples + pieceNum;
    // Print the total number of pieces divided by 2
    printf("%d", totalPiece / 2);
    // End of the code
    return 0;
}

