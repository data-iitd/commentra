
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring the number of elements in the list
    long sum = 0 ; // Declaring the sum variable to 0
    long * list = NULL ; // Declaring a pointer to an array of long type to store the list
    long * odd = NULL ; // Declaring a pointer to an array of long type to store the odd numbers
    int i = 0 ; // Declaring the iterator variable to 0

    scanf ( "%d", &n ) ; // Reading the number of elements in the list from the standard input

    list = ( long * ) malloc ( n * sizeof ( long ) ) ; // Allocating memory to store n elements in the list
    odd = ( long * ) malloc ( n * sizeof ( long ) ) ; // Allocating memory to store n elements in the odd ArrayList

    for ( i = 0 ; i < n ; i ++ ) // Iterating through the input to add each element to the list
        scanf ( "%ld", &list [ i ] ) ;

    for ( i = 0 ; i < n ; i ++ ) { // Iterating through each element in the list
        if ( list [ i ] % 2 == 0 ) // Checking if the current element is even
            sum += list [ i ] ; // Adding the even number to the sum
        else
            odd [ i ] = list [ i ] ; // Adding the odd number to the odd ArrayList
    }

    qsort ( odd, n, sizeof ( long ), compare ) ; // Sorting the odd ArrayList in ascending order

    for ( i = 0 ; i < n ; i ++ ) // Iterating through each odd number in the sorted odd ArrayList
        sum += odd [ i ] ; // Adding the odd number to the sum

    if ( n % 2 != 0 ) // Checking if the size of the odd ArrayList is odd
        sum -= odd [ 0 ] ; // Subtracting the first odd number if the size is odd

    printf ( "%ld\n", sum ) ; // Printing the final sum to the standard output

    free ( list ) ; // Freeing the memory allocated to the list
    free ( odd ) ; // Freeing the memory allocated to the odd ArrayList

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

int compare ( const void * a, const void * b ) { // Defining the compare function to sort the odd ArrayList in ascending order
    return ( * ( long * ) a - * ( long * ) b ) ; // Returning the difference between the two elements to sort the odd ArrayList in ascending order
}

