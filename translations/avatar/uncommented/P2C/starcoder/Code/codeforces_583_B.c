#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, j, counter, counter_turns, current_level;
    scanf ( "%d", &n );
    int *a = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &a [ i ] );
    }
    current_level = 0;
    counter = 0;
    counter_turns = - 1;
    while ( counter < n ) {
        counter_turns += 1;
        for ( i = 0; i < n; i++ ) {
            if ( a [ i ]!= - 1 && a [ i ] <= counter ) {
                counter += 1;
                a [ i ] = - 1;
            }
        }
        for ( i = 0; i < n; i++ ) {
            if ( a [ i ]!= - 1 ) {
                a [ i ] = - 1;
            }
        }
    }
    printf ( "%d", counter_turns );
    return 0;
}
