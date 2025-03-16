

#include <stdio.h>

int main ( void ) {
    // Initialize the variable `T` with the value of 100000000
    long T = 100000000 ;

    // Initialize the variable `S` with the value of 2
    long S = 2 ;

    // Initialize the variable `q` with the value of 3
    long q = 3 ;

    // Initialize the variable `previous` with the value of `S`
    long previous = S ;

    // Initialize the variable `answer` with the value of 0
    int answer = 0 ;

    // Start a while loop that continues as long as `previous` is less than `T`
    while ( previous < T ) {
        // Increment the value of `answer` by 1
        answer ++ ;

        // Multiply the value of `previous` by `q`
        previous *= q ;
    }

    // Print the value of `answer` to the standard output stream
    printf ( "%d\n", answer ) ;

    // End the program
    return 0 ;
}
