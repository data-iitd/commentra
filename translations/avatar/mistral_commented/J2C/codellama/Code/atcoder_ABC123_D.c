
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int x [ 3 ] ; // Declaring and initializing an integer array x of size 3
    int max = 0 ; // Initializing max to 0

    // Reading the size of the array x from the standard input stream
    for ( int i = 0 ; i < 3 ; ++ i ) {
        scanf ( "%d" , &x [ i ] ) ; // Reading the i-th element of the array x from the standard input stream
        max = max < x [ i ] ? x [ i ] : max ; // Finding the maximum element of the array x
    }

    int k ; // Declaring and initializing an integer k
    scanf ( "%d" , &k ) ; // Reading the integer k from the standard input stream

    long a [ 3 ] [ x [ 0 ] ] ; // Declaring and initializing a 2D array a of size 3x[0]

    // Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = 0 ; j < x [ i ] ; ++ j ) {
            scanf ( "%ld" , &a [ i ] [ j ] ) ; // Reading the (x[i]-j)-th element of the sub-list a[i] from the standard input stream
        }
        qsort ( a [ i ] , x [ i ] , sizeof ( long ) , cmp ) ; // Sorting the sub-list a[i] in ascending order
    }

    long ans [ k ] ; // Declaring and initializing an array ans of size k

    // Finding all such sums and adding them to the array ans
    for ( int i = 0 ; i < x [ 0 ] ; ++ i ) {
        for ( int j = 0 ; j < x [ 1 ] ; ++ j ) {
            for ( int m = 0 ; m < x [ 2 ] ; ++ m ) {
                if ( ( i + 1 ) * ( j + 1 ) * ( m + 1 ) <= k ) { // Checking if the product of (i+1), (j+1), and (m+1) is less than or equal to k
                    long tmp = a [ 0 ] [ x [ 0 ] - i - 1 ] // Getting the (x[0]-i)-th element of the sub-list a[0]
                            + a [ 1 ] [ x [ 1 ] - j - 1 ] // Getting the (x[1]-j)-th element of the sub-list a[1]
                            + a [ 2 ] [ x [ 2 ] - m - 1 ] ; // Getting the (x[2]-m)-th element of the sub-list a[2]
                    ans [ k - ( i + 1 ) * ( j + 1 ) * ( m + 1 ) - 1 ] = tmp ; // Adding the sum of the three elements to the array ans
                }
            }
        }
    }

    // Printing the i-th element of the array ans, where i is the index of the element to be printed, starting from the last one
    for ( int i = 0 ; i < k ; ++ i ) {
        printf ( "%ld\n" , ans [ i ] ) ;
    }

    return 0 ;
}

int cmp ( const void * a , const void * b ) {
    return ( * ( long * ) a - * ( long * ) b ) ;
}

