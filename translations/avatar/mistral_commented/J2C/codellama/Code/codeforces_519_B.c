#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Main method is the entry point of the C program
    // It has a void return type and no parameters
    // We are using the scanf() function to read input from the standard input
    // and the printf() function to write the output to the standard output

    int n ;
    // Declaring and initializing an integer variable 'n'

    scanf ( "%d" , &n ) ;
    // Reading the number of test cases (n) from the input using the scanf() function

    int a = 0 , b = 0 , c = 0 ;
    // Declaring and initializing three integer variables a, b, and c with zero values

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        a += x ;
    }
    // Using a for loop to read and sum up the first number in each test case using the scanf() function
    // and adding it to the variable 'a'

    for ( int i = 0 ; i < n - 1 ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        b += x ;
    }
    // Using a for loop to read and sum up the second number in each test case (except the last one) using the scanf() function
    // and adding it to the variable 'b'

    for ( int i = 0 ; i < n - 2 ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        c += x ;
    }
    // Using a for loop to read and sum up the third number in each test case (except the last two) using the scanf() function
    // and adding it to the variable 'c'

    int x = a - b ;
    // Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    int y = b - c ;
    // Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    printf ( "%d\n" , x ) ;
    printf ( "%d\n" , y ) ;
    // Printing the values of 'x' and 'y' to the standard output using the printf() function

    return 0 ;
}

