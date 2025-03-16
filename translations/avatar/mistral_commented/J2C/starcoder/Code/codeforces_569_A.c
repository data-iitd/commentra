
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Initialize a variable `T` to store the value of the first integer
    int T ;

    // Initialize a variable `S` to store the value of the second integer
    int S ;

    // Initialize a variable `q` to store the value of the third integer
    int q ;

    // Initialize a variable `previous` to store the value of `S`
    long previous = S ;

    // Initialize a variable `answer` to store the value of 0
    int answer = 0 ;

    // Read the first integer `T` from the standard input stream
    scanf ( "%d", &T ) ;

    // Read the second integer `S` from the standard input stream
    scanf ( "%d", &S ) ;

    // Read the third integer `q` from the standard input stream
    scanf ( "%d", &q ) ;

    // Start a while loop that continues as long as `previous` is less than `T`
    while ( previous < T ) {
        // Increment the value of `answer` by 1
        answer ++ ;

        // Multiply the value of `previous` by `q`
        previous *= q ;
    }

    // Print the value of `answer` to the standard output stream
    printf ( "%d", answer ) ;

    // Return 0 to the operating system
    return 0 ;
}

