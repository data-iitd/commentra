
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    long x ; // Declaring the variable x to store the first number
    long r ; // Declaring the variable r to store the last digit of the number x
    long newNumber = 0 ; // Declaring the variable newNumber to store the final number after calculating the digits in reverse order
    int pow = 0 ; // Declaring the variable pow to 0 to be used as the power of 10 in the calculation of the new number
    int i ; // Declaring the variable i to be used as the counter in the for loop
    int size ; // Declaring the variable size to store the size of the ArrayList
    long *list ; // Declaring the variable list to store the ArrayList

    // The following while loop runs as long as the number x is greater than zero
    while ( x > 0 ) {
        r = x % 10 ; // Storing the last digit of the number x in the variable r

        // The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if ( 9 - r < r ) {
            // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if ( x / 10 == 0 && 9 - r == 0 ) {
                list [ i ] = r ; // Adding the last digit r to the ArrayList if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
            } else {
                list [ i ] = 9 - r ; // Adding the number 9 minus the last digit r to the ArrayList if the difference between 9 and the last digit is greater than the last digit itself
            }
        } else {
            list [ i ] = r ; // Adding the last digit r to the ArrayList if the difference between 9 and the last digit is less than or equal to the last digit itself
        }

        x = x / 10 ; // Dividing the number x by 10 to get the next digit
    }

    // The following for loop runs through each digit in the ArrayList and calculates the new number by adding the digit multiplied by the power of 10 to the variable newNumber
    for ( i = 0 ; i < size ; i ++ ) {
        newNumber = newNumber + list [ i ] * ( long ) pow ( 10 , pow ) ;
        pow ++ ;
    }

    printf ( "%ld\n" , newNumber ) ; // Printing the final number to the standard output stream

    return 0 ;
}

