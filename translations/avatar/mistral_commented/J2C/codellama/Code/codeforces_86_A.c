
#include <stdio.h>
#include <stdlib.h>

int power ( long a ) {
    // Method definition for calculating the power of a number
    int res = 0 ;          // Initializing the result variable to 0
    while ( a > 0 ) {       // While the number 'a' is greater than 0
        res ++ ;            // Increment the result variable
        a = a / 10 ;         // Divide the number by 10 to get the number of digits
    }
    return res ;           // Return the result
}

long mult ( long a ) {
    // Method definition for calculating the product of a number with the maximum number that can be formed using its digits
    int pow = power(a) ;    // Calculate the power of the number 'a'
    long max = 0 ;          // Initializing the maximum variable to 0
    for ( int j = 0 ; j < pow ; ++ j ) {
        // Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max = max * 10 + 9 ; // Multiply the maximum variable with 10 and add 9 to get the next digit
    }
    return a * ( max - a ) ; // Return the product of the number 'a' and the maximum number calculated above
}

int main ( ) {
    // Main method definition

    long l, r ;             // Declaring the first and second numbers 'l' and 'r'

    scanf ( "%ld %ld" , &l , &r ) ; // Reading the first and second numbers 'l' and 'r' from the console

    long res = 0 ;          // Initializing the result variable to 0

    long maxxes [ 10 ] ;    // Creating an array 'maxxes' of size 10 to store the maximum numbers that can be formed using each digit

    long temp = 0 ;         // Initializing a temporary variable to 0

    for ( int i = 0 ; i < 10 ; ++ i ) {     // Loop to calculate and store the maximum numbers that can be formed using each digit
        temp = temp * 10 + 9 ;             // Multiply the temporary variable with 10 and add 9 to get the next digit
        maxxes [ i ] = temp / 2 * ( temp - temp / 2 ) ; // Calculate and store the maximum number in the 'i'th index of the 'maxxes' array
    }

    res = mult(l) > res ? mult(l) : res ;      // Calculate the product of the first number 'l' with the maximum number that can be formed using its digits and update the result variable
    res = mult(r) > res ? mult(r) : res ;      // Calculate the product of the second number 'r' with the maximum number that can be formed using its digits and update the result variable

    temp = 0 ;                              // Resetting the temporary variable to 0

    for ( int i = 0 ; i < 10 ; ++ i ) {     // Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
        temp = temp * 10 + 9 ;             // Multiply the temporary variable with 10 and add 9 to get the next digit
        if ( l <= temp / 2 && temp / 2 <= r ) // Check if the range includes the maximum number that can be formed using the 'i'th digit
            res = maxxes [ i ] > res ? maxxes [ i ] : res ; // Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true
    }

    printf ( "%ld" , res ) ;           // Printing the final result

    return 0 ;                         // Returning 0 to indicate that the program executed successfully
}

