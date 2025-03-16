#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int power ( long long a ) {
    // Method definition for calculating the power of a number
    int res = 0 ;          // Initializing the result variable to 0
    while ( a > 0 ) {       // While the number 'a' is greater than 0
        res ++ ;            // Increment the result variable
        a = a / 10 ;         // Divide the number by 10 to get the number of digits
    }
    return res ;           // Return the result
}

long long mult ( long long a ) {
    // Method definition for calculating the product of a number with the maximum number that can be formed using its digits
    int pow = power(a) ;    // Calculate the power of the number 'a'
    long long max = 0 ;    // Initializing the maximum variable to 0
    for ( int j = 0 ; j < pow ; ++ j ) {
        // Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max = max * 10 + 9 ; // Multiply the maximum variable with 10 and add 9 to get the next digit
    }
    return a * ( max - a ) ; // Return the product of the number 'a' and the maximum number calculated above
}

int main ( int argc, char * argv [ ] ) {
    // Main method definition

    long long l, r ;      // Declaring two variables to store the first and second number
    scanf ( "%lld %lld", &l, &r ) ; // Reading the first and second number from the console

    long long res = 0 ;    // Initializing the result variable to 0

    long long maxxes [ 10 ] ; // Creating an array'maxxes' of size 10 to store the maximum numbers that can be formed using each digit

    long long temp = 0 ;    // Initializing a temporary variable to 0

    for ( int i = 0 ; i < 10 ; ++ i ) {     // Loop to calculate and store the maximum numbers that can be formed using each digit
        temp = temp * 10 + 9 ;             // Multiply the temporary variable with 10 and add 9 to get the next digit
        maxxes [ i ] = temp / 2 * ( temp - temp / 2 ) ; // Calculate and store the maximum number in the 'i'th index of the'maxxes' array
    }

    res = max ( mult(l), res ) ;      // Calculate the product of the first number 'l' with the maximum number that can be formed using its digits and update the result variable
    res = max ( mult(r), res ) ;      // Calculate the product of the second number 'r' with the maximum number that can be formed using its digits and update the result variable

    temp = 0 ;                              // Resetting the temporary variable to 0

    for ( int i = 0 ; i < 10 ; ++ i ) {     // Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
        temp = temp * 10 + 9 ;             // Multiply the temporary variable with 10 and add 9 to get the next digit
        if ( l <= temp / 2 && temp / 2 <= r ) // Check if the range includes the maximum number that can be formed using the 'i'th digit
            res = max ( maxxes [ i ], res ) ; // Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true
    }

    printf ( "%lld", res ) ;           // Printing the final result

    return 0 ;
}

