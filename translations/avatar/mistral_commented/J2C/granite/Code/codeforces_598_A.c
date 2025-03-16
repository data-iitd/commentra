
#include <stdio.h> // Including the standard input/output header file

int main ( void ) { // Defining the main function that runs the program

    int q ; // Declaring an integer variable 'q' to store the number of test cases

    scanf ( "%d", & q ) ; // Reading the number of test cases from the console using the scanf function

    while ( q -- > 0 ) { // Starting a while loop that runs q times

        int n ; // Declaring an integer variable 'n' to store the input integer

        scanf ( "%d", & n ) ; // Reading the integer 'n' from the console using the scanf function

        long s = 0 ; // Initializing the long variable's' with zero value

        int x = ( int ) ( log ( n ) / log ( 2 ) ) ; // Calculating the integer 'x' using the logarithmic formula

        x ++ ; // Incrementing the value of 'x' by 1

        s = - 1 * ( long ) pow ( 2, x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) pow ( 2, x ) ; // Calculating the value of's' using the given formula

        printf ( "%ld\n", s ) ; // Printing the value of's' to the console using the printf function
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}

