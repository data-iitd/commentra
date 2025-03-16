
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from the standard input
int nextInt() {
    // Declare a variable to store the input
    int i;
    // Read the input from the standard input
    scanf("%d", &i);
    // Return the input
    return i;
}

// Main function
int main() {
    // Read the number of apples from the standard input
    int appleNum = nextInt();
    // Read the number of pieces to be made from apples from the standard input
    int pieceNum = nextInt();
    // Calculate the number of pieces made from apples
    int pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    // Print the total number of pieces divided by 2
    printf("%d\n", totalPiece / 2);
    // End of the code
    return 0;
}

