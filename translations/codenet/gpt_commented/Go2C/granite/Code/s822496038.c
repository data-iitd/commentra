
#include <stdio.h>
#include <stdlib.h>

int main() {
    int appleNum, pieceNum, pieceNumMadeFromApples, totalPiece;
    
    // Read the number of apples and pieces from input
    scanf("%d %d", &appleNum, &pieceNum);
    
    // Calculate the number of pieces made from apples (3 pieces per apple)
    pieceNumMadeFromApples = appleNum * 3;
    
    // Calculate the total number of pieces (pieces from apples + existing pieces)
    totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Output the total number of complete sets of 2 pieces
    printf("%d\n", totalPiece / 2);
    
    return 0;
}
