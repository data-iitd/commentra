#include <stdio.h> // Importing stdio for standard I/O
<<<<<<< HEAD
#include <stdlib.h> // Importing stdlib for general utilities
=======
#include <stdlib.h> // Importing stdlib for conversion functions
>>>>>>> 98c87cb78a (data updated)

// Function to read the next integer from input
int nextInt() {
    int i;
<<<<<<< HEAD
    scanf("%d", &i); // Read an integer from input
=======
    scanf("%d", &i); // Read the next integer from input
>>>>>>> 98c87cb78a (data updated)
    return i; // Return the read integer
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
    
    return 0; // Return success
}

// <END-OF-CODE>
