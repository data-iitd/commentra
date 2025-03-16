#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    long mod = 1e9 + 7 ; // Assigning the value of 1e9 + 7 to a long variable named mod
    int n, k ; // Declaring two integer variables named n and k
    scanf ( "%d %d", &n, &k ) ; // Reading the first two integer inputs and assigning them to the variables n and k

    int l = 1 ; // Initializing the variable l to 1
    int q = 0 ; // Initializing the variable q to 0
    while ( l <= n ) { // Starting a while loop that runs as long as l is less than or equal to n
        int r = n / ( n / l ) ; // Calculating the right end of the current subsequence
        q ++ ; // Incrementing the variable q to consider the next subsequence
        l = r + 1 ; // Incrementing the variable l to consider the next subsequence
    }

    long * dp = ( long * ) malloc ( k * ( q + 1 ) * sizeof ( long ) ) ; // Creating an array named dp of size k * (q + 1) to store the dynamic programming results

    for ( int j = 1 ; j <= q ; j ++ ) { // Starting a for loop that runs from 1 to q
        dp [ j ] = j + dp [ j - 1 ] ; // Calculating the dp value for the current subsequence length using the previous dp value and the length of the current subsequence
    }

    for ( int i = 1 ; i < k ; i ++ ) { // Starting a nested for loop that runs from 1 to k - 1 for the number of overlapping subsequences
        for ( int j = 1 ; j <= q ; j ++ ) { // Starting an inner for loop that runs from 1 to q for the length of the current subsequence
            dp [ i * ( q + 1 ) + j ] = dp [ i * ( q + 1 ) + j - 1 ] + dp [ ( i - 1 ) * ( q + 1 ) + q - j + 1 ] * j ; // Calculating the dp value for the current combination of subsequence length and number of overlapping subsequences using the dp values of the previous combinations and the length of the current subsequence
            dp [ i * ( q + 1 ) + j ] %= mod ; // Taking the modulo of the dp value to ensure it doesn't exceed the value of mod
        }
    }

    printf ( "%ld\n", dp [ k * ( q + 1 ) - 1 ] ) ; // Printing the final result, which is the dp value for the combination of subsequence length and number of overlapping subsequences that matches the given input
    free ( dp ) ; // Freeing the memory allocated to the array dp
    return 0 ; // Returning 0 to indicate that the program executed successfully
}

