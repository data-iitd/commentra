

#include <stdio.h> // Including the header file for input/output operations

// A helper function to find the greatest common divisor of two numbers
long getGCD ( long a, long b ) {
    if ( b == 0 ) { // Base case: if b is 0, return a as the gcd
        return a ;
    } else {
        return getGCD ( b, a % b ) ; // Recursive call: finding the gcd of b and the remainder of a divided by b
    }
}

int main ( ) { // Starting the main function
    long n, m ; // Declaring two variables n and m to store the input values
    scanf ( "%ld %ld", & n, & m ) ; // Reading the input values n and m from the standard input

    long a [ n ] ; // Declaring an array a of size n to store the input values
    for ( long i = 0 ; i < n ; i ++ ) {
        scanf ( "%ld", & a [ i ] ) ; // Reading an integer value and storing it in the array
    }

    long gcd ; // Declaring a variable gcd to store the greatest common divisor
    long lcd = 1 ; // Declaring and initializing a variable lcm to store the least common multiple

    // Finding the least common multiple of all array elements
    for ( long i = 0 ; i < n ; i ++ ) {
        gcd = getGCD ( lcd, a [ i ] ) ; // Finding the greatest common divisor of lcm and the current array element
        lcd = lcd * a [ i ] / gcd ; // Updating the value of lcm

        // Checking if lcm is greater than m
        if ( lcd > m ) {
            printf ( "0" ) ; // If true, printing 0 and returning from the function
            return 0 ;
        }
    }

    // Checking if any array element is a factor of lcm
    for ( long i = 0 ; i < n ; i ++ ) {
        if ( ( lcd / a [ i ] ) % 2 == 0 ) { // Checking if the remainder of lcm divided by the current array element is 0 and even
            printf ( "0" ) ; // If true, printing 0 and returning from the function
            return 0 ;
        }
    }

    // Printing the result
    printf ( "%ld", ( m / lcd + 1 ) / 2 ) ; // Printing the result

    return 0 ; // Returning 0 to indicate successful execution of the program
}

