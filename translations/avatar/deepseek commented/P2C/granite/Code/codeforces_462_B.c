

#include <stdio.h>
#include <string.h>

int main ( ) {
    int n, k ;
    scanf ( "%d %d", & n, & k ) ;
    // Read the values of n and k from input

    char s [ 100001 ] ;
    scanf ( "%s", s ) ;
    // Read the string s from input

    int count [ 26 ] = { 0 } ;
    // Initialize a list `count` with 26 zeros to count occurrences of each letter

    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) {
        count [ s [ i ] - 'A' ] ++ ;
    }
    // Iterate over each character in the string `s`, calculate its index in the `count` list, and increment the corresponding count

    qsort ( count, 26, sizeof ( int ), cmpfunc ) ;
    // Sort the `count` list in descending order

    int res = 0 ;
    // Initialize `res` to 0, which will be used to store the result

    for ( int i = 0 ; i < 26 ; i ++ ) {
        if ( count [ i ] >= k ) {
            res += k * k ;
            printf ( "%d\n", res ) ;
            return 0 ;
        }
        // If the current count is greater than or equal to `k`, calculate the result using the formula `k * k` and print it, then return from the function

        k -= count [ i ] ;
        res += count [ i ] * count [ i ] ;
    }
    // If the current count is less than `k`, subtract the current count from `k` and add the square of the current count to `res`

    printf ( "%d\n", res ) ;
    // Print the final result `res`

    return 0 ;
}
// End of code

