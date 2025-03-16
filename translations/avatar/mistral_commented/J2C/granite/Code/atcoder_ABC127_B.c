

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char * argv [ ] ) {
    // Creating a FILE pointer for reading input and a FILE pointer for writing output
    FILE * in = stdin ;  // Assigning the standard input stream to the input file pointer
    FILE * out = stdout ;  // Assigning the standard output stream to the output file pointer

    // Reading input variables from the user
    int r ;  // Declaring the integer 'r' to store the first input
    int d ;  // Declaring the integer 'd' to store the second input
    long x ;  // Declaring the long integer 'x' to store the third input

    // Reading the first integer 'r' from the user
    fscanf ( in, "%d", & r ) ;

    // Reading the second integer 'd' from the user
    fscanf ( in, "%d", & d ) ;

    // Reading the long integer 'x' from the user
    fscanf ( in, "%ld", & x ) ;

    // Running the loop for 10 iterations
    for ( int i = 0 ; i < 10 ; ++ i ) {
        // Multiplying 'r' with 'x' and subtracting 'd' from it
        x = r * x - d ;

        // Writing the result to the output stream
        fprintf ( out, "%ld\n", x ) ;
    }

    // Ending the program
    return EXIT_SUCCESS ;
}

