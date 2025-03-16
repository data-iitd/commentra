

#include < stdio.h >
#include < stdlib.h >

int main ( void ) {
    long x ; // Declaring a variable x of type long to store the first number
    scanf ( "%ld", & x ) ; // Reading the first number from the standard input stream and storing it in the variable x

    // The following while loop runs as long as the number x is greater than zero
    while ( x > 0 ) {
        long r = x % 10 ; // Storing the last digit of the number x in the variable r

        // The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if ( 9 - r < r ) {
            // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if ( x / 10 == 0 && 9 - r == 0 ) {
                printf ( "%ld", r ) ; // Printing the last digit r to the standard output stream if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
            } else {
                printf ( "%ld", 9 - r ) ; // Printing the number 9 minus the last digit r to the standard output stream if the difference between 9 and the last digit is greater than the last digit itself
            }
        } else {
            printf ( "%ld", r ) ; // Printing the last digit r to the standard output stream if the difference between 9 and the last digit is less than or equal to the last digit itself
        }

        x = x / 10 ; // Dividing the number x by 10 to get the next digit
    }

    printf ( "\n" ) ; // Printing a new line to the standard output stream

    return 0 ; // Returning 0 to indicate successful execution of the program
}

