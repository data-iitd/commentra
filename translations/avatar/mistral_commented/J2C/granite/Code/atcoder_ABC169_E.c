

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int num = 998244353 ;  // Initializing a variable 'num' with a value
    char buffer [ 1000000 ] ;  // Creating a character array to store the input line
    fgets ( buffer, 1000000, stdin ) ;  // Reading the input line from the standard input stream
    int n = atoi ( buffer ) ;  // Converting the input line to an integer and storing it in the variable 'n'

    int * a = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Dynamically allocating memory for the first array
    int * b = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Dynamically allocating memory for the second array

    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the test cases
        fgets ( buffer, 1000000, stdin ) ;  // Reading the input line from the standard input stream
        char * token = strtok ( buffer, " " ) ;  // Tokenizing the input line to extract the first array element
        a [ i ] = atoi ( token ) ;  // Converting the first array element to an integer and storing it in the array
        token = strtok ( NULL, " " ) ;  // Tokenizing the input line to extract the second array element
        b [ i ] = atoi ( token ) ;  // Converting the second array element to an integer and storing it in the array
    }

    qsort ( a, n, sizeof ( int ), cmpfunc ) ;  // Sorting the first array in ascending order
    qsort ( b, n, sizeof ( int ), cmpfunc ) ;  // Sorting the second array in ascending order

    if ( n % 2 == 1 ) {  // Checking if the number of test cases is odd
        printf ( "%d\n", b [ n / 2 ] - a [ n / 2 ] + 1 ) ;  // Calculating and printing the answer for odd number of test cases
    } else {
        double b = ( a [ n / 2 ] + a [ n / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the first array
        double c = ( b [ n / 2 ] + b [ n / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the second array
        printf ( "%d\n", ( int ) ( 2 * ( c - b ) + 1 ) ) ;  // Calculating and printing the answer for even number of test cases
    }

    free ( a ) ;  // Freeing the memory allocated for the first array
    free ( b ) ;  // Freeing the memory allocated for the second array

    return 0 ;  // Returning 0 to indicate successful execution of the program
}

int cmpfunc ( const void * a, const void * b ) {  // Function to compare two integers and return their difference
    return ( *( int * ) a - *( int * ) b ) ;  // Comparing the two integers and returning their difference
}

