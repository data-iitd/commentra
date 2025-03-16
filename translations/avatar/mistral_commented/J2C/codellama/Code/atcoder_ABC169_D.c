#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    long n ; // Declaring a long integer variable to store the input
    int sqrt ; // Declaring an integer variable to store the square root of the input
    int answer = 0 ; // Declaring an integer variable to store the answer
    int i = 2 ; // Declaring an integer variable to store the current prime factor
    int count = 0 ; // Declaring an integer variable to store the number of occurrences of a prime factor
    int j = 1 ; // Declaring an integer variable to store the number of times a prime factor is counted

    // Reading the input from the user
    scanf ( "%ld", &n ) ;

    // Calculating the square root of the input
    sqrt = ( int ) sqrt ( n ) ;

    // Checking for prime factors of the input
    for ( i = 2 ; i <= sqrt ; i ++ ) {
        count = 0 ; // Initializing the counter variable to 0
        while ( 0 == ( n % i ) ) { // Checking if the input is divisible by the current prime factor
            n /= i ; // Dividing the input by the current prime factor
            count ++ ; // Incrementing the counter variable
        }

        // Calculating the contribution of the current prime factor to the answer
        for ( j = 1 ; count - j >= 0 ; j ++ ) {
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

    return 0 ;
}

