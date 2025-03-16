
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512000

int main ( ) {
 // Initialize constants
 int BUFFER_SIZE = 512000 ;

 // Initialize scanner and print writer
 char buffer[BUFFER_SIZE] ;
 scanf( "%s", buffer ) ;
 long position = atol( buffer ) ;
 printf( "%ld\n", solve( position ) ) ;
 return 0 ;
}

// Initialize input and output streams
void init ( ) {
}

// Close input and output streams
void closeIO ( ) {
}

// Solve the problem
long solve ( long position ) {
 long nrstSeqStartIndx = 1 ; // Initialize index for the start of the next sequence

 // Binary search for the start index of the sequence containing the position
 while ( getValueAtIndex( nrstSeqStartIndx * 2 ) < position ) {
 nrstSeqStartIndx *= 2 ; // Multiply index by 2
 }

 // Linear search for the end index of the sequence containing the position
 while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ) {
 nrstSeqStartIndx++ ; // Increment index
 }

 // Print the answer
 long startIndex = getValueAtIndex( nrstSeqStartIndx ) ; // Get the start index of the sequence
 return ( position - startIndex ) + 1 ; // Print the length of the sequence
}

// Get the value at a given index
long getValueAtIndex ( long index ) {
 return 1 + ( ( index - 1 ) * index / 2 ) ; // Calculate the value at the given index
}

