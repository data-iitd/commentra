

#include <stdio.h>

int main ( ) {
    int n, m, r, c, i;
    scanf ( "%d %d", &n, &m );
    // Read the values of n and m from standard input

    int b [ 2 * n ];
    for ( i = 0 ; i < 2 * n ; i ++ ) b [ i ] = 1;
    // Initialize a list `b` with 1s, size is 2*n

    b [ 0 ] = b [ n - 1 ] = b [ n ] = b [ 2 * n - 1 ] = 0;
    // Set specific positions in `b` to 0

    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d %d", &r, &c );
        // Read each pair of row and column indices
        b [ r - 1 ] = b [ n + c - 1 ] = 0;
        // Update `b` based on the input pairs
    }

    if ( n % 2 && b [ n / 2 ] && b [ n + n / 2 ] ) b [ n / 2 ] = 0;
    // Check if `n` is odd and specific positions in `b` are 1, then set them to 0

    int sum = 0;
    for ( i = 0 ; i < 2 * n ; i ++ ) sum += b [ i ];
    // Calculate the sum of the list `b`

    printf ( "%d", sum );
    // Print the sum of the list `b`

    return 0;
}
// Translate the above Python code to C and end with comment "