#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from input
int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
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
