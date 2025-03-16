

#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library
#include <string.h> // Including the string library
#include <math.h> // Including the mathematical library
#include <time.h> // Including the time library
#include <stdbool.h> // Including the boolean library
#include <assert.h> // Including the assert library

int main ( int argc, char * argv [ ] ) { // Defining the main function with command-line arguments argc and argv
    int n ; // Declaring an integer variable n to store the first integer value
    long k ; // Declaring a long integer variable k to store the second integer value
    long arr [ 100000 ] ; // Declaring an array named arr of length 100000 to store long integer values
    bool set [ 100000 ] ; // Declaring an array named set of length 100000 to store boolean values
    int count = 0 ; // Declaring an integer variable count to store the count of unique elements in the array

    scanf ( "%d %ld", & n, & k ) ; // Reading the first integer value n and the second integer value k from the standard input stream

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array arr from index 0 to n-1
        scanf ( "%ld", & arr [ i ] ) ; // Reading a long integer value from the standard input stream and storing it in the arr[i] index
    }

    qsort ( arr, n, sizeof ( long ), cmpfunc ) ; // Sorting the arr array in ascending order using the qsort() function

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the sorted arr array from index 0 to n-1
        if ( arr [ i ] % k!= 0 ) { // Checking if the arr[i] value is not divisible by k
            count ++ ; // Incrementing the count variable if the condition is true
            set [ i ] = true ; // Setting the arr[i] index in the set array to true
        } else if (! set [ i ] ) { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
            count ++ ; // Incrementing the count variable if the condition is true
            set [ i ] = true ; // Setting the arr[i] index in the set array to true
        }
    }

    printf ( "%d", count ) ; // Printing the count value to the standard output stream

    return 0 ; // Returning 0 to indicate successful program execution
}

int cmpfunc ( const void * a, const void * b ) { // Defining a comparison function cmpfunc to compare two long integer values
    if ( *( long * ) a < *( long * ) b ) { // Checking if the first long integer value is less than the second long integer value
        return -1 ; // Returning -1 if the condition is true
    } else if ( *( long * ) a > *( long * ) b ) { // Checking if the first long integer value is greater than the second long integer value
        return 1 ; // Returning 1 if the condition is true
    } else { // If the first long integer value is equal to the second long integer value
        return 0 ; // Returning 0
    }
}

These comments should provide a clear understanding of the code's functionality and logic.