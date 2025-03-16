

#include <stdio.h>

int main ( void ) {
    int a, b, hole = 1, i = 0, check = 1;
    // Initializing `hole` to 1, `i` to 0, and `check` to 1.
    scanf ( "%d %d", &a, &b );
    // Taking two integer inputs, `a` and `b`.
    while ( check ) {
        // The `while` loop runs as long as `check` is 1.
        if ( hole >= b ) {
            // Checking if `hole` is greater than or equal to `b`.
            check = 0;
            // If so, set `check` to 0 to exit the loop.
        } else {
            hole = a * ( i + 1 ) - i;
            // If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
            i += 1;
            // Increment `i` by 1.
        }
    }
    printf ( "%d", i );
    // Finally, print the value of `i` after the loop exits.

    return 0;
}
// 