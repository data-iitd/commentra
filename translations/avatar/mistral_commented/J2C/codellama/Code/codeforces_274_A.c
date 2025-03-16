
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring the integer variable n
    long k ; // Declaring the long integer variable k

    scanf ( "%d %ld", &n, &k ) ; // Reading the integer value n and the long integer value k from the standard input stream

    long *arr = ( long * ) malloc ( n * sizeof ( long ) ) ; // Creating an array named arr of length n to store long integer values
    HashSet *set = ( HashSet * ) malloc ( sizeof ( HashSet ) ) ; // Creating an empty HashSet named set to store unique long integer values

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array arr from index 0 to n-1
        scanf ( "%ld", &arr [ i ] ) ; // Reading a long integer value from the standard input stream and storing it in the arr[i] index
    }

    qsort ( arr, n, sizeof ( long ), compare ) ; // Sorting the arr array in ascending order using the qsort() function

    int count = 0 ; // Initializing the count variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the sorted arr array from index 0 to n-1
        if ( arr [ i ] % k != 0 ) { // Checking if the arr[i] value is not divisible by k
            count ++ ; // Incrementing the count variable if the condition is true
            set.add ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
        } else if ( ! set.contains ( arr [ i ] / k ) ) { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
            count ++ ; // Incrementing the count variable if the condition is true
            set.add ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
        }
    }

    printf ( "%d\n", count ) ; // Printing the count value to the standard output stream

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

int compare ( const void *a, const void *b ) { // Defining the compare function to sort the arr array in ascending order
    return ( * ( long * ) a - * ( long * ) b ) ; // Returning the difference between the two long integer values
}

