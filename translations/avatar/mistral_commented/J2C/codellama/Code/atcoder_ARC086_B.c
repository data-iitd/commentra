
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n ; // Declaring the variable n
    scanf ( "%d" , &n ) ; // Reading the first integer from the standard input stream and assigning it to the variable n
    int * a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Creating an integer array of size n
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        scanf ( "%d" , &a [ i ] ) ; // Reading the integers from the standard input stream and assigning them to the elements of the array a
    }
    int m = 0 ; // Initializing the variable m to 0
    for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
        if ( abs ( a [ m ] ) < abs ( a [ i ] ) ) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
            m = i ; // Assigning the index of the smallest absolute value to the variable m
        }
    }
    int r = 0 ; // Initializing the variable r to 0
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        if ( a [ m ] >= 0 ^ a [ i ] >= 0 ) { // Checking if the signs of the elements at indices m and i are different
            ++ r ; // Incrementing the variable r
        }
    }
    if ( a [ m ] >= 0 ) { // Checking if the smallest absolute value is positive
        for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
            ++ r ; // Incrementing the variable r
        }
    } else { // If the smallest absolute value is negative
        for ( int i = n ; i > 1 ; -- i ) { // Starting a for loop to iterate through the array a from the last element to the second one
            ++ r ; // Incrementing the variable r
        }
    }
    printf ( "%d\n" , r ) ; // Printing the value of the variable r to the standard output stream
    for ( int i = 0 ; i < r ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        printf ( "%d %d\n" , i + 1 , i + 2 ) ; // Printing each pair in the array a to the standard output stream
    }
    return 0 ; // Returning 0 to the operating system
}
