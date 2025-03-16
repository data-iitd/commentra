
#include <stdio.h>
// Including the standard input/output library

int main ( void ) {
    // Main function is the entry point of the C program
    // It has a void return type and no parameters

    int n = 0 ;
    // Declaring and initializing an integer variable 'n' with zero value

    int a = 0, b = 0, c = 0 ;
    // Declaring and initializing three integer variables 'a', 'b', and 'c' with zero values

    while ( scanf ( "%d", &n ) == 1 ) a += n ;
    // Using a while loop to read and sum up the numbers from the standard input using the scanf() function
    // and adding it to the variable 'a'

    while ( scanf ( "%d", &n ) == 1 ) b += n ;
    // Using a while loop to read and sum up the numbers from the standard input (except the last one) using the scanf() function
    // and adding it to the variable 'b'

    while ( scanf ( "%d", &n ) == 1 ) c += n ;
    // Using a while loop to read and sum up the numbers from the standard input (except the last two) using the scanf() function
    // and adding it to the variable 'c'

    int x = a - b ;
    // Calculating the difference between the sum of the numbers from the standard input and storing it in a variable 'x'

    int y = b - c ;
    // Calculating the difference between the sum of the numbers from the standard input (except the last one) and storing it in a variable 'y'

    printf ( "%d\n", x ) ;
    printf ( "%d\n", y ) ;
    // Printing the values of 'x' and 'y' to the standard output using the printf() function

    return 0 ;
    // Returning 0 to indicate successful execution of the program
}

