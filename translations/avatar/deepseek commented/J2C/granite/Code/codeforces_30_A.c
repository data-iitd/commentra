

#include <stdio.h>
#include <math.h>

int main ( void ) {
    // Step 1: Reading Input Values
    int A, B, n;
    scanf ( "%d %d %d", &A, &B, &n );

    // Step 2: Handling Special Case A == 0
    if ( A == 0 ) {
        if ( B == 0 )
            printf ( "1\n" ) ; 
        else
            printf ( "No solution\n" ) ; 
        return 0 ; 
    }

    // Step 3: Checking Divisibility
    if ( B % A!= 0 ) {
        printf ( "No solution\n" ) ; 
        return 0 ; 
    }

    // Step 4: Normalizing B
    B /= A ; 
    int neg = B < 0 ; 
    if ( neg && n % 2 == 0 ) {
        printf ( "No solution\n" ) ; 
        return 0 ; 
    } 
    if ( neg )
        B = - B ;

    // Step 5: Iterating to Find Solution
    for ( int x = 0 ; x <= B ; x ++ ) {
        if ( pow ( x, n ) == B ) {
            printf ( "%d\n", neg? - x : x ) ; 
            return 0 ; 
        }
    }

    // Step 6: No Solution Found
    printf ( "No solution\n" ) ; 
    return 0 ; 
}
