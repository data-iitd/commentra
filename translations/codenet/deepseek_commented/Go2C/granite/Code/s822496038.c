

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to read words instead of lines.
    // sc.Split(bufio.ScanWords)
    
    // Read the number of apples.
    int appleNum = 0;
    scanf("%d", &appleNum);
    
    // Read the number of pieces.
    int pieceNum = 0;
    scanf("%d", &pieceNum);
    
    // Calculate the total pieces that can be made from the apples.
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Add the given pieces to the pieces made from apples.
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print half of the total pieces.
    printf("%d\n", totalPiece / 2);
    
    return 0;
}
