#include <stdio.h>
#include <stdlib.h>

// This is the global scanner used to read input from the standard input.
FILE *sc = stdin;

// nextInt reads a single word from the standard input, converts it to an integer, and returns it.
// It panics if the conversion fails.
int nextInt() {
    int i;
    fscanf(sc, "%d", &i);
    return i;
}

// The main function is the entry point of the program.
int main() {
    // Set the scanner to read words instead of lines.
    // Not necessary in C, but we assume the input is already set up correctly.
    
    // Read the number of apples.
    int appleNum = nextInt();
    
    // Read the number of pieces.
    int pieceNum = nextInt();
    
    // Calculate the total pieces that can be made from the apples.
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Add the given pieces to the pieces made from apples.
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print half of the total pieces.
    printf("%d\n", totalPiece / 2);
    
    return 0;
}
