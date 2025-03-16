

#include <stdio.h>

int main ( void ) {
    int n, k, x = 0 ;  // Declare and initialize variables n, k, and x
    scanf ( "%d %d", &n, &k ) ;  // Read input for n and k
    if ( k <= ( n * n ) / 2 || k <= ( n * n ) - ( ( n * n ) / 2 ) ) {  // Check if k is within the feasible range
        printf ( "YES\n" ) ;  // Print 'YES' if k is feasible
        for ( int i = 0 ; i < n ; i ++ ) {  // Loop through each row
            for ( int j = 0 ; j < n ; j ++ ) {  // Loop through each column
                if ( i % 2 == j % 2 && x < k ) {  // Check if the cell should be 'L'
                    printf ( "L" ) ;  // Print 'L'
                    x ++ ;  // Increment x
                } else printf ( "S" ) ;  // Print 'S' otherwise
            }
            printf ( "\n" ) ;  // Move to the next line after each row
        }
    } else printf ( "NO\n" ) ;  // Print 'NO' if k is not feasible
    return 0 ;
}
