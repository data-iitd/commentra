

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    // Read input: n is the number of elements

    int * l = ( int * ) malloc ( n * sizeof ( int ) );
    // Allocate memory for the list l

    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", l + i );
        // Read input: l is the list of integers
    }

    qsort ( l, n, sizeof ( int ), cmp );
    // Sort the list l to prepare for binary search operations

    int ans = 0;
    // Initialize the answer variable to store the count of valid triangles

    for ( int i = 0 ; i < n ; i ++ ) {
        // Outer loop: iterate over each element in l
        for ( int j = i + 1 ; j < n ; j ++ ) {
            // Inner loop: iterate over each element in l starting from i+1
            int a = l [ i ];
            int b = l [ j ];
            // a and b are the sides of the triangle being considered

            int right = bsearch_left ( l, a + b );
            // Find the leftmost index where a + b can be inserted to maintain sorted order

            int left = bsearch_right ( l, max ( a - b, b - a ) );
            // Find the rightmost index where max(a - b, b - a) can be inserted to maintain sorted order

            int tmp = max ( 0, right - left );
            // Calculate the number of valid elements that can form a triangle

            if ( left <= i && i < right ) {
                tmp --;
            }
            // Adjust for overcounting if i is within the valid range

            if ( left <= j && j < right ) {
                tmp --;
            }
            // Adjust for overcounting if j is within the valid range

            ans += tmp;
            // Add the valid triangle count for the current pair to the total answer
        }
    }

    printf ( "%d\n", ans / 3 );
    // Print the final answer, dividing by 3 as implied by the context

    free ( l );
    // Free the memory allocated for the list l

    return 0;
}

