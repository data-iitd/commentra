
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N ; // Declaring a variable named N to store the number of elements in the list
    long x ; // Declaring a variable named x to store the target value

    scanf ( "%d", &N ) ; // Reading the number of elements in the list from the standard input
    scanf ( "%ld", &x ) ; // Reading the target value from the standard input

    long *sweet = ( long * ) malloc ( N * sizeof ( long ) ) ; // Creating an array of long type named sweet to store the elements

    for ( int i = 0 ; i < N ; i ++ ) { // A for loop to read and add N elements to the array
        long a ; // Declaring a variable named a to store the current element
        scanf ( "%ld", &a ) ; // Reading an element from the standard input
        sweet [ i ] = a ; // Adding the element to the array
    }

    qsort ( sweet, N, sizeof ( long ), compare ) ; // Sorting the array in ascending order using the qsort() function

    int num = 0 ; // Initializing a variable named num to keep track of the number of elements that can be subtracted from x

    for ( int i = 0 ; i < N ; i ++ ) { // A for loop to find the number of elements that can be subtracted from x
        if ( x - sweet [ num ] >= 0 ) { // Checking if x is greater than or equal to the current element in the array
            x = x - sweet [ num ] ; // Subtracting the current element from x
            num ++ ; // Incrementing the num variable
        } else { // If x is less than the current element in the array
            break ; // Exiting the for loop
        }
    }

    if ( ( num == N ) && ( x > 0 ) ) { // Checking if all the elements in the array have been subtracted from x and x is still greater than 0
        num -= 1 ; // Decrementing the num variable by 1 as the last element that was subtracted from x is not included in the count
    }

    printf ( "%d\n", num ) ; // Printing the number of elements that can be subtracted from x

    free ( sweet ) ; // Freeing the memory allocated to the array

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

int compare ( const void *a, const void *b ) { // Defining a function named compare to compare two elements in the array
    return ( * ( long * ) a - * ( long * ) b ) ; // Returning the difference between the two elements
}

