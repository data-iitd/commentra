#include <stdio.h>

int main() {
    int appleNum, pieceNum;
    
    // Read the number of apples
    scanf("%d", &appleNum);
    // Read the number of pieces
    scanf("%d", &pieceNum);
    
    // Calculate the number of pieces made from apples
    int pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print the result
    printf("%d\n", totalPiece / 2);
    
    return 0;
}

// <END-OF-CODE>
