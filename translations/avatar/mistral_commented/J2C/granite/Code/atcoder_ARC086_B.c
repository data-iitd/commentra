

#include < stdio.h > // Including the standard input/output library
#include < stdlib.h > // Including the standard library library

int main ( ) { // Starting point of the program, main method with an empty argument list
    int n ; // Declaring the variable n of type int
    scanf ( "%d", & n ) ; // Reading the first integer from the standard input stream and assigning it to the variable n
    int a [ n ] ; // Declaring an integer array of size n
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        scanf ( "%d", & a [ i ] ) ; // Reading an integer from the standard input stream and assigning it to the current element of the array a
    }
    int m = 0 ; // Initializing the variable m to 0
    for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
        if ( abs ( a [ m ] ) > abs ( a [ i ] ) ) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
            m = i ; // Assigning the index of the smallest absolute value to the variable m
        }
    }
    int r [ n - 1 ] [ 2 ] ; // Declaring an integer array of size n-1 to store the pairs (i, i+1)
    int k = 0 ; // Initializing the variable k to 0
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        if ( a [ m ] >= 0 ^ a [ i ] >= 0 ) { // Checking if the signs of the elements at indices m and i are different
            r [ k ] [ 0 ] = i + 1 ; // Assigning the value of i+1 to the first element of the pair (i, i+1)
            r [ k ] [ 1 ] = i + 2 ; // Assigning the value of i+2 to the second element of the pair (i, i+1)
            ++ k ; // Incrementing the variable k by 1
        }
    }
    if ( a [ m ] >= 0 ) { // Checking if the smallest absolute value is positive
        for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
            r [ k ] [ 0 ] = i ; // Assigning the value of i to the first element of the pair (i, i+1)
            r [ k ] [ 1 ] = i + 1 ; // Assigning the value of i+1 to the second element of the pair (i, i+1)
            ++ k ; // Incrementing the variable k by 1
        }
    } else { // If the smallest absolute value is negative
        for ( int i = n ; i > 1 ; -- i ) { // Starting a for loop to iterate through the array a from the last element to the second one
            r [ k ] [ 0 ] = i ; // Assigning the value of i to the first element of the pair (i, i-1)
            r [ k ] [ 1 ] = i - 1 ; // Assigning the value of i-1 to the second element of the pair (i, i-1)
            ++ k ; // Incrementing the variable k by 1
        }
    }
    printf ( "%d\n", k ) ; // Printing the size of the array r to the standard output stream
    for ( int i = 0 ; i < k ; ++ i ) { // Starting a for loop to iterate through the array r from the first element to the last one
        printf ( "%d %d\n", r [ i ] [ 0 ], r [ i ] [ 1 ] ) ; // Printing each pair in the array r to the standard output stream
    }
    return 0 ; // Returning 0 to indicate successful program execution
}

