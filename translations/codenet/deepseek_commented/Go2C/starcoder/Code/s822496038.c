
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Set the scanner to read words instead of lines.
    scanf("%d", &appleNum);
    
    // Read the number of pieces.
    scanf("%d", &pieceNum);
    
    // Calculate the total pieces that can be made from the apples.
    pieceNumMadeFromApples = appleNum * 3
    
    // Add the given pieces to the pieces made from apples.
    totalPiece = pieceNumMadeFromApples + pieceNum
    
    // Print half of the total pieces.
    printf("%d", totalPiece / 2);
}

