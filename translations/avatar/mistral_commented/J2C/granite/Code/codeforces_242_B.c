

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000
#define INF 100000005

int main ( void ) {
    int n ;
    int a [ MAX_SIZE ] ;
    int b [ MAX_SIZE ] ;
    int left = INF ;
    int right = 0 ;
    int i ;

    // Reading the number of elements in the arrays
    scanf ( "%d", & n ) ;

    // Reading the elements of the arrays and updating the minimum and maximum elements
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", & a [ i ] ) ;
        scanf ( "%d", & b [ i ] ) ;
        left = ( left < a [ i ] )? left : a [ i ] ;
        right = ( right > b [ i ] )? right : b [ i ] ;
    }

    // Checking if there is an element that has the same minimum and maximum value in both arrays
    for ( i = 0 ; i < n ; i ++ ) {
        if ( left == a [ i ] && right == b [ i ] ) {  // Checking if the current element in both arrays has the same minimum and maximum value
            printf ( "%d\n", i + 1 ) ;  // If true, printing the index of the element
            return 0 ;  // Exiting the program after finding the element
        }
    }

    // If no such element is found, printing -1
    printf ( "-1\n" ) ;

    return 0 ;
}

