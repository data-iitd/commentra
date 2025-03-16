#include <stdio.h>
#include <stdlib.h>

// This is the main function, which is the entry point of the program.
int main() {
<<<<<<< HEAD
    int appleNum, pieceNum;

    // Read the number of apples.
    scanf("%d", &appleNum);
    
    // Read the number of pieces.
=======
    // Declare variables to hold the number of apples and pieces.
    int appleNum, pieceNum;
    
    // Read the number of apples from standard input.
    scanf("%d", &appleNum);
    
    // Read the number of pieces from standard input.
>>>>>>> 98c87cb78a (data updated)
    scanf("%d", &pieceNum);
    
    // Calculate the total pieces that can be made from the apples.
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Add the given pieces to the pieces made from apples.
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print half of the total pieces.
    printf("%d\n", totalPiece / 2);
<<<<<<< HEAD

    return 0;
=======
    
    return 0; // Indicate that the program ended successfully.
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
