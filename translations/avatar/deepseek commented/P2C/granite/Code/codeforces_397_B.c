

#include <stdio.h>

int main ( ) {
    int t;
    scanf ( "%d", &t );  // Read the number of test cases
    for ( int i = 0; i < t; i ++ ) {
        int a, b, k;
        scanf ( "%d %d %d", &a, &b, &k );  // Read each query and store it in the variables a, b, and k
        if ( k * b >= a ) {
            printf ( "Yes\n" );  // Print "Yes" if the condition is met
        }
        else {
            printf ( "No\n" );  // Print "No" if the condition is not met
        }
    }
    return 0;
}

