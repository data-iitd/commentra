#include <stdio.h>

int main() {
    // Variables to hold the number of apples and pieces
    int appleNum, pieceNum;
    
    // Read the number of apples from standard input
    scanf("%d", &appleNum);
    // Read the number of pieces to be made from apples from standard input
    scanf("%d", &pieceNum);
    
    // Calculate the number of pieces made from apples
    int pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print the total number of pieces divided by 2
    printf("%d\n", totalPiece / 2);
    
    return 0;
}
// <END-OF-CODE>
