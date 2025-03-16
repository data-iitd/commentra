
#include <stdio.h> // Including the standard input/output library
#include <math.h> // Including the mathematical library

int main ( void ) { // Starting the main function
    long n ; // Declaring a long integer variable for the given number
    scanf ( "%ld", &n ) ; // Reading a long integer value from user input

    // Calculating the square root of the given number
    int sqrt = ( int ) sqrt ( n ) ;

    // Initializing the answer variable to 0
    int answer = 0 ;

    // Checking for prime factors of the given number
    for ( int i = 2 ; i <= sqrt ; i ++ ) { // Starting a for loop to check for prime factors
        int count = 0 ; // Initializing a counter variable to count the number of occurrences of a prime factor
        while ( 0 == ( n % i ) ) { // Checking if the given number is divisible by the current prime factor
            n /= i ; // Dividing the given number by the current prime factor
            count ++ ; // Incrementing the counter variable
        }

        // Calculating the contribution of the current prime factor to the answer
        for ( int j = 1 ; count - j >= 0 ; j ++ ) {
            count -= j ;
            answer ++ ;
        }
    }

    // Checking for the remaining prime factor (if any)
    if ( n > 1 ) {
        answer ++ ;
    }

    // Printing the result
    printf ( "%d\n", answer ) ;

    return 0 ; // Returning 0 to indicate successful execution
}

